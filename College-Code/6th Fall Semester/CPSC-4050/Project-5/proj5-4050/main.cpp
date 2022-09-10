#include <iostream>
#include "Vector.h"

int main(int args, char *argv[]) {
    vzl::Vector axisOfRotation(0, 0, 1);
    if (args < 4) {
        std::cerr << "Not enough arguments passed" << std::endl;
        exit(1);
    }
    vzl::Vector P2(atof(argv[1]), atof(argv[2]), atof(argv[3]));

    vzl::Vector P0(0, 0, 0);
    double L0 = 2.5;
    double L1 = 1.5;

    vzl::Vector x = P2 - P0;
    vzl::Vector xHat = x.unitvector();

    /* This is theta before acos */
    double theta = (std::pow(x.magnitude(), 2) - (L0 * L0) - (L1 * L1)) / (2 * (L0 * L1));

    if (theta < -1 || theta > 1) {
        std::cerr << "Invalid Angle" << std::endl;
        exit(1);
    } else {
        /* This is the actual theta value */
        theta = acos(theta);
    }

    /* Now we need phi */
    double cosPhi = (L0 + L1 * cos(theta)) / (x.magnitude());
    double sinPhi = sin(acos(cosPhi));

    /* */
    vzl::Vector N0 = (xHat * cosPhi) + (axisOfRotation ^ xHat) * sinPhi;

    vzl::Vector P1 = P0 + N0 * L0;

    std::cout << P1.X() << " " << P1.Y() << " " << P1.Z();
    return 0;

}
