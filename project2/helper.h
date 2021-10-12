//
// Created by Gavin Taylor Mcroy on 10/10/21.
//

#ifndef PROJECT2_HELPER_H
#define PROJECT2_HELPER_H

#define _XOPEN_SOURCE

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

typedef void *(*thFuncPtr) (void *);

void *wrapper(thFuncPtr funcPtr, void *arg);

void switchThreadsStatus(int threadToChange, int changedToo);

struct Node *nextThread(int currentID, int waitingFor);

struct Node *newNode(ucontext_t context);

int addNode(ucontext_t context);

void rotate();

int removeNode(int id);

void exitNode(int id);

struct Node *getNode(int id);

struct Node *getHead();

#endif //PROJECT2_HELPER_H