//
// Created by Gavin Taylor Mcroy on 10/13/2020 AD.
//

#ifndef PROB2_BINARYSEARCHT_H
#define PROB2_BINARYSEARCHT_H


#include <utility>
#include <string>

class BinarySearchT {

public:
    static double const EPSILON;
    typedef int keyType;

    struct Node {
        std::string myString;
        keyType key;
        int size;
        Node *left, *right;

        explicit Node(keyType k,std::string s) {
            myString = std::move(s);
            key = k;
            size = 1;
            left = right = nullptr;
        }
//        explicit Node(keyType k){
//            key = k;
//            size =1;
//            left = right = nullptr;
//        }
    };

    static bool double_equals(double a,double b,double epsilon);

    int get_size(Node *n);

    void update_size(Node *n);

    Node *insert(Node *root, keyType k, const std::string&);

    void print_inorder(Node *root);

    Node *find(Node *root, keyType k);

    Node *predFind(Node *root, keyType k);

    std::pair<Node *, Node *> split(Node *root, keyType k);

    Node *insert_keep_balanced(Node *root, keyType k, const std::string& s);

    Node *join(Node *L, Node *R);

    Node *remove(Node *root, keyType k);

    int get_rank(Node* node, double val);


};


#endif //PROB2_BINARYSEARCHT_H
