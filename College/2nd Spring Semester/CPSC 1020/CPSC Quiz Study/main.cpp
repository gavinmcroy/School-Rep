#include <iostream>
#include "Object.h"

int main() {

    Object obj2(20,20);
    Object obj1;

    Object obj = obj2;
    std::cout<<obj.getX()<<std::endl;

    int val = obj2+obj1;
    std::cout<<val<<std::endl;


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
