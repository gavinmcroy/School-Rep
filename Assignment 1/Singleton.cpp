//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//
#include "Ppm.h"
#include "Pgm.h"
#include "Singleton.h"

Singleton::Singleton() {
    Pgm pgm("potatochips.pgm");
    pgm.openImage();
    pgm.readImageInformation();
    pgm.printImageInformation();
    pgm.copyImage();
    pgm.createImage();
    pgm.closeImage();

//    Ppm ppm("potatochips.ppm");
//    ppm.openImage();
//    ppm.readImageInformation();
//    ppm.printImageInformation();
//    ppm.copyImage();
//    ppm.createImage();
//    ppm.closeImage();

}

Singleton *Singleton::getInstance() {
    if (!instance) {
        instance = new Singleton();
        return instance;
    } else {
        return instance;
    }
}

Singleton *Singleton::instance = nullptr;