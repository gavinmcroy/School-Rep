#define _XOPEN_SOURCE
//
// Created by Gavin Taylor Mcroy on 10/10/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "mythreads.h"
#include "helper.h"

__attribute__((unused)) int interruptsAreDisabled = 0;

__attribute__((unused)) int waitingFor = 0;

ucontext_t main_context;

int currentID = 0;

static void interruptDisable();

static void interruptEnable();

int conditionalVariable[NUM_LOCKS][CONDITIONS_PER_LOCK];

int locks[NUM_LOCKS];

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
    const int NUM_ARGS = 2;

    interruptDisable();
    ucontext_t targetContext;
    getcontext(&targetContext);

    targetContext.uc_stack.ss_sp = malloc(STACK_SIZE);
    targetContext.uc_stack.ss_size = STACK_SIZE;
    targetContext.uc_stack.ss_flags = 0;

    makecontext(&targetContext, (void (*)(void)) wrapper, NUM_ARGS, funcPtr, argPtr);

    int targetID = addNode(targetContext);
    switchThreadsStatus(currentID, targetID);

    interruptEnable();
    return targetID;
}

void threadJoin(int threadID, void **result) {
    interruptDisable();
    struct Node *node = getNode(threadID);

    if (!node) {
        interruptEnable();
        return;
    } else {
        while (node->status != THREAD_EXIT && node->status != THREAD_FINISHED) {
            getNode(currentID)->status = THREAD_WAITING;
            waitingFor = threadID;
            interruptEnable();
            threadYield();
            interruptDisable();
        }

        if (result) {
            *result = node->threadResult;
        }

        exitNode(threadID);
    }

    interruptEnable();
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

void threadExit(void *result) {
    interruptDisable();
    if (currentID == MAIN_THREAD) {
        struct Node *node = getHead(), *temp;

        while (node) {
            temp = node->nextNode;
            if (node->threadID != MAIN_THREAD) deleteNode(node->threadID);
            node = temp;
        }
        exit(MAIN_THREAD);
    }
    getNode(currentID)->threadResult = result;
    getNode(currentID)->status = THREAD_FINISHED;

    interruptEnable();
    threadYield();
}

void switchThreadsStatus(int threadToChange, int changedToo) {
    if (threadToChange == changedToo) {
        return;
    }

    struct Node *currentNode = getNode(threadToChange);
    struct Node *newNode = getNode(changedToo);

    ucontext_t *newContext;
    ucontext_t *currentContext;
    newContext = &(newNode->threadContext);
    currentContext = &(currentNode->threadContext);

    if (currentNode->status == THREAD_RUNNING) {
        currentNode->status = THREAD_READY;
    }
    currentID = changedToo;
    newNode->status = THREAD_RUNNING;

    getcontext(currentContext);
    swapcontext(currentContext, newContext);

    if (newNode->status == THREAD_RUNNING) {
        newNode->status = THREAD_READY;
    }
    if (currentNode->status == THREAD_READY) {
        currentNode->status = THREAD_RUNNING;
    }
    currentID = threadToChange;
}

//------------------------
void threadLock(int lockNum) {
    interruptDisable();
    while (locks[lockNum] == THREAD_LOCKED) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }
    locks[lockNum] = THREAD_LOCKED;
    interruptEnable();
}

void threadUnlock(int lockNum) {
    interruptDisable();
    locks[lockNum] = THREAD_UNLOCKED;
    interruptEnable();
}

void threadWait(int lockNum, int conditionNum) {
    interruptDisable();
    if (locks[lockNum] != THREAD_LOCKED) {
        fprintf(stderr, "ERROR: ThreadWait called with no lock in possesion..");
        exit(THREAD_ERROR);
    }

    struct Node *node = getNode(currentID);
    node->lockNumber = lockNum;
    node->conditionNumber = conditionNum;
    conditionalVariable[lockNum][conditionNum]++;
    node->queuePosition = conditionalVariable[lockNum][conditionNum];

    locks[lockNum] = THREAD_UNLOCKED;
    while (node->queuePosition > MAIN_THREAD) {
        interruptEnable();
        threadYield();
        interruptDisable();
    }
    node->conditionNumber = THREAD_ERROR;
    node->lockNumber = THREAD_ERROR;
    node->queuePosition = THREAD_ERROR;
    interruptEnable();
    threadLock(lockNum);
}

void threadSignal(int lockNum, int conditionNum) {
    interruptDisable();
    if (conditionalVariable[lockNum][conditionNum] == 0) {
        interruptEnable();
        return;
    }
    conditionalVariable[lockNum][conditionNum]--;
    struct Node *node = getHead();
    while (node != NULL) {
        if (node->lockNumber == lockNum && node->conditionNumber == conditionNum)
            node->queuePosition--;
        node = node->nextNode;
    }
    interruptEnable();
}