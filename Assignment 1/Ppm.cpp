//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//
#include "Ppm.h"
#include<iostream>
#include<sstream>
#include <utility>

Ppm::Ppm(std::string fileName) {
    this->fileName = std::move(fileName);
    ascii = false;
    binary = false;
}

void Ppm::createImage() {
    //---TODO outputting text file as tmp precaution
    std::cout << "GENERATING IMAGE" << std::endl;

    std::ofstream outFile;
    if (ascii) {
        outFile.open("test.ppm", std::ios::out);

    } else if (binary) {
        outFile.open("test.ppm", std::ios::out | std::ios::binary);
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
        std::vector<ColorPixel>::iterator iter;
        for (iter = pixels.begin(); iter != pixels.end(); iter++) {
//            if (iter->getGreen() < 0) {
//                std::cout << "Error green below 0" << std::endl;
//            }
//            if (iter->getRed() < 0) {
//                std::cout << "Error red below 0" << std::endl;
//            }
//            if (iter->getBlue() < 0) {
//                std::cout << "Error blue below 0" << std::endl;
//            }
            outFile << (unsigned char) iter->getRed();
            outFile << (unsigned char) iter->getGreen();
            outFile << (unsigned char) iter->getBlue();
        }
        return;
    }

    std::vector<ColorPixel>::iterator iter;
    for (iter = pixels.begin(); iter != pixels.end(); iter++) {
        outFile << iter->getRed() << std::endl;
        outFile << iter->getGreen() << std::endl;
        outFile << iter->getBlue() << std::endl;
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
            if (magicNum == "P6") {
                std::cout << "ASCII" << std::endl;
                this->ascii = true;
                this->binary = false;
                break;
            }
            if (magicNum == "P3") {
                std::cout << "Binary" << std::endl;
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

void Ppm::printImageInformation() {
    std::cout << "FILE INPUT NAME: " << this->fileName << std::endl;
    std::cout << "MAGIC NUMBER: " << this->magicNum << std::endl;
    std::cout << "IMAGE WIDTH: " << this->width << std::endl;
    std::cout << "IMAGE HEIGHT: " << this->height << std::endl;
    std::cout << "MAXIMUM VALUE: " << this->maxValue << std::endl;
}

void Ppm::copyImage() {
    int i = 1;
    std::string tmp;
    int red, green, blue;
    std::cout << "COPYING IMAGE TO VECTOR" << std::endl;

    if (ascii) {
        std::vector<int> buffer(std::istreambuf_iterator<char>(inFile), {});
        while (buffer.size() != i) {
            if (i % 3 == 1) {
                //std::cout << "RED: " << buffer.at(i-1) << std::endl;
                red = buffer.at(i - 1);
            } else if (i % 3 == 2) {
                //std::cout << "GREEN: " << buffer.at(i-1) << std::endl;
                green = buffer.at(i - 1);
            } else if (i % 3 == 0) {
                //std::cout << "BLUE: " << buffer.at(i-1) << std::endl;
                blue = buffer.at(i - 1);
                ColorPixel colorPixel(red, green, blue);
                pixels.push_back(colorPixel);
            }
            i++;
        }

    } else if (binary) {
        while (getline(inFile, tmp)) {
            if (i % 3 == 1) {
                //            std::cout << tmp << std::endl;
                //            std::cout << "Red" << std::endl;
                //std::cout<<tmp<<std::endl;
                red = stoi(tmp);
            } else if (i % 3 == 2) {
                //            std::cout << tmp << std::endl;
                //            std::cout << "Green" << std::endl;
                green = stoi(tmp);
            } else if (i % 3 == 0) {
                //            std::cout << tmp << std::endl;
                //            std::cout << "Blue" << std::endl;
                blue = stoi(tmp);
                ColorPixel colorPixel(red, green, blue);
                pixels.push_back(colorPixel);
            }
            i++;
        }
    }
    std::cout << "DONE" << std::endl;
}


void Ppm::closeImage() {
    this->inFile.close();
}


