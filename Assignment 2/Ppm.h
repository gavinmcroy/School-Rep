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
    std::string outputName;
    std::ifstream inFile;
    std::vector<std::vector<ColorPixel>> pixels;

public:

    Ppm(std::string,std::string);

    ~Ppm();

    void openImage();

    void closeImage();

    void readImageInformation();

    void createImage();

    void copyImage();

    void printImageInformation();


};


#endif //ASSIGNMENT_1_PPM_H
