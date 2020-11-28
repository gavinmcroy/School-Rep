#include "Blur.h"
//#include "graphics.h"

int main() {
    Blur blur;
    blur.readImage("paw.ppm");

    std::pair<int, int> val;
    val.first = 0;
    val.second = 0;

    blur.breadthFirstSearch(val);
    std::cout<< 1 <<std::endl;

    //for(int i = 0; i < )
    blur.printPath(val,std::make_pair(450,0));
    std::cout<<blur.getSteps();
   // blur.calculateBlur();

    blur.writeImage("paw2.ppm");
}




