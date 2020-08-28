#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

Intset::Intset() {
    headNode = nullptr;
}

Intset::Node::Node(int val, Intset::Node *next) {
    this->val = val;
    this->nextNode = next;
}

Intset::~Intset() {
    Node *tmp = headNode;
    Node *test = headNode;
    while (tmp != nullptr) {
        tmp = tmp->nextNode;
        delete test;
        test = tmp;
    }
    headNode = nullptr;
    print();
}

/* Return true if key is in the set */
bool Intset::find(int key) {
    Node *tmp = headNode;
    while (true) {
        if (tmp == nullptr) {
            return false;
        }
        if (tmp->val == key) {
            return true;
        }
        tmp = tmp->nextNode;
    }
}


/* Inserts a new key in order.  It is an error if key is already in the set. */
void Intset::insert(int key) {
    assert (!find(key));
    /* If list is empty */
    if (headNode == nullptr) {
        Node *element = new Node(key, nullptr);
        headNode = element;
    }/* If element value is lower than current headNodes value */
    else if (headNode->val > key) {
        Node *element = new Node(key, headNode);
        headNode = element;
    }  /* If element value is higher than headNodes value */
    else {
        Node *currentStep = headNode;
        Node *stepBehind = headNode;
        while (true) {
            if (currentStep->nextNode == nullptr) {
                Node *element = new Node(key, nullptr);
                currentStep->nextNode = element;
                break;
            }
            if (stepBehind->val < key && currentStep->val > key) {
                Node *element = new Node(key, currentStep);
                stepBehind->nextNode = element;
                break;
            }
            stepBehind = currentStep;
            currentStep = currentStep->nextNode;
        }
    }
}

/* Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key) {
    assert (find(key));
    Node *currentStep = headNode;
    Node *stepBehind = headNode;
    while (true) {
        /* Checks headnode first since its a special case */
        if (headNode->val == key) {
            headNode = headNode->nextNode;
            delete currentStep;
            break;
        }
            /* Checks all elements after headnode */
        else if (currentStep->val == key) {
            stepBehind->nextNode = currentStep->nextNode;
            delete currentStep;
            break;
        }
        stepBehind = currentStep;
        currentStep = currentStep->nextNode;
    }
}

void Intset::print(void) {
    Node *tmp = headNode;
    if (tmp == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (true) {
        std::cout << tmp->val << std::endl;
        if (tmp->nextNode == nullptr) {
            break;
        }
        tmp = tmp->nextNode;
    }
}

