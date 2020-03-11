#include "Ppm.h"
#include "Pgm.h"
#include <iostream>
#include<fstream>
/*
 * Gavin McRoy
 */
int main() {
    Pgm pgm("chips.pgm");
    pgm.openImage();
    pgm.readImageInformation();
    pgm.printImageInformation();
    pgm.copyImage();
    pgm.createImage();
    pgm.closeImage();


//    std::ofstream data("data.txt",std::ios::out);
//    unsigned char name = -191;
//    std::cout<<name<<std::endl;
//    std::cout<<(unsigned char)name<<std::endl;
//    data<<name<<std::endl<<name;


//    Ppm ppm("chips.ppm");
//    ppm.openImage();
//    ppm.readImageInformation();
//    ppm.printImageInformation();
//    ppm.copyImage();
//    ppm.createImage();
//    ppm.closeImage();
    return 0;
}
