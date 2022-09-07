#define _XOPEN_SOURCE 600

#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "mythreads.h"


int interruptsAreDisabled = 0;
int currentID;
int waitingFor;
ucontext_t mainContext;
int nextId;
Node *head;

int locks[NUM_LOCKS];
int conditionalVariable[NUM_LOCKS][CONDITIONS_PER_LOCK];

static void interruptDisable() {
    interruptsAreDisabled = 1;
}

static void interruptEnable() {
    interruptsAreDisabled = 0;
}

void threadInit() {
    interruptDisable();

    head = NULL;
    waitingFor = INVALID;
    nextId = 0;


    getcontext(&mainContext);
    mainContext.uc_stack.ss_size = STACK_SIZE;
    mainContext.uc_stack.ss_flags = 0;
    currentID = addNode(mainContext);
    getNode(currentID)->status = RUNNING;

    for (int i = 0; i < NUM_LOCKS; i++) {
        locks[i] = UNLOCKED;
        for (int j = 0; j < CONDITIONS_PER_LOCK; j++)
            conditionalVariable[i][j] = 0;
    }

    interruptEnable();
}

void threadJoin(int thread_id, void **result) {
    interruptDisable();
    Node *node = getNode(thread_id);
    if (!node) {
        interruptEnable();
        return;
    } else {
        while (node->status != DONE && node->status != EXITED) {
            getNode(currentID)->status = WAITING;
            waitingFor = thread_id;
            interruptEnable();
            threadYield();
            interruptDisable();
        }
        if (result) {
            *result = node->result;
        }

        closeNode(thread_id);
    }
    interruptEnable();
}

void threadYield() {
    interruptDisable();

    Node *targetNode = pickNextThread();
    if (!targetNode) {
        interruptEnable();
        return;
    }

    Node *myNode = getNode(currentID);
    switchThread(myNode->id, targetNode->id);
    interruptEnable();
}

int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    const int MAX_ARGS = 2;
    interruptDisable();
    ucontext_t targetContext;
    getcontext(&targetContext);
    targetContext.uc_stack.ss_sp = malloc(STACK_SIZE);
    targetContext.uc_stack.ss_size = STACK_SIZE;
    targetContext.uc_stack.ss_flags = 0;

    makecontext(&targetContext, (void (*)(void)) wrapper, MAX_ARGS, funcPtr, argPtr);

    int targetID = addNode(targetContext);
    switchThread(currentID, targetID);

    interruptEnable();
    return targetID;
}

void threadLock(int lockNum) {
    interruptDisable();
    while (locks[lockNum] == LOCKED) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }
    locks[lockNum] = LOCKED;
    interruptEnable();
}

void threadUnlock(int lockNum) {
    interruptDisable();
    locks[lockNum] = UNLOCKED;
    interruptEnable();
}

void threadExit(void *result) {
    interruptDisable();
    if (currentID == MAIN_THREAD) {
        Node *node = head, *temp;
        while (node) {
            temp = node->next;
            if (node->id != MAIN_THREAD) {
                deleteNode(node->id);
            }
            node = temp;
        }
        exit(MAIN_THREAD);
    }
    getNode(currentID)->status = DONE;
    getNode(currentID)->result = result;
    interruptEnable();
    threadYield();
}

void threadSignal(int lockNum, int conditionNum) {
    interruptDisable();
    if (conditionalVariable[lockNum][conditionNum] == MAIN_THREAD) {
        interruptEnable();
        return;
    }
    conditionalVariable[lockNum][conditionNum]--;
    Node *node = head;
    while (node) {
        if (node->lockNumber == lockNum && node->conditionalNumber == conditionNum) {
            node->queuePosition--;
        }
        node = node->next;
    }
    interruptEnable();
}

