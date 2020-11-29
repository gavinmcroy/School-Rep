#include "Blur.h"
//#include "graphics.h"

int main() {
    Blur blur;
    blur.readImage("paw.ppm");

    std::pair<int, int> val;
    val.first = 450;
    val.second = 450;

    blur.breadthFirstSearch(val);
    blur.findEveryWhitePixel();


    //std::cout<< 1 <<std::endl;

    //for(int i = 0; i < )
    //blur.printPath(val,std::make_pair(0,0));
    blur.calculateBlur();
   // std::cout<<blur.getSteps();
   // blur.calculateBlur();

    blur.writeImage("paw2.ppm");
}




