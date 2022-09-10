#include <stdlib.h>
#include <iostream>
#include "linkedlist.h"

using namespace std;

NodePtr head = NULL;
NodePtr tail = NULL;


bool isEmpty() {
    return (head == NULL);
}

NodePtr makeNewNode(int number) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = number;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtFront(const NodePtr newPtr) {
    if (isEmpty()) {
        head = newPtr;
        tail = newPtr;
    } else { // not empty
        newPtr->next = head;
        head = newPtr;
    }

}

void insertAtEnd(const NodePtr newPtr) {
    if (isEmpty()) {
        head = newPtr;
        tail = newPtr;
    } else {
        NodePtr tmp = tail;
        newPtr->prev = tail;
        tail->next = newPtr;
        tail = newPtr;
        //---TODO
    }
}

//void insertStrategic(const Nodeptr newPtr){
//
//}

void deleteFromFront() {
    if (isEmpty()) {
        return;
    }
    NodePtr tmp = head;
    head = head->next;
    delete (tmp);
    //---TODO
}

void deleteFromEnd() {
    if (isEmpty()) {
        return;
    }
    NodePtr nodeToDel = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete nodeToDel;
    //---TODO
}

void printList() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    } else {
        NodePtr temp = head;
        while (temp != NULL) {
            cout << " The data is: " << temp->data << endl;
            temp = temp->next;
        }
    }
}

