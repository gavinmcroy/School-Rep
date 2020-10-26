//
// Created by Gavin McRoy on 10/22/2020.
//

#include "Hash.h"

unsigned int Hash::myHash(char s, int table_size) {
    int x = s;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % size;
}

int temp(int x) {
//    x = ((x >> 16) ^ x) * 0x45d9f3b;
//    x = ((x >> 16) ^ x) * 0x45d9f3b;
//    x = (x >> 16) ^ x;
//    return x%size;
}


Hash::Hash() {
    size = 12;
    table = new Node *[size];
    for (int i = 0; i < size; i++)
        table[i] = nullptr;
    num_elems = 0;
    /* TODO Remove print statement */
    std::cout << myHash('0', size) << std::endl;
}

Hash::~Hash() {
    for (int i = 0; i < size; i++) {
        while (table[i] != nullptr) {
            Node *temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
    delete[] table;

}

bool Hash::find(char key) {
    int h = myHash(key, size);
    Node *n = table[h];
    while (n != nullptr) {
        if (n->key == key) return true;
        n = n->next;
    }
    return false;

}

void Hash::insert(char key) {
    assert (!find(key));
    num_elems++;
    int h = myHash(key, size);

    if (num_elems == size) {
        /* Allocates memory for table of double size and stores old table in tmp */
        size *= 2;
        h = myHash(key, size);
        Node **tempNewTable = new Node *[size];
        Node **tmpOldTable = table;
        table = tempNewTable;

        /* Sets all head pointers to NULL in table */
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }

        /* Re hash and copy elements to new table */
        for (int i = 0; i < size / 2; i++) {
            for (Node *tmp = tmpOldTable[i]; tmp != nullptr; tmp = tmp->next) {
                int hash = myHash(tmp->key, size);
                /* Inserts if head pointer is NULL else insert in front of the list */
                if (table[hash] == nullptr) {
                    table[hash] = new Node(tmp->key, nullptr);
                    continue;
                }
                Node *newNode = new Node(tmp->key, table[hash]);
                table[hash] = newNode;
            }
        }
        /* Deletes the old table */
        for (int i = 0; i < size / 2; i++) {
            while (tmpOldTable[i] != nullptr) {
                Node *temp = tmpOldTable[i];
                tmpOldTable[i] = tmpOldTable[i]->next;
                delete temp;
            }
        }
        delete[] tmpOldTable;
    }

    /* Check if first element is empty */
    if (table[h] == nullptr) {
        table[h] = new Node(key, nullptr);
        return;
    }
    /* Inserts element in the front of the list */
    Node *newNode = new Node(key, table[h]);
    table[h] = newNode;

}

void Hash::remove(char key) {
    assert (find(key));
    num_elems--;
    int h = myHash(key, size);
    Node *temp = table[h];
    Node *previous = table[h];

    /* Checks for if the head of the list equals key */
    if (temp->key == key && temp->next != nullptr) {
        table[h] = temp->next;
        delete temp;
        return;
    } else if (temp->key == key) {
        table[h] = nullptr;
        delete temp;
        return;
    }
    for (Node *i = table[h]; i != nullptr; i = i->next) {
        /* Middle of the list check */
        if ((i->key == key) && (i->next != nullptr)) {
            previous->next = i->next;
            delete i;
            return;
        } /* End of the list check */
        else if (i->key == key) {
            previous->next = nullptr;
            delete i;
            return;
        }
        previous = i;
    }

}

void Hash::print() {
    for (int i = 0; i < size; i++) {
        for (Node *j = table[i]; j != nullptr; j = j->next) {
            cout << j->key << endl;
        }
    }

}