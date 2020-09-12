#include <iostream>
#include <fstream>

int main() {

    std::ifstream file;
    file.open("points.txt",std::ios::in) ;

    if(file.is_open()){
        std::cout<<"Working"<<std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
