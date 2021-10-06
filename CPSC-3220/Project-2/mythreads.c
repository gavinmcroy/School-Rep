//
// Created by Gavin Taylor Mcroy on 9/28/21.
//
#include <stdio.h>
#include "mythreads.h"

extern void threadInit() {

}

extern int threadCreate(thFuncPtr funcPtr, void *argPtr) {
    return -1;
}

extern void threadYield() {

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

