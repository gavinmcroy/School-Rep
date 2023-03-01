// O(n log n) solution
#include <iostream>
#include <cstdlib>
#include <tuple>
#include <iomanip>
using namespace std;

typedef int keytype; // type of data stored in key fields in tree

struct Node {
  keytype key;
  int size; 
  Node *left, *right;
  Node (keytype k) { key = k; size = 1; left = right = NULL; }
};

int get_size(Node *n) { return n == NULL ? 0 : n->size; }
void update_size(Node *n) { n->size = 1 + get_size(n->left) + get_size(n->right); }

Node *insert(Node *root, keytype k)
{
  if (root == NULL) return new Node(k);
  if (k < root->key) root->left  = insert(root->left,  k);
  else               root->right = insert(root->right, k);
  update_size (root);
  return root;
}

void print_inorder(Node *root)
{
  if (root == NULL) return;
  print_inorder(root->left);
  cout << root->key << "\n";
  print_inorder(root->right);
}

Node *find(Node *root, keytype k)
{
  if (root == NULL || k == root->key) return root;
  return find(k < root->key ? root->left : root->right, k);
}

Node *predfind(Node *root, keytype k)
{
  if (root == NULL || k == root->key) return root;
  if (k < root->key) return predfind(root->left, k);
  Node *right_result = predfind(root->right, k);
  return right_result == NULL ? root : right_result;
}

Node *succfind(Node *root, keytype k)
{
  if (root == NULL || k == root->key) return root;
  if (k > root->key) return succfind(root->right, k);
  Node *left_result = succfind(root->left, k);
  return left_result == NULL ? root : left_result;
}

pair<Node *, Node *> split(Node *root, keytype k)
{
  pair <Node *, Node *> result = make_pair (root, root);
  if (root == NULL) return result;
  if (k < root->key) tie (result.first, root->left)   = split (root->left, k);
  else               tie (root->right, result.second) = split (root->right, k);
  update_size (root);
  return result;
}

Node *insert_keep_balanced(Node *root, keytype k)
{
  if (root == NULL) return new Node(k);
  if (rand() % (1 + root->size) == 0) {
    Node *new_root = new Node(k);
    tie (new_root->left, new_root->right) = split (root, k);
    update_size (new_root);
    return new_root;
  } 
  if (k < root->key) root->left  = insert_keep_balanced(root->left,  k);
  else               root->right = insert_keep_balanced(root->right, k);
  update_size (root);
  return root;
}

Node *join(Node *L, Node *R)
{
  if (L == NULL) return R;
  if (R == NULL) return L;
  Node *root = (rand() % (L->size + R->size) < L->size) ? L : R;
  if (root == L) L->right = join(L->right, R); 
  else           R->left  = join(L, R->left);   
  update_size (root);
  return root;
}

Node *remove(Node *root, keytype k)
{
  if (root == NULL) return NULL;
  if (k == root->key) {
    Node *result = join(root->left, root->right);
    delete root;
    return result;
  }
  if (k < root->key) root->left  = remove (root->left, k);
  else               root->right = remove (root->right, k);
  update_size (root);
  return root;
}

// Guaranteed to output a hash value in the range 0 ... 999,999
unsigned int myhash(int x)
{
  return ((unsigned)x * 123147 + 293871) % 100 + 900000;
}

int main(void)
{ 
  Node *root = NULL;
  int N = 1000000;
  for (int i=0; i<N; i++) root = insert_keep_balanced(root, i);
  double total = 0.0, worst = 0.0;
  for (int i=1; i<=N; i++) {
    int h = myhash(i), dist;
    Node *result = succfind(root, h);
    if (result) 
      dist = result->key - h + 1;
    else {
      result = succfind(root, 0);
      dist = N - h + result->key + 1;
    }
    root = remove(root, result->key);
    total += dist;
    worst = max(worst, (double)dist);
  }
  cout << "Average " << setprecision(15) << total/N << " Max " << worst << "\n";
}
