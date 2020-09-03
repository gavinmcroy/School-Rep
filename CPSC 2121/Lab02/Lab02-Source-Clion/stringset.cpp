#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int myhash(string s, int table_size) {
    unsigned int i, h = 0;
    for (i = 0; i < s.length(); i++)
        h = (h * 2917 + (unsigned int) s[i]) % table_size;
    return h;
}

Stringset::Stringset() {
    size = 4; // initial size of table
    table = new Node *[size]; // allocate table, initialize head ptrs all to NULL
    for (int i = 0; i < size; i++)
        table[i] = NULL;
    num_elems = 0;
}

Stringset::~Stringset() {
    for (int i = 0; i < size; i++) {
        while (table[i] != NULL) {
            Node *temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
    delete[] table;
}

/* Return true if key is in the set */
bool Stringset::find(string key) {
    int h = myhash(key, size);
    Node *n = table[h];
    while (n != NULL) {
        if (n->key == key) return true;
        n = n->next;
    }
    return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Stringset::insert(string key) {
    assert (!find(key));
    num_elems++;
    int h = myhash(key, size);

    if (num_elems == size) {
        // TODO: Expand table -- allocate new table of twice the size,
        // re-insert all keys into new table, and de-allocate old table.
        // (you may want to wait and add this code last, once everything
        // else is working, since the class will still function properly,
        // albeit slowly, without this part)
        size *= 2;
        h = myhash(key, size);
        Node **tempNewTable = new Node *[size];
        Node **tmpOldTable = table;
        table = tempNewTable;

        /* Sets all head pointers to NULL in table */
        for (int i = 0; i < size; i++) {
            table[i] = NULL;
        }

        /* Re hash and copy elements to new table */
        for (int i = 0; i < size / 2; i++) {
            for (Node *tmp = tmpOldTable[i]; tmp != NULL; tmp = tmp->next) {
                int hash = myhash(tmp->key, size);
                /* Inserts if head pointer is NULL else insert in front of the list */
                if (table[hash] == NULL) {
                    table[hash] = new Node(tmp->key, NULL);
                    continue;
                }
                Node *newNode = new Node(tmp->key, table[hash]);
                table[hash] = newNode;
            }
        }
        /* Delete the old table */
        for (int i = 0; i < size / 2; i++) {
            while (tmpOldTable[i] != NULL) {
                Node *temp = tmpOldTable[i];
                tmpOldTable[i] = tmpOldTable[i]->next;
                delete temp;
            }
        }
        delete[] tmpOldTable;
    }

    /* Check if first element is empty */
    if (table[h] == NULL) {
        table[h] = new Node(key, NULL);
        return;
    }
    /* Inserts element in the front of the list */
    Node *newNode = new Node(key, table[h]);
    table[h] = newNode;
}

/* Removes a key.  It is an error if key isn't in the set */
void Stringset::remove(string key) {
    assert (find(key));
    num_elems--;
    int h = myhash(key, size);
    Node *temp = table[h];
    Node *previous = table[h];

    /* Checks for if the head of the list equals key */
    if (temp->key == key && temp->next != NULL) {
        table[h] = temp->next;
        delete temp;
        return;
    } else if (temp->key == key) {
        table[h] = NULL;
        delete temp;
        return;
    }
    for (Node *i = table[h]; i != NULL; i = i->next) {
        /* Middle of the list check */
        if ((i->key == key) && (i->next != NULL)) {
            previous->next = i->next;
            delete i;
            return;
        } /* End of the list check */
        else if (i->key == key) {
            previous->next = NULL;
            delete i;
            return;
        }
        previous = i;
    }
}

void Stringset::print(void) {
    for (int i = 0; i < size; i++) {
        for (Node *j = table[i]; j != NULL; j = j->next) {
            cout << j->key << endl;
        }
    }
}
