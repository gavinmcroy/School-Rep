#include <iostream>
#include <cstdlib>
#include "BinarySearchT.h"

using namespace std;

int main(int argc, char *argv[]) {
    BinarySearchT binarySearchT;
    BinarySearchT::Node *root = nullptr;

    
    /*
        So basically I know you need to use a bst to store the elements in the order you need to print them out. But instead of storing them by their value, you store the elements as a sequence. So i figured out what the pivot would be for each element, and that pivot value should essentially be the rank of the element in the bst. So say you have 9 elements, the pivot would be 0, so you would need to insert 9 at rank 0 of the bst so the first element that’s printed is 9.

        So get the rank of what each element should be by figuring out what the pivot value would be. Then I think you need to write a function that inserts elements into a bst based on that rank. So instead of using the insert function that compares the value of the element you’re inserting to the value of the root, you want compare the rank of the element you are inserting to the rank of the root
     
        I just wasn't able to get this to run properly :(
            (function was insertOnRank at the bottom of BinarySearchT.cpp and .h)
     */
    
    
    if (argc != 2) {
        cout << "Usage: bad1 <input size>\n";
       // return 0;
    }

    int N = atoi(argv[1]);   // get first command-line argument
    if (N < 1 || N > 100000) {
        cout << "Invalid input size!\n";
        //return 0;
    }
    //int counterNum = 0;
    //long long lag = 9;
    cout << N << "\n";
    for (int i = 0;  i < N; i++) {
        root = binarySearchT.insert_keep_balanced(root, i);
        //cout<<i<<endl;
        //lag+=123456789;
    
    }
    for(int i = 0; i < N; i++){
        cout<<binarySearchT.get_rank(root,i)<<endl;
    }
   // cout<<"COUNTER"<<counterNum;
    return 0;
}
