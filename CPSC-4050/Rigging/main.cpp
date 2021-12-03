#include <iostream>
#include "Vector.h"

int main(int args, char *argv[]) {
    if (args < 4) {
        std::cerr << "Not enough arguments passed" << std::endl;
        exit(1);
    }
    vzl::Vector modifiedPoint(atof(argv[1]),atof(argv[2]),atof(argv[3]));

    vzl::Vector P(0, 0, 0);
    double L0 = 2.5;
    double L1 = 1.5;

    std::cout << modifiedPoint.X() << " " << modifiedPoint.Y() << " " << modifiedPoint.Z() << std::endl;
    return 0;
}
