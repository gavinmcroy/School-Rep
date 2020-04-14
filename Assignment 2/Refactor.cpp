//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//
#include "Ppm.h"
#include "Pgm.h"
#include "Refactor.h"

Refactor::Refactor(const std::string &input, const std::string &output) {
    if (input.find(".pgm") != -1) {
        Pgm pgm(input, output);
        pgm.openImage();
        pgm.readImageInformation();
        pgm.printImageInformation();
        pgm.copyImage();
        pgm.createImage();
        pgm.closeImage();
    } else {
        Ppm ppm(input, output);
        ppm.openImage();
        ppm.readImageInformation();
        ppm.printImageInformation();
        ppm.copyImage();
        ppm.createImage();
        ppm.closeImage();
    }

}

Refactor *Refactor::getInstance(const std::string &input, const std::string &output) {
    if (!instance) {
        instance = new Refactor(input, output);
        return instance;
    } else {
        return instance;
    }
}

Refactor *Refactor::instance = nullptr;