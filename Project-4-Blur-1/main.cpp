#include "Blur.h"
//#include "graphics.h"

int main() {
    Blur blur;
    blur.readImage("paw.ppm");

    std::pair<int, int> val;
    val.first = 0;
    val.second = 0;

    blur.breadthFirstSearch(val);
   // blur.findEveryWhitePixel();


    //std::cout<< 1 <<std::endl;

    //for(int i = 0; i < )
   // blur.printPath(val,std::make_pair(57,200));
    blur.calculateBlur();
   // std::cout<<blur.getSteps();

   std::cout<<blur.modified(val,std::make_pair(57,200))<<std::endl;

    blur.writeImage("paw2.ppm");
}




