//
// Created by Gavin Taylor Mcroy on 9/28/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"

ucontext_t main_context;
//Thread mainContext;
Thread *runningThread;
Thread *threadHead;
Thread *threadTail;
int threadUniqueIdentifier = 0;
extern int interruptsAreDisabled = 0;

void *wrapper(thFuncPtr userFunction, int argc, void *args, Thread *thread) {
    void *something = NULL;

    /* TODO this may not account for return types */
    something = userFunction(args);
    /* Function has been completed, needs to be caught by join */

    interruptsAreDisabled = 1;
    swapcontext(&thread->threadContext, &main_context);
    thread->isRunning = false;
    thread->isWaiting = true;
    interruptsAreDisabled = 0;

    return something;
}

extern void threadInit() {
    threadHead = NULL;
    threadTail = NULL;
    runningThread = NULL;
    printf("Thread library initialized\n");
}

/* Initializes thread, and sets state to ready. Main thread is [0] */
extern int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    interruptsAreDisabled = 1;
    Thread *thread = threadSetup();
    interruptsAreDisabled = 0;

    /* Place newly created thread at end of list or at head if empty list */
    insertIntoList(thread);

    const int MAX_ARGS = 4;
    const int USER_ARGS = 1;
    /* Function is wrapped, so that when it finishes, context is switched back and ID returned */
    makecontext(&thread->threadContext,
                (void (*)()) wrapper, MAX_ARGS, funcPtr, USER_ARGS, argPtr, &thread->threadContext);

    /* Thread is supposed to begin running before function returns */
    interruptsAreDisabled = 1;
    runningThread = thread;
    thread->isRunning = true;
    swapcontext(&main_context, &thread->threadContext);
    interruptsAreDisabled = 0;

    return thread->threadID;
}

/* We could have a global indexer, so if theres 5 threads. we go down a list
 * Almost like round robin thread 1 runs yields, thread 2, and so fourth */
extern void threadYield() {
    /* Holder to loop over linked list to ensure functionality */
    /* What this does is runs the next thread, once next thread finishes this current thread resumes
     * then the function returns */
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


/* Helper functions for code clarity */
Thread *threadSetup() {
    Thread *thread = (Thread *) malloc(sizeof(Thread));
    /* Setup thread stack */
    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
    getcontext(&thread->threadContext);

    interruptsAreDisabled = 1;
    thread->threadContext.uc_stack.ss_sp = stack;
    thread->threadContext.uc_stack.ss_size = STACK_SIZE;
    thread->threadContext.uc_stack.ss_flags = 0;

    /* Basic thread initialization */
    thread->isFinished = false;
    thread->isWaiting = false;
    thread->isReady = false;

    /* TODO Thread ID may need to change */
    thread->threadID = threadUniqueIdentifier;
    threadUniqueIdentifier++;
    return thread;
}

void printAllThreads() {
    /* DEBUG prints all current threads set to active */
    for (Thread *thread1 = threadHead; thread1 != NULL; thread1 = thread1->nextThread) {
        printf("ID: %d\n", thread1->threadID);
    }
}

void insertIntoList(Thread * thread){
    if (threadHead == NULL) {
        threadHead = thread;
        threadTail = thread;
    } else {
        threadTail->nextThread = thread;
        threadTail = thread;
        thread->nextThread = NULL;
    }
}
