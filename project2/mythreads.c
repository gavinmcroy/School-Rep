#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "mythreads.h"
#include "helper.h"

int interruptsAreDisabled = 0;
ucontext_t main_context;
int currentID = 0;
int waitingFor = 0;
struct Node *head = NULL;

typedef struct Node {
    int threadID;
    ucontext_t threadContext;
    int status;
    void *threadResult;

    int conditionNumber;
    int queuePosition;
    int lockNumber;

    struct Node *next;
} Node;

static void interruptDisable();

static void interruptEnable();

int locks[NUM_LOCKS];
int conditionalVariable[NUM_LOCKS][CONDITIONS_PER_LOCK];

void *wrapper(thFuncPtr funcPtr, void *arg) {
    interruptEnable();
    void *result = (void *) funcPtr(arg);
    threadExit(result);
    return result;
}

static void interruptDisable() {
    interruptsAreDisabled = 1;
}

static void interruptEnable() {
    interruptsAreDisabled = 0;
}

void threadInit() {
    interruptDisable();
    currentID = 0;
    waitingFor = THREAD_ERROR;
    head = NULL;

    getcontext(&main_context);
    main_context.uc_stack.ss_size = STACK_SIZE;
    main_context.uc_stack.ss_flags = 0;

    currentID = addNode(main_context);
    getNode(currentID)->status = THREAD_RUNNING;

    for (int i = 0; i < NUM_LOCKS; i++) {
        locks[i] = THREAD_UNLOCKED;
        for (int j = 0; j < CONDITIONS_PER_LOCK; j++)
            conditionalVariable[i][j] = 0;
    }
    interruptEnable();
}


int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    interruptDisable();
    ucontext_t targetContext;
    getcontext(&targetContext);

    targetContext.uc_stack.ss_sp = malloc(STACK_SIZE);
    targetContext.uc_stack.ss_size = STACK_SIZE;
    targetContext.uc_stack.ss_flags = 0;

    makecontext(&targetContext, (void (*)(void)) wrapper, 2, funcPtr, argPtr);

    int targetID = addNode(targetContext);
    switchThreadsStatus(currentID, targetID);

    interruptEnable();
    return targetID;
}

void threadYield() {
    interruptDisable();

    struct Node *targetNode = nextThread(0, 0);
    if (targetNode == NULL) {
        interruptEnable();
        return;
    }

    struct Node *myNode = getNode(currentID);
    switchThreadsStatus(myNode->threadID, targetNode->threadID);
    interruptEnable();
}

void threadJoin(int thread_id, void **result) {
    interruptDisable();
    struct Node *node = getNode(thread_id);
    if (node == NULL) {
        interruptEnable();
        return;
    } else {
        while (node->status != THREAD_FINISHED && node->status != THREAD_EXIT) {
            getNode(currentID)->status = THREAD_WAITING;
            waitingFor = thread_id;
            interruptEnable();
            threadYield();
            interruptDisable();
        }
        if (result != NULL)
            *result = node->threadResult;

        exitNode(thread_id);
    }
    interruptEnable();
}

void threadExit(void *result) {
    interruptDisable();
    if (currentID == 0) {
        struct Node *node = head, *temp;
        while (node != NULL) {
            temp = node->next;
            if (node->threadID != 0) removeNode(node->threadID);
            node = temp;
        }
        exit(0);
    }
    getNode(currentID)->status = THREAD_FINISHED;
    getNode(currentID)->threadResult = result;
    interruptEnable();
    threadYield();
}

void switchThreadsStatus(int threadToChange, int changedToo) {
    if (threadToChange == changedToo) return;

    struct Node *fromNode = getNode(threadToChange);
    struct Node *toNode = getNode(changedToo);

    ucontext_t *fromcontext, *tocontext;
    fromcontext = &(fromNode->threadContext);
    tocontext = &(toNode->threadContext);

    if (fromNode->status == THREAD_RUNNING)
        fromNode->status = THREAD_READY;
    currentID = changedToo;
    toNode->status = THREAD_RUNNING;

    getcontext(fromcontext);
    swapcontext(fromcontext, tocontext);

    if (toNode->status == THREAD_RUNNING)
        toNode->status = THREAD_READY;
    if (fromNode->status == THREAD_READY)
        fromNode->status = THREAD_RUNNING;
    currentID = threadToChange;
}