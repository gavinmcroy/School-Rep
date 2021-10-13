//
// Created by Gavin Taylor Mcroy on 10/10/21.
//
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"
#include "mythreads.h"

struct Node *head = NULL;
int nextID = 0;

struct Node *push(ucontext_t context) {
    Node *node = createNode(context);
    Node *last = NULL;
    Node *increment = head;

    if (!increment) {
        head = node;
        return node;
    }
    while (increment) {
        last = increment;
        increment = increment->nextNode;
    }

    last->nextNode = node;
    return node;
}

struct Node *createNode(ucontext_t context) {
    Node *node = malloc(sizeof(struct Node));

    node->status = THREAD_READY;
    node->conditionNumber = THREAD_ERROR;
    node->queuePosition = THREAD_ERROR;
    node->threadContext = context;
    node->lockNumber = THREAD_ERROR;
    node->nextNode = NULL;
    node->threadID = nextID;
    nextID++;

    return node;
}


int addNode(ucontext_t threadContext) {
    return push(threadContext)->threadID;
}

int deleteNode(int threadID) {
    Node *node = head;
    Node *lastNode = NULL;

    /* Delete the stack for the non main thread */
    if (threadID != MAIN_THREAD) {
        free((char *) getNode(threadID)->threadContext.uc_stack.ss_sp);
    }
    if (head->threadID == threadID) {
        head = head->nextNode;
        return threadID;
    } else {
        while (node) {
            if (node->threadID == threadID) {
                lastNode->nextNode = node->nextNode;
                return threadID;
            }
            lastNode = node;
            node = node->nextNode;
        }
    }
    return THREAD_ERROR;
}

void rotateStructure() {
    /* If either are NULL */
    if (!head || !head->nextNode) {
        return;
    }

    struct Node *endNode = head;
    while (endNode) {
        if (endNode->nextNode == NULL) {
            break;
        }
        endNode = endNode->nextNode;
    }
    endNode->nextNode = head;
    head = head->nextNode;
    endNode->nextNode->nextNode = NULL;
}

struct Node *getNode(int threadID) {
    Node *node = head;
    while (node) {
        if (node->threadID == threadID)
            return node;
        node = node->nextNode;
    }
    return NULL;
}

struct Node *getHead() {
    return head;
}

void exitNode(int threadID) {
    Node *node = getNode(threadID);

    /* Free stack for non main thread */
    if (threadID != MAIN_THREAD && node->status != THREAD_EXIT) {
        free((char *) node->threadContext.uc_stack.ss_sp);
    }

    node->lockNumber = THREAD_ERROR;
    node->conditionNumber = THREAD_ERROR;
    node->status = THREAD_EXIT;
    node->queuePosition = THREAD_ERROR;
}

struct Node *nextThread(int currentID, int waitingFor) {
    Node *node = head;
    Node *currentNode = getNode(currentID);
    Node *waitingForNode = getNode(waitingFor);

    int i = 0;
    if (currentNode->status == THREAD_WAITING && waitingForNode->status == THREAD_FINISHED) {
        currentNode->status = THREAD_RUNNING;
        node = waitingForNode;
        waitingFor = THREAD_ERROR;
    } else {
        while (node) {
            if ((node->status == THREAD_READY) ||
                (node->status == THREAD_WAITING && node->threadID != currentID)) {
                break;
            } else {
                i++;
            }
            node = node->nextNode;
        }
    }
    for (int trash = 0; i >= 0; i--) {
        rotateStructure();
    }
    return node;
}