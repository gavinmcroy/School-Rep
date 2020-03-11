//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//

#include "Pgm.h"
#include "Ppm.h"
#include<iostream>
#include<sstream>
#include <utility>

Pgm::Pgm(std::string fileName) {
    this->fileName = std::move(fileName);
    ascii = false;
    binary = false;
}

void Pgm::createImage() {
    //---TODO outputting text file as tmp precaution
    std::cout << "GENERATING IMAGE" << std::endl;

    std::ofstream outFile;
    if (ascii) {
        outFile.open("test1.pgm", std::ios::out);

    } else if (binary) {
        outFile.open("test.pgm", std::ios::out | std::ios::binary);
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
        std::vector<GrayPixel>::iterator iter;
        for (iter = grayPixels.begin(); iter != grayPixels.end(); iter++) {
            if (iter->getIntensity() < 0) {
                //std::cout << "Error intensity below 0" << iter->getIntensity()<<std::endl;
                outFile <<  (unsigned char) (iter->getIntensity()+255);
            }else{
                outFile << (unsigned char) iter->getIntensity();
            }
        }
        return;
    }

    std::vector<GrayPixel>::iterator iter;
    for (iter = grayPixels.begin(); iter != grayPixels.end(); iter++) {
        outFile << iter->getIntensity() << std::endl;
    }

    std::cout << "SUCCESSFUL IMAGE GENERATION" << std::endl;
    outFile.close();
}

void Pgm::openImage() {
    inFile.open(fileName, std::ios::in);
    if (!inFile) {
        std::cout << "file was not opened" << std::endl;
        return;
    }
}

void Pgm::readImageInformation() {
    std::string tmp;
    if (inFile) {
        std::cout << "File Read" << std::endl;
        while (getline(inFile, magicNum)) {
            if (magicNum == "P5") {
                std::cout << "TYPE: ASCII" << std::endl;
                this->ascii = true;
                this->binary = false;
                break;
            }
            if (magicNum == "P2") {
                std::cout << "TYPE: Binary" << std::endl;
                inFile.close();
                inFile.open(fileName, std::ios::binary | std::ios::in);
                this->ascii = false;
                this->binary = true;
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
    //---Catches maximum value
    getline(inFile, tmp);
    std::istringstream anotherIss(tmp);
    anotherIss >> this->maxValue;
}

void Pgm::printImageInformation() {
    std::cout << "FILE INPUT NAME: " << this->fileName << std::endl;
    std::cout << "MAGIC NUMBER: " << this->magicNum << std::endl;
    std::cout << "IMAGE WIDTH: " << this->width << std::endl;
    std::cout << "IMAGE HEIGHT: " << this->height << std::endl;
    std::cout << "MAXIMUM VALUE: " << this->maxValue << std::endl;
}

void Pgm::copyImage() {
    int i = 1;
    std::string tmp;
    int intensity;
    std::cout << "COPYING IMAGE TO VECTOR" << std::endl;

    if (ascii) {
        std::vector<int> buffer(std::istreambuf_iterator<char>(inFile), {});
        while (buffer.size() != i) {
            intensity = buffer.at(i-1);
            GrayPixel grayPixel(intensity);
            grayPixels.push_back(grayPixel);
            i++;
        }
    } else if (binary) {
        while (getline(inFile, tmp)) {
            intensity = stoi(tmp);
            GrayPixel grayPixel(intensity);
            grayPixels.push_back(grayPixel);
            i++;
        }
    }
    std::cout << "DONE" << std::endl;
}


void Pgm::closeImage() {
    this->inFile.close();
}