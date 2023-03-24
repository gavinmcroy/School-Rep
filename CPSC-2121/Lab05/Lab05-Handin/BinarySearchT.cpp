//
// Created by Gavin McRoy on 10/3/2020.
//

#include "BinarySearchT.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <tuple>

// type of data stored in key fields in tree
using namespace std;

double const BinarySearchT::EPSILON = 1e-9;

bool BinarySearchT::double_equals(double a, double b, double epsilon) {
    return std::abs(a - b) < epsilon;
}


int BinarySearchT::get_size(Node *n) {
    return n == nullptr ? 0 : n->size;
}

void BinarySearchT::update_size(Node *n) {
    n->size = 1 + get_size(n->left) + get_size(n->right);
}

BinarySearchT::Node *BinarySearchT::insert(Node *root, keyType k) {
    if (root == nullptr)
        return new Node(k);
    if (k < root->key)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);
    update_size(root);
    return root;
}

void BinarySearchT::print_inorder(Node *root) {
    if (root == nullptr)
        return;
    print_inorder(root->left);
    cout << root->key << "\n";
    print_inorder(root->right);
}

BinarySearchT::Node *BinarySearchT::find(Node *root, keyType k) {
    if (root == nullptr || k == root->key)
        return root;
    return find(k < root->key ? root->left : root->right, k);
}

BinarySearchT::Node *BinarySearchT::predFind(BinarySearchT::Node *root, keyType k) {
    if (root == nullptr || k == root->key) return root;
    if (k < root->key) return predFind(root->left, k);
    BinarySearchT::Node *right_result = predFind(root->right, k);
    return right_result == nullptr ? root : right_result;
}

pair<BinarySearchT::Node *, BinarySearchT::Node *>
BinarySearchT::split(BinarySearchT::Node *root, keyType k) {
    pair<BinarySearchT::Node *, BinarySearchT::Node *> result = make_pair(root, root);
    if (root == nullptr) return result;
    if (k < root->key) tie(result.first, root->left) = split(root->left, k);
    else tie(root->right, result.second) = split(root->right, k);
    update_size(root);
    return result;
}

BinarySearchT::Node *BinarySearchT::insert_keep_balanced(Node *root, keyType k) {
    if (root == nullptr) return new Node(k);
    if (rand() % (1 + root->size) == 0) {
        Node *new_root = new Node(k);
        tie(new_root->left, new_root->right) = split(root, k);
        update_size(new_root);
        return new_root;
    }
    if (k < root->key) root->left = insert_keep_balanced(root->left, k);
    else root->right = insert_keep_balanced(root->right, k);
    update_size(root);
    return root;
}

BinarySearchT::Node *BinarySearchT::join(Node *L, Node *R) {
    if (L == nullptr) return R;
    if (R == nullptr) return L;
    Node *root = (rand() % (L->size + R->size) < L->size) ? L : R;
    if (root == L) L->right = join(L->right, R);
    else R->left = join(L, R->left);
    update_size(root);
    return root;
}

BinarySearchT::Node *BinarySearchT::remove(Node *root, keyType k) {
    if (root == nullptr) return nullptr;
    if (k == root->key) {
        Node *result = join(root->left, root->right);
        delete root;
        return result;
    }
    if (k < root->key) root->left = remove(root->left, k);
    else root->right = remove(root->right, k);
    update_size(root);
    return root;
}

int BinarySearchT::get_rank(Node *node, double val) {
//    int count = 0;
//    if (node == nullptr) {
//        return 0;
//    }
//    if (val > node->key) {
//        count++;
//    }/* key.compareTo(n.key) > 0)*/
//    return count + get_rank(node->left, val) + get_rank(node->right, val);
    if (node == nullptr) {
        return 0;
    }
    int leftSize = node->left ? node->left->size : 0;
    if (val == node->key) {
        return leftSize;
    }
    if (val < node->key) {
        return get_rank(node->left, val);
    } else {
        return 1 + leftSize + get_rank(node->right, val);
    }

}