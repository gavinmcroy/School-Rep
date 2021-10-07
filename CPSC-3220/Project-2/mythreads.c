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

extern void threadInit() {
    /* TODO Setup threadData to be a linked list */
    threadHead = NULL;
    threadTail = NULL;
//    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
//    getcontext(&main_context);
//    main_context.uc_stack.ss_sp = stack;
//    main_context.uc_stack.ss_size = STACK_SIZE;
    printf("Thread library initialized\n");
}

extern int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    Thread *thread = (Thread *) malloc(sizeof(Thread));

    /* Means linked list is empty */
    if (threadHead == NULL) {
        threadHead = thread;
        threadTail = thread;
    }

    /* Setup thread stack */
    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
    getcontext(&thread->threadContext);
    thread->threadContext.uc_stack.ss_sp = stack;
    thread->threadContext.uc_stack.ss_size = STACK_SIZE;
    /* Basic thread initialization */
    thread->isFinished = false;
    thread->isRunning = false;
    thread->isWaiting = false;
    thread->isReady = true;

    /* TODO Thread ID may need to change */
    thread->threadID = threadUniqueIdentifier;

    threadUniqueIdentifier++;


    makecontext(&thread->threadContext,
                (void (*)()) funcPtr, 1, argPtr);

    /* Thread is supposed to begin running before function returns */
    swapcontext(&main_context, &thread->threadContext);

    /* Problem is the function never returns but ends inside what ever function called it */
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

