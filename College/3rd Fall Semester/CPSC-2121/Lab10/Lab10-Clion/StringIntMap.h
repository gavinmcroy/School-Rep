//
// Created by Gavin McRoy on 11/19/2020.
//

#ifndef LAB10_STRINGINTMAP_H
#define LAB10_STRINGINTMAP_H

#include<string>
#include <utility>

using namespace std;

class StringIntMap {
private:

    struct Node {
        string key;
        int val;
        Node *next;

        Node(string k, int v, Node *n) {
            key = std::move(k);
            val = v;
            next = n;
        }
    };

    Node **table;  // array of pointers to linked lists
    int size;      // size of table, as currently allocated
    int numElements; // number of elements stored in the table
    Node **allocateTable(int size);  // private helper function

public:
    StringIntMap();

    ~StringIntMap();

    int &operator[](string key);

    bool find(string key);

    void insert(string key, int val);

    void remove(string key);

    void print();

    int getNumElements();

    string *getKeys();
};



#endif //LAB10_STRINGINTMAP_H
