#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
  Node (int k, Node *n) { key = k; next = n; }
};

void print_list(Node *n)
{
  while (n != NULL) {
    cout << n->key << " ";
    n = n->next;
  }
  cout << "\n";
}

// Given linked lists A and B in sorted order, return a newly-allocated
// linked list containing one copy of each distinct element from A and B,
// also in sorted order.  You can write and call other helper functions
// if you like.
Node *unique_merge(Node *A, Node *B)
{
  // TBD...
}



int main(void)
{
  // A is the list of 1, 1, 3, 4
  // B is the list of 1, 3, 3
  Node *A = new Node(1, new Node(1, new Node(3, new Node(4, NULL))));
  Node *B = new Node(1, new Node(3, new Node(3, NULL)));
  print_list(unique_merge(A,B)); // should print 1, 3, 4
  return 0;
}
