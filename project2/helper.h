//
// Created by Gavin Taylor Mcroy on 10/12/21.
//

#ifndef PROJECT2_HELPER_H
#define PROJECT2_HELPER_H
#endif //PROJECT2_HELPER_H

#include "mythreads.h"

void *wrapper(thFuncPtr funcPtr, void *arg);

void switchThreadsStatus(int threadToChange, int changedToo);

struct Node *nextThread(int currentID, int waitingFor);

/* DATA STRUCTURE FUNCTIONS */
struct Node *newNode(ucontext_t context);

int addNode(ucontext_t context);

int removeNode(int id);

void rotate();

struct Node *getNode(int id);

void exitNode(int id);