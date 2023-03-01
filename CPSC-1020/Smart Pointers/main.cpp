#include <iostream>
#include<memory>
#include "Object.h"
#include<vector>
#include<string>
using namespace std;

int main() {
    std::vector<double> my_vec;
    vector<string> names[24];
    
    vector<int> scores(20,0);

    int nums[ ] = {4, 7, 11, 13, 15, 17, 19, 21, 71};
    int *numptr = nums;
    for (int i = 0; i < 3; i++) {
        numptr++;
    }
    cout<<*numptr<<endl;

    Object obj1;
    Object obj2;
    obj1 = obj2;
    std::cout<<obj1<<std::endl;

    std::unique_ptr<int> myPtr(new int);
    *myPtr = 20;
    std::shared_ptr<int> sharedPtr(new int);
    std::shared_ptr<int> sharedPtr1(new int);
    sharedPtr = sharedPtr1;
    std::cout<<*myPtr<<std::endl;
    std::cout << "Hello, World!" << std::endl;



    return 0;
}
