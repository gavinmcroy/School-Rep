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
        outFile.open("TASCII.pgm", std::ios::out);

    } else if (binary) {
        outFile.open("TBinary.pgm", std::ios::out | std::ios::binary);
    }
    if (!outFile) {

        std::cout << "Error opening/generating file" << std::endl;
        return;
    }
    outFile << magicNum << std::endl;
    outFile << "#Gavins ppm image" << std::endl;
    outFile << width << " " << height << std::endl;
    outFile << maxValue << std::endl;

    if (binary) {
        char *buffer = new char[grayPixels.size()];
        int bufferSize = grayPixels.size();

        for (int i = 0; i < grayPixels.size(); i++) {
            buffer[i] = grayPixels.at(i).getIntensity();
        }
        outFile.write(buffer, bufferSize);
        delete[] buffer;

    } else if (ascii) {
        std::vector<GrayPixel>::iterator iter;
        for (iter = grayPixels.begin(); iter != grayPixels.end(); iter++) {
            outFile << iter->getIntensity() << std::endl;
        }
    }

    std::cout << "SUCCESSFUL IMAGE GENERATION" << std::endl;
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
            if (magicNum == "P2") {
                std::cout << "TYPE: ASCII" << std::endl;
                this->ascii = true;
                this->binary = false;
                //---TODO TEMP

                break;
            }
            if (magicNum == "P5") {
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
    std::string tmp;
    int intensity;
    std::cout << "COPYING IMAGE TO VECTOR" << std::endl;

    if (ascii) {
        int i = 1;
        while (getline(inFile, tmp)) {
            intensity = stoi(tmp);
            GrayPixel grayPixel(intensity);
            grayPixels.push_back(grayPixel);
            i++;
        }
    } else if (binary) {

        int location = inFile.tellg();
        //std::cout << location << std::endl;
        inFile.seekg(location, inFile.end);
        int bufferSize = inFile.tellg();
        inFile.seekg(location, inFile.beg);

        //std::cout << bufferSize << std::endl;
        char *buffer = new char[bufferSize];
        inFile.read(buffer, bufferSize);

        if (!inFile) {
            std::cout << "Characters unsuccessfully read from file" << std::endl;
        }

        for (int i = 0; i < bufferSize; i++) {
            unsigned char c = buffer[i];
            GrayPixel grayPixel(c);
            grayPixels.push_back(grayPixel);
        }
    }

    std::cout << "DONE" << std::endl;
}

void Pgm::closeImage() {
    this->inFile.close();
}