#include "Ppm.h"
#include "Pgm.h"
/*
 * Gavin McRoy
 */
int main() {

//    Pgm pgm("potatochips.pgm");
//    pgm.openImage();
//    pgm.readImageInformation();
//    pgm.printImageInformation();
//    pgm.copyImage();
//    pgm.createImage();
//    pgm.closeImage();


    Ppm ppm("potatochips.ppm");
    ppm.openImage();
    ppm.readImageInformation();
    ppm.printImageInformation();
    ppm.copyImage();
    ppm.createImage();
    ppm.closeImage();
    return 0;
}
