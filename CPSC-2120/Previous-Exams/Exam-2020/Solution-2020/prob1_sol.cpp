#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
  Node (int k, Node *n) { key = k; next = n; }
};

void print_list(Node *head)
{
  for (Node *n = head; n != NULL; n = n->next) cout << n->key << " ";
  cout << "\n";
}

// Restore list to sorted order and return a pointer to its head pointer
Node *fix_list(Node *head)
{
  if (head->next == NULL) return head;
  if (head->key > head->next->key) swap (head->key, head->next->key);
  fix_list(head->next);
  if (head->key > head->next->key) swap (head->key, head->next->key);
  return head;
}

int main(void)
{
  Node *head = NULL;

  // Make list with one out-of-place node
  for (int x=100; x>=50; x-=9) head = new Node(x, head);
  head = new Node(87, head);
  for (int x=45; x>=0; x-=13) head = new Node(x, head);

  cout << "Original list:  ";
  print_list(head);

  head = fix_list(head);

  cout << "Corrected list: ";
  print_list(head);
}
