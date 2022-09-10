//
// Created by Gavin McRoy on 10/22/2020.
//

#include<string>
#include<iostream>
#include <assert.h>

#ifndef LAB07_CLION_HASH_H
#define LAB07_CLION_HASH_H
using namespace std;

class Hash {
private:

    struct Node {
        char key;
        Node *next;

        Node(char k, Node *n) {
            key = k;
            next = n;
        }

        Node() {
            key = ' ';
            next = nullptr;
        }
    };

    Node **table;  // array of pointers to linked lists
    int size;      // size of table, as currently allocated
    int num_elems; // number of elements stored in the table

   unsigned int myHash(char key, int tableSize);
public:
    Hash();

    ~Hash();

    bool find(char key);

    void insert(char key);

    void remove(char key);

    void print();


};


#endif //LAB07_CLION_HASH_H
