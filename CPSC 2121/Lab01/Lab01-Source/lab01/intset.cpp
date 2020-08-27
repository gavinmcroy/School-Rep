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

//TODO Implement destructor
Intset::~Intset() {
//---TODO implement
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
//---currentStep->nextNode == nullptr
/*headNode->val < key && oneStepAhead->val > key*/
/* TODO Inserts a new key in order.  It is an error if key is already in the set. */
void Intset::insert(int key) {
    assert (!find(key));
    if (headNode == nullptr) {
        Node *element = new Node(key, nullptr);
        headNode = element;
    }
    else if(headNode->val>key){
        Node *element = new Node(key,headNode);
        headNode = element;
    }
    else {
        Node *currentStep = headNode;
        //Node *stepBehind = nullptr;
        while (true) {
            if (currentStep->nextNode == nullptr) {
                Node *element = new Node(key, nullptr);
                currentStep->nextNode = element;
                break;
            }
            //stepBehind = currentStep;
           // currentStep = currentStep->nextNode;
            //break;
        }
    }
}

/* TODO Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key) {
    assert (find(key));
    Node *tmp = headNode;
    while (true) {
        if (tmp->val == key) {
            break;
        }
        tmp = tmp->nextNode;
    }

}

void Intset::print(void) {
    Node *tmp = headNode;
    while (true) {
        std::cout << tmp->val << std::endl;
        if (tmp->nextNode == nullptr) {
            break;
        }
        tmp = tmp->nextNode;
    }
    //std::cout << "SIZE: " << size << std::endl;
}

