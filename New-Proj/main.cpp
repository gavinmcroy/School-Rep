#include <iostream>
#include "HalloweenOptimization.h"

int main() {
    std::string fileName = "candy.txt";
    HalloweenOptimization halloweenOptimization(fileName);
    std::cout << "Greedy : " << halloweenOptimization.greedyImplementation() << std::endl;
    //halloweenOptimization.debugPrintStatements();
    std::cout<<"Refinement : "<<halloweenOptimization.refineImplementation()<<std::endl;
    return 0;
}
