#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node (int v, Node *n) { val = v; next = n; }
  Node () { val = 0; next = NULL; }
};

// Return a linked list containing the even elements of array[0..N-1]
// in the order they appear in the array.  The array is not to be modified.
Node *filter_evens(int *array, int N)
{
  Node *n = NULL;
  for (int i=N-1; i>=0; i--) 
    if (array[i]%2 == 0) n = new Node(array[i], n);
  return n;
}

int main(void)
{
  int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *head = filter_evens(A, 10);
  return 0;
}
