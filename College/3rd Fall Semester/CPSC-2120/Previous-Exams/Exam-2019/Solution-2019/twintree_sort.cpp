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

// -1 = A<B, 0 = A==B, +1=A>B
int tree_cmp(Node *A, Node *B)
{
  if (!A && !B) return 0;
  if (!A &&  B) return -1;
  if ( A && !B) return +1;
  if (A->key < B->key) return -1;
  if (A->key > B->key) return +1;
  int lres = tree_cmp(A->left, B->left);
  return lres ? lres : tree_cmp(A->right, B->right);
}

struct Tree { int index; };

bool operator== (const Tree a, const Tree b)
{
  return tree_cmp(roots[a.index], roots[b.index]) == 0;
}  

bool operator< (const Tree a, const Tree b)
{
  return tree_cmp(roots[a.index], roots[b.index]) == -1;
}

int main(void)
{
  build_trees();

  Tree T[N];
  for (int i=0; i<N; i++) T[i].index = i;
  sort (T,T+N);
  for (int i=0; i<N-1; i++)
    if (T[i]==T[i+1]) cout << T[i].index << " " << T[i+1].index << "\n";
  
  return 0;
}
