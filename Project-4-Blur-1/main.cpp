#include "Blur.h"
//#include "graphics.h"

int main() {
    Blur blur;
    blur.readImage("paw.ppm");
    //blur.breadthFirstSearch();
    blur.calculateBlur();
    blur.writeImage("paw2.ppm");
}




