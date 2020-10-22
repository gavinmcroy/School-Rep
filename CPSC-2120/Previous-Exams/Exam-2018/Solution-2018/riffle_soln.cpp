#include <iostream>
#include <cstdlib>
using namespace std;

int *riffle(int *A, int *B, int n)
{
  int *result = new int[n*2], a=0, b=0;
  while (a+b != 2*n) result[a+b] = (b==n || (a<n && rand()%2)) ? A[a++] : B[b++];
  return result;
}

struct Node {
  int val;
  Node *next;
  Node (int v, Node *n) { val = v; next = n; }
};

Node *riffle(Node *A, Node *B)
{
  Node *result = NULL, **tail = &result;
  while (A || B) {
    Node *&nextguy = (B==NULL || (A && rand()%2)) ? A : B;
    *tail = new Node(nextguy->val, NULL);
    tail = &(*tail)->next;
    nextguy = nextguy->next;
  }
  return result;
}

int main(void)
{
  return 0;
}

