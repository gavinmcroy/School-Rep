#include <iostream>
#include "HalloweenOptimization.h"

int main() {
    std::string fileName = "candy.txt";
    HalloweenOptimization halloweenOptimization(fileName);
    std::cout << "Greedy : " << halloweenOptimization.greedyImplementation() << std::endl;
    return 0;
}
