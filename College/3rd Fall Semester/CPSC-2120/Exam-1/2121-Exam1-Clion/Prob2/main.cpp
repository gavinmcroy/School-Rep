#include <iostream>
#include<fstream>
#include<string>
#include "BinarySearchT.h"

int experiment(const std::string& s){
    int val = 0;
    for(char i : s){
        val+=i;
    }
    return val;
}
int main() {
    BinarySearchT binarySearchT;
    BinarySearchT::Node* root = nullptr;
    std::ifstream file;
    file.open("prob2_input.txt");
    std::string buffer;
    while(file>>buffer){
        root = binarySearchT.insert_keep_balanced(root,experiment(buffer),buffer);
    }

   binarySearchT.print_inorder(root);
    return 0;
}
