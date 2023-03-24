#ifndef INTSET_H /* Prevent multiple inclusion... */
#define INTSET_H

class Intset {

private:
    struct Node {
        int val;
        Node* nextNode;
        Node(int val,Node* next);
    };
    Node *headNode;

public:
    Intset();

    ~Intset();

    bool find(int key);

    void insert(int key);

    void remove(int key);

    void print(void);
};

#endif
