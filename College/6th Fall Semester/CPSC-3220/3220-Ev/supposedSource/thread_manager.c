#define RUNNABLE 0
#define DONE 3
#define RUNNING 1
#define INVALID -1
#define LOCKED 1
#define WAITING 2
#define UNLOCKED 0
#define EXITED 4

#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "mythreads.h"

int interruptsAreDisabled = 0;
ucontext_t main_context;
int currentID;
int waitingFor;

void *linker(thFuncPtr funcPtr, void *argPtr);
void switchThread(int fromID, int toID);
struct Node *pickThread();

//INDIVIDUAL THREADS
struct Node
{
  int id;
  int status; 
  ucontext_t context;
  void *result;

  int lockNum;
  int condNum;
  int queuePos;

  struct Node *next;
};

//FUNCTIONS FOR MANAGING THREAD LISTS WITH PRIORITY
struct Node *newNode(ucontext_t context);
int pushNode(ucontext_t context);
int removeNode(int id);
void exitNode(int id);
void rotate();
struct Node* getNode(int id);

int nextid;
struct Node* head;

static void interruptDisable();
static void interruptEnable();
int lockStates[NUM_LOCKS]; 
// next position on the conditional variable "queue"
int condVars[NUM_LOCKS][CONDITIONS_PER_LOCK];

void threadInit()
{
  interruptDisable();

  nextid = 0;
  head = NULL;
  waitingFor = INVALID;

  getcontext(&main_context);
  main_context.uc_stack.ss_size = STACK_SIZE;
  main_context.uc_stack.ss_flags = 0;
  currentID = pushNode(main_context);
  getNode(currentID)->status = RUNNING;

  int iter, jter;
  for (iter = 0; iter < NUM_LOCKS; iter++)
  {
    lockStates[iter] = UNLOCKED;
    for (jter = 0; jter < CONDITIONS_PER_LOCK; jter++)
      condVars[iter][jter] = 0;
  }

  interruptEnable();
}


int threadCreate(thFuncPtr funcPtr, void *argPtr)
{
  interruptDisable();
  ucontext_t targetcontext;
  getcontext(&targetcontext);
  targetcontext.uc_stack.ss_sp = malloc(STACK_SIZE);
	targetcontext.uc_stack.ss_size = STACK_SIZE;
  targetcontext.uc_stack.ss_flags = 0;

  makecontext(&targetcontext, (void (*) (void))linker, 2, funcPtr, argPtr);

  int targetID = pushNode(targetcontext);
  switchThread(currentID, targetID);

  interruptEnable();
  return targetID;
}

void threadYield()
{
  interruptDisable();

  struct Node* targetNode = pickThread();
  if (targetNode == NULL) {
    interruptEnable();
    return;
  }

  struct Node *mynode = getNode(currentID);
  switchThread(mynode->id, targetNode->id);
  interruptEnable();
}

void threadJoin(int thread_id, void **result)
{
  interruptDisable();
  struct Node *node = getNode(thread_id);
  if (node == NULL) {
    interruptEnable();
    return;
  }
  else {
    while (node->status != DONE && node->status != EXITED) {
      getNode(currentID)->status = WAITING;
      waitingFor = thread_id;
      interruptEnable();
      threadYield();
      interruptDisable();
    }
    if (result != NULL)
      *result = node->result;

    exitNode(thread_id);
  }
  interruptEnable();
}

void threadExit(void *result)
{
  interruptDisable();
  if (currentID == 0)
  {
    struct Node *node = head, *temp;
    while (node != NULL)
    {
      temp = node->next;
      if (node->id != 0) removeNode(node->id);
      node = temp;
    }
    exit(0);
  }
  getNode(currentID)->status = DONE;
  getNode(currentID)->result = result;
  interruptEnable();
  threadYield();
}

void threadLock(int lockNum)
{
  interruptDisable();
  while (lockStates[lockNum] == LOCKED) {
    interruptEnable();
    threadYield();
    interruptDisable();
  }
  lockStates[lockNum] = LOCKED;
  interruptEnable();
}

void threadUnlock(int lockNum)
{
  interruptDisable();
  lockStates[lockNum] = UNLOCKED;
  interruptEnable();
}

