//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//
#include "Ppm.h"
#include<iostream>
#include<sstream>

Ppm::Ppm(std::string fileName,std::string outputFile) {
    this->fileName = std::move(fileName);
    this->outputName = std::move(outputFile);
    ascii = false;
}

Ppm::~Ppm(){

}

void Ppm::createImage() {
    //---TODO outputting text file as tmp precaution
    std::cout << "GENERATING IMAGE" << std::endl;

    std::ofstream outFile;
    if (ascii) {
        outFile.open(outputName, std::ios::out);

    }
    if (!outFile) {

        std::cout << "Error opening/generating file" << std::endl;
        return;
    }
    outFile << magicNum << std::endl;
    outFile << "#Gavins ppm image" << std::endl;
    outFile << width << " " << height << std::endl;
    outFile << maxValue << std::endl;

    if (ascii) {
//        std::vector<ColorPixel>::iterator iter;
//        for (iter = pixels.begin(); iter != pixels.end(); iter++) {
//            outFile << iter->getRed() << std::endl;
//            outFile << iter->getGreen() << std::endl;
//            outFile << iter->getBlue() << std::endl;
//        }

        for (int i = pixels.size()-1; i >= 0; i--) {
            for (int j = pixels.at(i).size()-1; j >= 0 ; j--) {
                outFile << pixels.at(i).at(j).getRed() << std::endl;
                outFile << pixels.at(i).at(j).getGreen() << std::endl;
                outFile << pixels.at(i).at(j).getBlue() << std::endl;
            }
        }
    }

    std::cout << "SUCCESSFUL IMAGE GENERATION" << std::endl;
}

void Ppm::openImage() {
    inFile.open(fileName, std::ios::in);
    if (!inFile) {
        std::cout << "file was not opened" << std::endl;
        return;
    }
}

void Ppm::readImageInformation() {
    std::string tmp;
    if (inFile) {
        std::cout << "File Read" << std::endl;
        while (getline(inFile, magicNum)) {
            if (magicNum == "P3") {
                std::cout << "ASCII" << std::endl;
                inFile.close();
                inFile.open(fileName, std::ios::binary | std::ios::in);
                this->ascii = true;
                break;
            }
        }
    } else {
        std::cout << "File is of wrong type" << std::endl;
        return;
    }

    while (getline(inFile, tmp)) {
        if (tmp.at(0) == '#') {
            continue;
        }
        std::istringstream iss(tmp);
        iss >> this->width >> this->height;

        if (this->width > 255 && this->height > 255) {
            break;
        }
    }
    //---Catches maximum value (0-255)
    getline(inFile, tmp);
    std::istringstream anotherIss(tmp);
    anotherIss >> this->maxValue;
}

void Ppm::printImageInformation() {
    std::cout << "FILE INPUT NAME: " << this->fileName << std::endl;
    std::cout << "MAGIC NUMBER: " << this->magicNum << std::endl;
    std::cout << "IMAGE WIDTH: " << this->width << std::endl;
    std::cout << "IMAGE HEIGHT: " << this->height << std::endl;
    std::cout << "MAXIMUM VALUE: " << this->maxValue << std::endl;
}

void Ppm::copyImage() {
    std::string tmp;
    std::cout << "COPYING IMAGE TO VECTOR" << std::endl;
    if (ascii) {
        int i = 1;
        std::vector<ColorPixel> colorTmp;
        int red, green, blue;
        while (getline(inFile, tmp)) {
            if (i % 3 == 1) {
                red = stoi(tmp);
            } else if (i % 3 == 2) {
                green = stoi(tmp);
            } else if (i % 3 == 0) {
                blue = stoi(tmp);
                ColorPixel colorPixel(red, green, blue);
                colorTmp.push_back(colorPixel);
            }
            if(i%width==0){
                pixels.push_back(colorTmp);
                colorTmp.clear();
            }
            i++;
        }
    }
    std::cout << "DONE" << std::endl;
}

void Ppm::closeImage() {
    this->inFile.close();
}