void threadWait(int lockNum, int conditionNum) {
    interruptDisable();
    if (locks[lockNum] != LOCKED) {
        fprintf(stderr, "ERROR: ThreadWait called with no lock in possesion..");
        exit(INVALID);
    }

    Node *node = getNode(currentID);
    node->lockNumber = lockNum;
    node->conditionalNumber = conditionNum;
    conditionalVariable[lockNum][conditionNum]++;
    node->queuePosition = conditionalVariable[lockNum][conditionNum];

    locks[lockNum] = UNLOCKED;
    while (node->queuePosition > MAIN_THREAD) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }

    node->lockNumber = INVALID;
    node->queuePosition = INVALID;
    node->conditionalNumber = INVALID;

    interruptEnable();
    threadLock(lockNum);
}

void *wrapper(thFuncPtr funcPtr, void *argPtr) {
    interruptEnable();
    void *result = (void *) funcPtr(argPtr);
    threadExit(result);
    return result;
}

Node *pickNextThread() {
    Node *node = head;
    Node *currentNode = getNode(currentID);
    Node *waitingForNode = getNode(waitingFor);

    int index = 0;
    if (currentNode->status == WAITING && waitingForNode->status == DONE) {
        currentNode->status = RUNNING;
        node = waitingForNode;
        waitingFor = INVALID;
    } else {
        while (node) {
            if (node->status == STANDBY ||
                (node->status == WAITING && node->id != currentID)) {
                break;
            } else {
                index++;
            }
            node = node->next;
        }
    }
    for (int trash; index >= 0; index--) rotate();
    return node;
}

void switchThread(int fromID, int toID) {
    if (fromID == toID) {
        return;
    }

    Node *fromNode = getNode(fromID);
    Node *toNode = getNode(toID);
    ucontext_t *fromContext = &(fromNode->context);
    ucontext_t *toContext = &(toNode->context);

    if (fromNode->status == RUNNING) {
        fromNode->status = STANDBY;
    }
    currentID = toID;
    toNode->status = RUNNING;

    getcontext(fromContext);
    swapcontext(fromContext, toContext);

    if (toNode->status == RUNNING) {
        toNode->status = STANDBY;
    }
    if (fromNode->status == STANDBY) {
        fromNode->status = RUNNING;
    }
    currentID = fromID;
}

Node *placeFront(ucontext_t context) {
    Node *node = createNode(context);
    node->next = head;
    head = node;
    return node;
}

Node *placeBack(ucontext_t context) {
    Node *node = createNode(context);
    Node *last, *iter = head;
    if (!iter) {
        head = node;
        return node;
    }
    while (iter) {
        last = iter;
        iter = iter->next;
    }
    last->next = node;
    return node;
}

int addNode(ucontext_t context) {
    return placeBack(context)->id;
}

int deleteNode(int id) {
    Node *node = head;
    Node *last = NULL;

    if (id != MAIN_THREAD) {
        free((char *) getNode(id)->context.uc_stack.ss_sp);
    }

    if (head->id == id) {
        node = head;
        head = head->next;
        return id;
    } else {
        while (node) {
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

void rotate() {

    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *tail = head;
    while (tail) {
        if (!tail->next) break;
        tail = tail->next;
    }
    tail->next = head;
    head = head->next;
    tail->next->next = NULL;
}

Node *createNode(ucontext_t context) {
    Node *node = malloc(sizeof(Node));
    node->id = nextId;
    node->status = STANDBY;
    node->queuePosition = INVALID;
    node->conditionalNumber = INVALID;
    node->lockNumber = INVALID;
    node->context = context;
    node->next = NULL;
    nextId++;
    return node;
}

Node *getNode(int id) {
    Node *node = head;
    while (node) {
        if (node->id == id) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void closeNode(int id) {
    Node *node = getNode(id);

    if (node->status != EXITED && id != MAIN_THREAD) {
        free((char *) node->context.uc_stack.ss_sp);
    }

    node->conditionalNumber = INVALID;
    node->queuePosition = INVALID;
    node->lockNumber = INVALID;
    node->status = EXITED;
}