void threadWait(int lockNum, int conditionNum)
{
  interruptDisable();
  if (lockStates[lockNum] != LOCKED) {
    fprintf(stderr, "ERROR: ThreadWait called with no lock in possesion..");
    exit(INVALID);
  }

  struct Node *node = getNode(currentID);
  node->lockNum = lockNum;
  node->condNum = conditionNum;
  condVars[lockNum][conditionNum]++;
  node->queuePos = condVars[lockNum][conditionNum];

  lockStates[lockNum] = UNLOCKED;
  while (node->queuePos > 0) {
    interruptEnable();
    threadYield();
    interruptDisable();
  }
  node->condNum = INVALID;
  node->lockNum = INVALID;
  node->queuePos = INVALID;
  interruptEnable();
  threadLock(lockNum);
}

void threadSignal(int lockNum, int conditionNum)
{
  interruptDisable();
  if (condVars[lockNum][conditionNum] == 0) {
    interruptEnable();
    return;
  }
  condVars[lockNum][conditionNum]--;
  struct Node *node = head;
  while (node != NULL)
  {
    if (node->lockNum == lockNum && node->condNum == conditionNum)
      node->queuePos--;
    node = node->next;
  }
  interruptEnable();
}

void *linker(thFuncPtr funcPtr, void *argPtr)
{
  interruptEnable();
  void *result = (void *)funcPtr(argPtr);
  threadExit(result);
  return result;
}

void switchThread(int fromID, int toID)
{
  if (fromID == toID) return;

  struct Node *fromNode = getNode(fromID);
  struct Node *toNode = getNode(toID);

  ucontext_t *fromcontext, *tocontext;
  fromcontext = &(fromNode->context);
  tocontext = &(toNode->context);

  if (fromNode->status == RUNNING)
    fromNode->status = RUNNABLE;
  currentID = toID;
  toNode->status = RUNNING;

  getcontext(fromcontext);
  swapcontext(fromcontext, tocontext);

  if (toNode->status == RUNNING)
    toNode->status = RUNNABLE;
  if (fromNode->status == RUNNABLE)
    fromNode->status = RUNNING;
  currentID = fromID;
}

struct Node *pickThread()
{
  struct Node *node = head;
  struct Node *currentNode = getNode(currentID),
    *waitingForNode = getNode(waitingFor);

  int index = 0;
  if (currentNode->status == WAITING && waitingForNode->status == DONE) {
    currentNode->status = RUNNING;
    node = waitingForNode;
    waitingFor = INVALID;
  } else {
    while (node != NULL)
    {
      if (node->status == RUNNABLE ||
        (node->status == WAITING && node->id != currentID)) break;
      else index++;
      node = node->next;
    }
  }
  for (; index >= 0; index--) rotate();
  return node;
}

struct Node *newNode(ucontext_t context)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->id = nextid;
  nextid++;
  node->lockNum = INVALID;
  node->context = context;
  node->status = RUNNABLE;
  node->queuePos = INVALID;
  node->condNum = INVALID;

  node->next = NULL;
  return node;
}

struct Node *pushFront(ucontext_t context)
{
  struct Node *node = newNode(context);
  node->next = head;
  head = node;
  return node;
}

struct Node *pushBack(ucontext_t context)
{
  struct Node *node = newNode(context);
  struct Node *last, *iter = head;
  if (iter == NULL) {
    head = node;
    return node;
  }
  while (iter != NULL)
  {
    last = iter;
    iter = iter->next;
  } last->next = node;
  return node;
}

int pushNode(ucontext_t context)
{
  return pushBack(context)->id;
}

void rotate()
{

  if (head == NULL || head->next == NULL) return;

  struct Node *tail = head;
  while (tail != NULL)
  {
    if (tail->next == NULL) break;
    tail = tail->next;
  }
  tail->next = head;
  head = head->next;
  tail->next->next = NULL;
}

int removeNode(int id)
{
  struct Node *node = head, *last = NULL;

  if (id != 0)
    free((char *)getNode(id)->context.uc_stack.ss_sp);

  if (head->id == id) {
    node = head;
    head = head->next;
    return id;
  } else {
    while (node != NULL)
    {
      if (node->id == id) {
        last->next = node->next;
        return id;
      }
      last = node;
      node = node->next;
    }
  }
  return INVALID;
}

void exitNode(int id)
{
  struct Node* node = getNode(id);

  if (node->status != EXITED && id != 0)
    free((char *)node->context.uc_stack.ss_sp);

  node->queuePos = INVALID;
  node->lockNum = INVALID;
  node->status = EXITED;
  node->condNum = INVALID;
}

struct Node* getNode(int id)
{
  struct Node *node = head;
  while (node != NULL)
  {
    if (node->id == id)
      return node;
    node = node->next;
  }
  return NULL;
}

static void interruptDisable() {
  interruptsAreDisabled = 1;
}
static void interruptEnable() {
  interruptsAreDisabled = 0;
}
