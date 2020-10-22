// Compile with stringintmap.cpp from class
#include <iostream>
#include <vector>
#include <algorithm>
#include "stringintmap.h"
using namespace std;

struct Node {
  string key;
  bool is_root;
  int left, right;
  Node (string s) { key = s; left = right = -1; is_root = true; }
};

StringIntMap id;
vector<Node> tree;
vector<string> *results;

void add_node(string s)
{
  if (id.find(s)) return;
  id[s] = tree.size();
  tree.emplace_back(s);
}

void inorder(int x, int depth)
{
  results[depth].push_back(tree[x].key);
  if (tree[x].left != -1) inorder(tree[x].left, depth+1);
  if (tree[x].right != -1) inorder(tree[x].right, depth+1);
}

int main(void)
{
  string parent, child;
  while (cin >> parent >> child) {
    add_node(parent); add_node(child);
    int p = id[parent], c = id[child];
    if (tree[c].key < tree[p].key) tree[p].left = c;
    else                           tree[p].right = c;
    tree[c].is_root = false;
  }
  int root = 0;
  while (!tree[root].is_root) root++;
  results = new vector<string>[tree.size()+1];
  inorder(root, 0);
  for (int i=0; results[i].size() > 0; i++) {
    cout << "Level " << i << ":";
    for (string s : results[i]) cout << " " << s;
    cout << "\n";
  }
}
