//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//
#include<vector>
#include<fstream>
#include"ColorPixel.h"
#include <string>

#ifndef ASSIGNMENT_1_PPM_H
#define ASSIGNMENT_1_PPM_H


class Ppm {
private:
    int height;
    int width;
    int maxValue;
    bool ascii;
    std::string magicNum;
    std::string fileName;
    std::ifstream inFile;
    std::vector<ColorPixel> pixels;

public:

    Ppm(std::string);

    void openImage();

    void closeImage();

    void readImageInformation();

    void createImage();

    void copyImage();

    void printImageInformation();


};


#endif //ASSIGNMENT_1_PPM_H
