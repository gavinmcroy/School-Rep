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

Node *umerge(Node *A, Node *B, int current, bool first)
{
  if (!A && !B) return NULL;
  if (!A || (B && B->key <= A->key)) swap(A,B); // take from A next
  return (first || A->key != current) ? new Node(A->key, umerge(A->next,B,A->key,false)) : umerge(A->next,B,current,false);      
}

Node *unique_merge(Node *A, Node *B)
{
  return umerge(A,B,0,true);
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
