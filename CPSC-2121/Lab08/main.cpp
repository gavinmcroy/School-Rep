#include <iostream>
#include "TSP.h"

int main() {
    TSP tsp("tsp_points.txt");
    std::cout << "Optimal Tour: " << tsp.calculateOptimalTour() << std::endl;
    tsp.outputTour();
    return 0;
}
