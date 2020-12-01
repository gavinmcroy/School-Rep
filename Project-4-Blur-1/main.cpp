#include "Blur.h"
//#include "graphics.h"

int main() {
    Blur blur;
    blur.readImage("paw.ppm");

    std::pair<int, int> val;
    val.first = -1;
    val.second = -1;

    blur.buildMegaNode();
    blur.calculateBlur();

   // std::cout << blur.printShortedPathOnImage(val, std::make_pair(57, 200)) << std::endl;

    blur.writeImage("paw2.ppm");
}




