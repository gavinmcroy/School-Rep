#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

Intset::Intset() {
    headNode = nullptr;
    size = 0;
}

struct Intset::Node {
    int val;
    Node *nextNode;
};

//TODO Implement destructor
Intset::~Intset() {
//---To implement
}

/* Return true if key is in the set */
bool Intset::find(int key) {
    Node *tmp = headNode;
    while (true) {
        if (tmp->val == key) {
            return true;
        }
        if (tmp->nextNode == nullptr) {
            return false;
        }
        tmp = tmp->nextNode;
    }
}


/* TODO Inserts a new key in order.  It is an error if key is already in the set. */
void Intset::insert(int key) {
    assert (!find(key));
    if (headNode == nullptr) {
        Node *element = new Node;
        element->val = key;
        headNode = element;
        headNode->nextNode = nullptr;
        size++;
    } else {
        Node *tmp = headNode;
        while (true) {
            if (tmp->nextNode == nullptr) {
                Node *element = new Node;
                element->val = key;
                tmp->nextNode = element;
                element->nextNode = nullptr;
                break;
            }
            tmp = tmp->nextNode;
        }
        size++;
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
    std::cout << "SIZE: " << size << std::endl;
}
