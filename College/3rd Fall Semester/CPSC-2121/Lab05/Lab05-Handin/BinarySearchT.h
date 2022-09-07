//
// Created by Gavin McRoy on 10/3/2020.
//

#ifndef LAB05_CLION_BINARYSEARCHT_H
#define LAB05_CLION_BINARYSEARCHT_H
#include <cstdlib>
#include <utility>

class BinarySearchT {

public:
    static double const EPSILON;
    typedef double keyType;

    struct Node {
        keyType key;
        int size;
        Node *left, *right;

        explicit Node(keyType k) {
            key = k;
            size = 1;
            left = right = nullptr;
        }
    };

    static bool double_equals(double a,double b,double epsilon);

    int get_size(Node *n);

    void update_size(Node *n);

    Node *insert(Node *root, keyType k);

    void print_inorder(Node *root);

    Node *find(Node *root, keyType k);

    Node *predFind(Node *root, keyType k);

    std::pair<Node *, Node *> split(Node *root, keyType k);

    Node *insert_keep_balanced(Node *root, keyType k);

    Node *join(Node *L, Node *R);

    Node *remove(Node *root, keyType k);

    int get_rank(Node* node, double val);


};


#endif //LAB05_CLION_BINARYSEARCHT_H
