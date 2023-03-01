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

Node *unique_merge(Node *A, Node *B)
{
  bool first = true;
  int current;
  Node *result = NULL, **tail = &result;
  while (A || B) {
    Node *&nextguy = (B==NULL || (A && A->key < B->key)) ? A : B;
    if (first || nextguy->key != current) {
      current = nextguy->key;
      *tail = new Node(nextguy->key, NULL);
      tail = &(*tail)->next;
      first = false;
    }
    nextguy = nextguy->next;
  }
  return result;
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

