// This file is the same as the lab 4 BST solution up to the main() part
// We also included the stringintmap code written in class, with the
// only modification that we made the elements in that class public so
// we could access them directly (e.g,. to enumerate through the
// contents of the hash table).  We also relabeled the "Node" struct
// here to a BstNode so it wouldn't conflict with the "Node" struct
// in stringintmap.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include "stringintmap_quiz1.h"

using namespace std;

struct BstNode {
  int key;
  int size;
  BstNode *left;
  BstNode *right;
  BstNode (int k) { key = k; size = 1; left = right = NULL; }
};

void fix_size(BstNode *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
BstNode *insert(BstNode *T, int k)
{
  if (T == NULL) return new BstNode(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// prints out the inorder traversal of T (i.e., the contents of T in sorted order)
void print_inorder(BstNode *T)
{
  if (T == NULL) return;
  print_inorder(T->left);
  cout << T->key << "\n";
  print_inorder(T->right);
}

// return a pointer to the node with key k in tree T, or NULL if it doesn't exist
BstNode *find(BstNode *T, int k)
{
  if (T == NULL) return NULL;
  if (k == T->key) return T;
  if (k < T->key) return find(T->left, k);
  else return find(T->right, k);
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
BstNode *select(BstNode *T, int r)
{
  assert(T!=NULL && r>=0 && r<T->size);

  int rank_of_root = T->left ? T->left->size : 0;
  if (r == rank_of_root) return T;
  if (r < rank_of_root) return select(T->left, r);
  else return select(T->right, r - rank_of_root - 1);
}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(BstNode *T, int k, BstNode **L, BstNode **R)
{
  if (T == NULL) {
    *L = NULL;
    *R = NULL;
    return;
  }
  if (k < T->key) {
    // recursively split left subtree
    split(T->left, k, L, &T->left);
    *R = T;
  } else {
    split(T->right, k, &T->right, R);
    *L = T;
  }
  fix_size(T);
}

// insert key k into the tree T, returning a pointer to the resulting tree
BstNode *insert_keep_balanced(BstNode *T, int k)
{
  // If k is the Nth node inserted into T, then:
  // with probability 1/N, insert k at the root of T
  // otherwise, insert_random k recursively left or right of the root of T
  if (T == NULL) return new BstNode(k);
  if (rand() % (T->size + 1) == 0) {
    // insert at root
    BstNode *new_root = new BstNode(k);
    split(T, k, &new_root->left, &new_root->right);
    fix_size(new_root);
    return new_root;
  }
  if (k < T->key) T->left = insert_keep_balanced(T->left, k);
  else T->right = insert_keep_balanced(T->right, k);
  fix_size(T);
  return T;
}

// New code beyond this point...

struct StrNode { 
  string val; 
  StrNode *next;
  StrNode (string s, StrNode *n) { val = s; next = n; }
};

int main(void)
{
  ifstream text("e.txt");
  string s;
  StringIntMap C, R;
  BstNode *T = NULL;
  while (text >> s) C[s]++;
  for (int i=0; i<C.size; i++)
    for (Node *n = C.table[i]; n; n=n->next)
      T = insert_keep_balanced(T, n->val);
  int threshold = select(T, T->size - 1000)->key;

  StrNode **uncommon_words = new StrNode *[threshold];
  for (int i=0; i<threshold; i++) uncommon_words[i] = NULL;
  ifstream fin("s.txt");
  while (fin >> s) 
    if (C[s] < threshold && !R.find(s)) {
      R[s]=0;
      uncommon_words[C[s]] = new StrNode(s, uncommon_words[C[s]]);
    }
  for (int i=threshold-1; i>=0; i--) 
    if (uncommon_words[i]) {
      cout << "Frequency " << i << ":";
      for (StrNode *n = uncommon_words[i]; n; n=n->next)
	cout << " " << n->val;
      cout << "\n";
    }
  return 0;
}
