//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//

#include<string>
#include<fstream>
#include<vector>
#include "GrayPixel.h"

#ifndef ASSIGNMENT_1_PGM_H
#define ASSIGNMENT_1_PGM_H


class Pgm {
    int height;
    int width;
    int maxValue;
    bool ascii;
    std::string magicNum;
    std::string fileName;
    std::ifstream inFile;
    std::vector<GrayPixel> grayPixels;
public:

    Pgm(std::string);

    void openImage();

    void closeImage();

    void readImageInformation();

    void createImage();

    void copyImage();

    void printImageInformation();
};


#endif //ASSIGNMENT_1_PGM_H
