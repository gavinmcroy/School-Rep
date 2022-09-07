#include <iostream>
#include<vector>
#include "Test.h"
#include "Inherit.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<Test*> tmp;
    tmp.push_back(new Inherit);
    tmp.push_back(new Test);
    
    Test *test = new Inherit;
    auto* ah = dynamic_cast<Inherit*>(test);

    for(int i = 0; i<tmp.size(); i++){
        tmp.at(i)->printFunction();
    }

    return 0;
}
