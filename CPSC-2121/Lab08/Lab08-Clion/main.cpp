#include <iostream>
#include "TSP.h"

int main() {
    TSP tsp("tsp_points.txt");
   // tsp.debugFunction();
    std::cout << "Optimal Tour: " << tsp.calculateOptimalTour() << std::endl;
    tsp.outputTour();
    std::cout<<"Optimal Tour is in Output.txt"<<std::endl;
    //std::cout<<tsp.calculateTourDistance();
    return 0;
}
