#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
  Node (int k) { key = k; left = right = NULL; }
};

Node *insert(Node *root, int x)
{
  if (root == NULL) return new Node(x);
  if (x < root->key) root->left = insert(root->left, x);
  else               root->right = insert(root->right, x);
  return root;
}

// Global variables containing the pre-order traversal of our tree
// and its length.  So A[0] ... A[N-1] is the pre-order traversal.
int *A, N;

void preorder(Node *root)
{
  if (root == NULL) return;
  A[N++] = root->key;
  preorder(root->left);
  preorder(root->right);
}

int select_helper(int r, int i, int j)
{
  int root = A[i], root_rank, left=i+1, right=j; // A[left]<root, A[right]>root
  if (i==j) return root;
  if (A[j] < root) { left=j; right=j+1; }
  else if (A[i+1] > root) { left=i; right=i+1; }
  else {
    while (right - left > 1) {
      int mid = (left+right)/2;
      if (A[mid] < root) left = mid;
      else right = mid;
    }
  }
  root_rank = left-i;
  if (r==root_rank) return root;
  if (r <root_rank) return select_helper(r, i+1, left);
  return select_helper(r-root_rank-1, right, j);
}

// Return the rth largest element, based on the global pre-order array A
// and its length N.  You can write and call helper functions if you need to.
int select(int r)
{
  return select_helper(r, 0, N-1);
}

int main(void)
{
  int B = 10;
  
  // Build random B-node tree and compute its pre-order traversal
  Node *root = NULL;
  for (int i=0; i<B; i++)
    root = insert(root, rand());
  A = new int[B];
  preorder(root);  // Now N = B

  // New test out select...
  cout << "\n";
  for (int r=0; r<N; r++)
    cout << "select(" << r << ") gives " << select(r) << "\n";

  // These results should match what we get when we print out the
  // sorted ordering of A...
  sort(A,A+N); cout << "\n";
  for (int r=0; r<N; r++)
    cout << "select(" << r << ") should have given " << A[r] << "\n";
  cout << "\n";
  
  return 0;
}
