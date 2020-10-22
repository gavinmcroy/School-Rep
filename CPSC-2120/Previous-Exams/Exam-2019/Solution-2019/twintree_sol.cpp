#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
  Node (int k) { key = k; left = right = NULL; }
};

// N trees with roots stored in roots[0] ... roots[N-1]
// roots[ans1] and roots[ans2] are the same; all others are different
// in some way
const int N = 10000, ans1 = 2120, ans2 = 2019;
Node *roots[N];

Node *insert(Node *root, int x)
{
  if (root == NULL) return new Node(x);
  if (x < root->key) root->left = insert(root->left, x);
  else               root->right = insert(root->right, x);
  return root;
}

Node *join(Node *L, Node *R)
{
  if (L == NULL) return R;
  if (R == NULL) return L;
  if (L->key%2) { L->right = join(L->right, R); return L; }
  else          { R->left = join(L, R->left); return R; }
  
}

Node *copy(Node *root)
{
  if (root == NULL) return NULL;
  Node *newroot = new Node(root->key);
  newroot->left = copy(root->left);
  newroot->right = copy(root->right);
  return newroot;
}

// build N trees each of size N
void build_trees(void)
{
  Node *T1 = NULL, *T3 = NULL;
  for (int i=0; i<N/2; i++) T1 = insert(T1, i*100+rand()%100);
  for (int i=0; i<N/2-20; i++) T3 = insert(T3, (N/2+i+20)*100+rand()%100);
  for (int i=0; i<N; i++) {
    Node *T2 = NULL;
    int v = (i==ans1 || i==ans2) ? N : i;
    for (int j=0; j<20; j++) 
      T2 = insert(T2, (N/2+j)*100+((v>>j)&1));  
    roots[i] = join(join(copy(T1),T2),copy(T3));
  }
  cout << "Built " << N << " trees, two being identical\n";
}

bool tree_same(Node *A, Node *B)
{
  if (!A && !B) return true;
  if (!A && B) return false;
  if (A && !B) return false;
  if (A->key != B->key) return false;
  return tree_same(A->left, B->left) && tree_same(A->right, B->right);
}

unsigned int tree_hash(Node *T, unsigned int so_far)
{
  if (T == NULL) return so_far;
  so_far = so_far * 2834757 + T->key;
  so_far = tree_hash(T->left, so_far);
  return   tree_hash(T->right, so_far);
}

struct ListNode {
  int index;
  ListNode *next;
  ListNode (int i, ListNode *n) { index = i; next = n; }
};

int main(void)
{
  build_trees();

  ListNode **table = new ListNode *[N];
  for (int i=0; i<N; i++) table[i] = NULL;  
  for (int i=0; i<N; i++) {
    int h = tree_hash(roots[i], 0) % N;
    for (ListNode *n = table[h]; n; n=n->next)
      if (tree_same(roots[n->index], roots[i]))
	cout << n->index << " " << i << "\n";
    table[h] = new ListNode(i, table[h]);
  }
  
  return 0;
}
