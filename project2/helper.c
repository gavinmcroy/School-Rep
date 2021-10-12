//
// Created by Gavin Taylor Mcroy on 10/12/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"
#include "mythreads.h"

struct Node *head = NULL;
int nextID = 0;

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


struct Node *nextThread(int currentID, int waitingFor) {
    struct Node *node = head;
    struct Node *currentNode = getNode(currentID),
            *waitingForNode = getNode(waitingFor);

    int index = 0;
    if (currentNode->status == THREAD_WAITING && waitingForNode->status == THREAD_FINISHED) {
        currentNode->status = THREAD_RUNNING;
        node = waitingForNode;
        waitingFor = THREAD_ERROR;
    } else {
        while (node != NULL) {
            if (node->status == THREAD_READY ||
                (node->status == THREAD_WAITING && node->threadID != currentID))
                break;
            else index++;
            node = node->next;
        }
    }
    for (; index >= 0; index--) rotate();
    return node;
}

struct Node *newNode(ucontext_t context) {
    struct Node *node = malloc(sizeof(struct Node));
    node->threadID = nextID;
    nextID++;
    node->lockNumber = THREAD_ERROR;
    node->threadContext = context;
    node->status = THREAD_READY;
    node->queuePosition = THREAD_ERROR;
    node->conditionNumber = THREAD_ERROR;

    node->next = NULL;
    return node;
}

struct Node *pushBack(ucontext_t context) {
    struct Node *node = newNode(context);
    struct Node *last, *iter = head;
    if (iter == NULL) {
        head = node;
        return node;
    }
    while (iter != NULL) {
        last = iter;
        iter = iter->next;
    }
    last->next = node;
    return node;
}

int addNode(ucontext_t context) {
    return pushBack(context)->threadID;
}

void rotate() {

    if (head == NULL || head->next == NULL) return;

    struct Node *tail = head;
    while (tail != NULL) {
        if (tail->next == NULL) break;
        tail = tail->next;
    }
    tail->next = head;
    head = head->next;
    tail->next->next = NULL;
}

int removeNode(int id) {
    struct Node *node = head, *last = NULL;

    if (id != 0)
        free((char *) getNode(id)->threadContext.uc_stack.ss_sp);

    if (head->threadID == id) {
        node = head;
        head = head->next;
        return id;
    } else {
        while (node != NULL) {
            if (node->threadID == id) {
                last->next = node->next;
                return id;
            }
            last = node;
            node = node->next;
        }
    }
    return THREAD_ERROR;
}

void exitNode(int id) {
    struct Node *node = getNode(id);

    if (node->status != THREAD_EXIT && id != 0)
        free((char *) node->threadContext.uc_stack.ss_sp);

    node->queuePosition = THREAD_ERROR;
    node->lockNumber = THREAD_ERROR;
    node->status = THREAD_EXIT;
    node->conditionNumber = THREAD_ERROR;
}

struct Node *getNode(int id) {
    struct Node *node = head;
    while (node != NULL) {
        if (node->threadID == id)
            return node;
        node = node->next;
    }
    return NULL;
}