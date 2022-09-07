#include <iostream>
#include <cstdlib>
#include "BinarySearchT.h"

using namespace std;

int main(int argc, char *argv[]) {
    BinarySearchT binarySearchT;
    BinarySearchT::Node *root = nullptr;

    if (argc != 2) {
        cout << "Usage: bad1 <input size>\n";
       // return 0;
    }

    int N = 100000; /* atoi(argv[1]); */  // get first command-line argument
    if (N < 1 || N > 100000) {
        cout << "Invalid input size!\n";
        //return 0;
    }
    int counterNum = 0;
    long long lag = 9;
    cout << N << "\n";
    for (int i = 0;  i < N; i++) {
        //root = binarySearchT.insert_keep_balanced(root, i);
        cout<<lag<<endl;
        lag+=123456789;
        counterNum++;
    }
    cout<<"COUNTER"<<counterNum;
    return 0;
}
