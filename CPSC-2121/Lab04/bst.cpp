#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <tuple>

using namespace std;

struct Node {
    int key;
    int size;    // number of nodes in this node's subtree
    Node *left;
    Node *right;

    Node(int k) {
        key = k;
        size = 1;
        left = right = nullptr;
    }
};

int findMinimumVal(Node *T) {
    if (T->left == nullptr) {
        return T->key;
    }
    return findMinimumVal(T->left);

}

/* insert key k into tree T, returning a pointer to the resulting tree */
Node *insert(Node *T, int k) {
    if (T == nullptr) {
        return new Node(k);
    }
    if (k < T->key) {
        T->left = insert(T->left, k);
    } else {
        T->right = insert(T->right, k);
    }
    T->size++;
    return T;
}

/* prints out the inorder traversal of T (i.e., the contents of T in sorted order) */
void print_inorder(Node *T) {
    if (T == nullptr) return;
    print_inorder(T->left);
    cout << T->key << endl;
    print_inorder(T->right);
}

/* return a pointer to the node with key k in tree T, or NULL if it doesn't exist */
Node *find(Node *T, int k) {
    /* key does not exist */
    if (T == nullptr) {
        return nullptr;
    }
    if (T->key == k) {
        return T;
    }
    if (k < T->key) {
        return find(T->left, k);
    } else {
        return find(T->right, k);
    }
}

/* TODO Return pointer to the node with key k if it exists
 * TODO If not, return a pointer to the node with the largest key smaller than k (i.e.,
 * TODO k's predecessor) or NULL if there isn't any node with key smaller than k. */
Node *predfind(Node *T, int k) {

    /* 3 Cases assume 20 is the root
     * predfind(20) return the root
     * prefind(5) -left sub tree (recursion)
     * prefind(50) -right sub tree (What if the smallest is 53?) (if you get back null then the root is the pred)
     */

    Node *findIfExist = find(T, k);

    /* There is no pred */
    if (findMinimumVal(T) < k) {
        return nullptr;
    }
    /* If the key exists in the tree */
    if (findIfExist != nullptr) {
        return findIfExist;
    }

    return nullptr;
}

/* TODO Join trees L and R (with L containing keys all <= the keys in R)
 * TODO Return a pointer to the joined tree.  */
Node *join(Node *L, Node *R) {
    /* choose either the root of L or the root of R to be the root of the joined tree
     * (where we choose with probabilities proportional to the sizes of L and R) */
    /* TODO Probably need some base cases here or else the next line will crash... */
    if (L == nullptr) {
        return R;
    }
    if (R == nullptr) {
        return L;
    }

    int total = L->size + R->size;
    int randn = rand() % total;  /* Pick random number in {0, 1, ..., total-1} */

    /* Make L the root of the joined tree in this case */
    /* R has to be merged into L's right subtree */
    if (randn < L->size) {
        /* Happens with probability L->size / total */
        L->right = join(L->right, R);
        L->size = 1;
        if (L->left) L->size += L->left->size;
        if (L->right) L->size += L->right->size;
        /* Change size */
        return L;
    } else {
        /* Happens with probability R->size / total
         * Make R the root of the joined tree in this case */

        R->left = join(L, R->left);
        R->size = 1;
        if (R->left) {
            R->size += R->left->size;
        }
        if (R->right) {
            R->size += R->right->size;
        }

        /* Change size */
        return R;
    }
}

/* TODO remove key k from T, returning a pointer to the resulting tree.
 * TODO if k isn't present in T, then return the pointer to T's root, with T unchanged */
Node *remove(Node *T, int k) {

    /* TODO Delete root? return join of left and right children */
//    if (!find(T, k)) {
//        return nullptr;
//    }
//    if(T== nullptr){
//        return nullptr;
//    }
    assert(find(T, k) != nullptr);

    if (T->key == k) {
        Node *tmp = T;
        T = join(T->left, T->right);
        delete tmp;
        return T;
    }

    if (k < T->key) {
        T->left = remove(T->left, k);
        // T->size--;
    } else {
        T->right = remove(T->right, k);
        //T->size--;
    }
    //T->size--;

    T->size = 1;
    if (T->left) {
        T->size += T->left->size;
    }
    if (T->right) {
        T->size += T->right->size;
    }
    return T;
}

/* TODO Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k) */
pair<Node *, Node *> split(Node *T, int k) {

    /* Assume root is 20. Split at 5 breaks the tree so that l<5 and r>5
     * this is passed on to the left subtree. For values < 5 we can just let them be
     * and we can reattach the values > 5 back to our left tree */
    if (T == nullptr) {
        return make_pair(nullptr, nullptr);
    }
    if (k < T->key) {
        split(T->left, k);
        T->size = 1;
        if (T->left) {
            T->size += T->left->size;
        }
        if (T->right) {
            T->size += T->right->size;
        }
        return make_pair(T, T->left);
    } else {
        split(T->right, k);
        T->size = 1;
        if (T->left) {
            T->size += T->left->size;
        }
        if (T->right) {
            T->size += T->right->size;
        }
        return make_pair(T->right, T);
    }
    /* What is you split on the root (20)? Should return two trees with vals < 20 and one with vals > 20
     * Delegate the split to the right, if 20 does not exist then the right bcomes NULL and the other previous
     * right tree is "pulled" out */

    /* Below is just for syntax reference on how to return a pair; you'll want to
     * remove this bit when filling in the function yourself...
     * Node *root_of_left_part;
     * Node *root_of_right_part;
     * return make_pair(root_of_left_part, root_of_right_part);
     */
//    T->size = 1;
//    if (T->left) {
//        T->size += T->left->size;
//    }
//    if (T->right) {
//        T->size += T->right->size;
//    }
    //return make_pair()
}

