#include <iostream>
#include "TSP.h"

int main() {

    /* TODO For point, should I add the corresponding city number? Meaning point (x,y) is the third
     * City out of the points, therefore a variable called number = 3 */

    std::cout << "Hello, World!" << std::endl;
    TSP tsp("tsp_points.txt");
    std::cout << "Optimal Tour: " << tsp.calculateOptimalTour() << std::endl;

    return 0;
}
