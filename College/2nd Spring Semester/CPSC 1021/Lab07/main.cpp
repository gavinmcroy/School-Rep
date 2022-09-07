#include <iostream>
#include"Dog.h"

int main() {
    std::cout << "Before instantiating Dog objects dogCount is " << Dog::getDogCount() << std::endl;
    std::cout << std::endl;

    std::cout << "Printing info" << std::endl;

    Dog dog1("Kevin Smith", 34);
    dog1.setBreed("Golden Retriever");
    dog1.setAge(2);
    dog1.printDogInfo();

    Dog dog2("Lana Strange", 23);
    dog2.setBreed("Staffordshire Terrier");
    dog2.setAge(4);
    dog2.printDogInfo();

    std::cout << std::endl;
    std::cout << "After instantiating Dog objects dogCount is: " << Dog::getDogCount() << std::endl;
    return 0;
}