/* insert key k into the tree T, returning a pointer to the resulting tree
 * keep the tree balanced by using randomized balancing.
 * We'll discuss the algorithm used here in lecture:
 * if N represents the size of our tree after the insert, then
 * ... with probability 1/N, insert k at the root of T (by splitting on k)
 * ... otherwise recursively call insert_keep_balanced on the left or right */
Node *insert_keep_balanced(Node *T, int k) {
    if (T == nullptr) return new Node(k);
    if (rand() % (1 + T->size) == 0) {
        // With probability 1/N, insert at root...
        pair<Node *, Node *> result = split(T, k);
        T = new Node(
                k); // ok to re-use T for new root, since result keeps pointers to remnants of original tree after splitting it
        T->left = result.first;
        T->right = result.second;
    } else {
        // Otherwise, recurseively insert on left or right side...
        if (k < T->key) T->left = insert_keep_balanced(T->left, k);
        else T->right = insert_keep_balanced(T->right, k);
    }
    // Make sure T's size is correct, since its subtrees may have changed
    T->size = 1;
    if (T->left != nullptr) T->size += T->left->size;
    if (T->right != nullptr) T->size += T->right->size;
    return T;
}

int main(void) {
    // Testing insert and print_inorder
    int A[10];

    // put 0..9 into A[0..9] in random order
    for (int i = 0; i < 10; i++) A[i] = i;
    for (int i = 9; i > 0; i--) swap(A[i], A[rand() % i]);

    // insert contents of A into a BST
    Node *T = nullptr;
    for (int i = 0; i < 10; i++) T = insert(T, A[i] * 10);

    // print contents of BST (should be 0, 10, 20, ..., 90 in sorted order)
    cout << "\nTesting insert and print_inorder (should be 0,10,20,...,90)\n";
    print_inorder(T);
    cout << "Size (should be 10): " << (T ? T->size : 0) << "\n";

    // test find: Elements 0,10,...,90 should be found; 100 should not be found
    cout << "\nTesting find (should be 0,10,20,...,90 found, 100 not found)\n";
    for (int i = 0; i <= 100; i += 10)
        if (find(T, i)) cout << i << " found\n";
        else cout << i << " not found\n";

    // test predfind -- if nothing printed, that's good news
//    if (predfind(T, -1)) cout << "Error: predfind(-1) returned something and should have returned NULL\n";
//    if (predfind(T, 50)->key != 50) cout << "Error: predfind(50) didn't return the node with 50 as its key\n";
//    cout << "Marker" << endl;
//
//    for (int i = 0; i <= 90; i += 10) {
//        if (predfind(T, i + 3)->key != i) {
//            cout << "Error: predfind(" << i + 3 << ") didn't return the node with " << i << " as its key\n";
//        }
//    }


    // test split
    cout << "\nTesting split\n";
    Node *L, *R;
    tie(L, R) = split(T, 20);  // we'll talk about tie() and tuples shortly...
    // Alternatively, could say:
    // pair<Node *, Node *> result = split(T, 20);
    // Node *L = result.first, *R = result.second;

    cout << "Contents of left tree after split (should be 0..20):\n";
    print_inorder(L);
    cout << "\nSize left subtree (should be 3): " << L->size << "\n";
    cout << "Contents of right tree after split (should be 30..90):\n";
    print_inorder(R);
    cout << "\nSize right subtree (should be 7): " << R->size << "\n";

    // test join
    T = join(L, R);
    cout << "\nTesting join\n";
    cout << "Contents of re-joined tree (should be 0,10,20,...,90)\n";
    print_inorder(T);
    cout << "\nSize (should be 10): " << T->size << "\n";

    // test remove
    cout << "\nTesting remove\n";
    for (int i = 0; i < 10; i++) A[i] = i * 10;
    for (int i = 9; i > 0; i--) swap(A[i], A[rand() % i]);
    for (int i = 0; i < 10; i++) {
        T = remove(T, A[i]);
        cout << "Contents of tree after removing " << A[i] << ":\n";
        print_inorder(T);
        cout << "\nSize of tree after this removal (should be 1 less than before): " << (T ? T->size : 0) << "\n";
    }

    // test insert_keep_balanced basic functionality
    // insert contents of A into a BST
    for (int i = 0; i < 10; i++) T = insert_keep_balanced(T, A[i]);

    // print contents of BST
    cout << "\n" << "Testing insert_keep_balanced (should be 0,10,20,..90)\n";
    print_inorder(T);
    cout << "\n" << "Size (should be 10): " << T->size << "\n";

    // test insert_keep_balanced speed
    cout << "Inserting 10 million elements in order; this should be very fast if insert_balance is working...\n";
    for (int i = 0; i < 10000000; i++) T = insert_keep_balanced(T, i + 10); // 10 million ints starting at 10
    cout << "Done\n";
    cout << "Size (should be 10000010): " << T->size << "\n\n";

    return 0;
}
