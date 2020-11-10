#include <iostream>
#include "HalloweenOptimization.h"

int main() {
    std::string fileName = "candy.txt";
    HalloweenOptimization halloweenOptimization(fileName);
    std::cout << "Greedy : " << halloweenOptimization.greedyImplementation() << std::endl;
   // std::cout << "Refinement : " << halloweenOptimization.refineImplementation() << std::endl;
    halloweenOptimization.resetForPrune();
    std::cout << "Exhaustive Search " << halloweenOptimization.prunedExhaustiveSearch(0) << std::endl;
    std::cout<< "MAX : " << halloweenOptimization.findMax() << std::endl;
    return 0;
}
