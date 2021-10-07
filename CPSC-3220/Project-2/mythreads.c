//
// Created by Gavin Taylor Mcroy on 9/28/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"

ucontext_t main_context;
Thread *threadHead;
Thread *threadTail;
int threadUniqueIdentifier = 0;

void *wrapper(thFuncPtr userFunction, int argc, void *args, Thread *thread) {
    void *something = NULL;
    if (args == NULL) {

    }
    printf("Wrapper function total arguments %d\n", argc);
    /* TODO this may not account for return types */
    something = userFunction(args);
    /* After execution continue back where the function was called */
    swapcontext(&thread->threadContext, &main_context);
    return something;
}

extern void threadInit() {
    /* TODO Setup threadData to be a linked list */
    threadHead = NULL;
    threadTail = NULL;
    printf("Thread library initialized\n");
}

/* Initializes thread, and sets state to ready */
extern int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    Thread *thread = (Thread *) malloc(sizeof(Thread));

    /* TODO Linked List is not built. Means linked list is empty */

    /* Setup thread stack */
    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
    getcontext(&thread->threadContext);
    thread->threadContext.uc_stack.ss_sp = stack;
    thread->threadContext.uc_stack.ss_size = STACK_SIZE;
    thread->threadContext.uc_stack.ss_flags = 0;
    /* Basic thread initialization */
    thread->isFinished = false;
    thread->isRunning = false;
    thread->isWaiting = false;
    thread->isReady = true;

    /* TODO Thread ID may need to change */
    thread->threadID = threadUniqueIdentifier;

    if (threadHead == NULL) {
        threadHead = thread;
        threadTail = thread;
    } else {
        threadTail->nextThread = thread;
        threadTail = thread;
        thread->nextThread = NULL;
    }
    for (Thread *thread1 = threadHead; thread1 != NULL; thread1 = thread1->nextThread) {
        printf("ID: %d\n", thread1->threadID);
    }


    /* We need to wrap the desired function call, so that we can gather required info
    makecontext(&thread->threadContext,
             (void (*)()) funcPtr, 1, argPtr); */
    const int MAX_ARGS = 4;
    const int USER_ARGS = 1;
    makecontext(&thread->threadContext,
                (void (*)()) wrapper, MAX_ARGS, funcPtr, USER_ARGS, argPtr, &thread->threadContext);

    /* Thread is supposed to begin running before function returns */
    swapcontext(&main_context, &thread->threadContext);

    threadUniqueIdentifier++;
    return thread->threadID;
}

extern void threadYield() {
    /* Holder to loop over linked list to ensure functionality */
}

extern void threadJoin(int thread_id, void **result) {

}

//exits the current thread -- closing the main thread, will terminate the program
extern void threadExit(void *result) {

}

extern void threadLock(int lockNum) {

}

extern void threadUnlock(int lockNum) {

}

extern void threadWait(int lockNum, int conditionNum) {

}

extern void threadSignal(int lockNum, int conditionNum) {
    //interruptsAreDisabled
}

//this needs to be defined in your library. Don't forget it or some of my tests won't compile.

