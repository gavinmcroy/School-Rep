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
        outFile.open("T_CASCII.ppm", std::ios::out);

    } else if (binary) {
        outFile.open("T_CBINARY.ppm", std::ios::out | std::ios::binary);
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
//        std::vector<ColorPixel>::iterator iter;
//        for (iter = pixels.begin(); iter != pixels.end(); iter++) {
//            if (iter->getGreen() < 0) {
//                std::cout << "Error green below 0" << std::endl;
//            }
//            if (iter->getRed() < 0) {
//                std::cout << "Error red below 0" << std::endl;
//            }
//            if (iter->getBlue() < 0) {
//                std::cout << "Error blue below 0" << std::endl;
//            }
//            outFile << (unsigned char) iter->getRed();
//            outFile << (unsigned char) iter->getGreen();
//            outFile << (unsigned char) iter->getBlue();
//        }

//        outFile.write(buffer, bufferSize);
//        delete[] buffer;

        ///TESTING
        int tmpLength = pixels.size() * 3;
        char *buffer = new char[tmpLength];

        //---I is set to one in order to accurately determine which color (RGB) is needed
        int i = 1;
        int j = 0;

//        for(int i =1; i<pixels.size();i++){
//            for(int j = 1; j<3; j++){
//                if(j%3==1) {
//                    buffer[j*i] = pixels.at(i-1).getRed();
//                }else if(j%3==2){
//                    buffer[j*i] = pixels.at(i-1).getGreen();
//                }else if(j%3==0){
//                    buffer[j*i] = pixels.at(i-1).getBlue();
//                }
//            }
//        }
        while (i <= tmpLength) {
            if (i % 3 == 1) {
                buffer[i - 1] = pixels.at(j).getRed();
                i++;
                //--Red
            } else if (i % 3 == 2) {
                //--Green
                buffer[i - 1] = pixels.at(j).getGreen();
                i++;
            } else if (i % 3 == 0) {
                //---Blue
                buffer[i - 1] = pixels.at(j).getBlue();
                i++;
                j++;
            }

        }
        outFile.write(buffer, tmpLength);
        delete[] buffer;
        ///TESTING

        return;
    } else if (ascii) {
        std::vector<ColorPixel>::iterator iter;
        for (iter = pixels.begin(); iter != pixels.end(); iter++) {
            outFile << iter->getRed() << std::endl;
            outFile << iter->getGreen() << std::endl;
            outFile << iter->getBlue() << std::endl;
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
            if (magicNum == "P6") {
                std::cout << "BINARY" << std::endl;
                this->ascii = false;
                this->binary = true;
                break;
            }
            if (magicNum == "P3") {
                std::cout << "ASCII" << std::endl;
                inFile.close();
                inFile.open(fileName, std::ios::binary | std::ios::in);
                this->ascii = true;
                this->binary = false;
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
    std::string tmp;
    std::cout << "COPYING IMAGE TO VECTOR" << std::endl;

    if (binary) {
//        std::vector<int> buffer(std::istreambuf_iterator<char>(inFile), {});
//        while (buffer.size() != i) {
//            if (i % 3 == 1) {
//                //std::cout << "RED: " << buffer.at(i-1) << std::endl;
//                red = buffer.at(i - 1);
//            } else if (i % 3 == 2) {
//                //std::cout << "GREEN: " << buffer.at(i-1) << std::endl;
//                green = buffer.at(i - 1);
//            } else if (i % 3 == 0) {
//                //std::cout << "BLUE: " << buffer.at(i-1) << std::endl;
//                blue = buffer.at(i - 1);
//                ColorPixel colorPixel(red, green, blue);
//                pixels.push_back(colorPixel);
//            }
//            i++;
//        }

        int location = inFile.tellg();
        std::cout << location << std::endl;
        inFile.seekg(location, inFile.end);
        int bufferSize = inFile.tellg();
        inFile.seekg(location, inFile.beg);

        std::cout << bufferSize << std::endl;
        char *buffer = new char[bufferSize];
        inFile.read(buffer, bufferSize);

        if (inFile) {
            std::cout << "characters read from file! " << std::endl;
        }


        ///---SEPARATE FROM EVERYTHING ELSE
        int i = 1;
        unsigned char red, blue, green;
        while (i < bufferSize) {
            if (i % 3 == 1) {
                red = buffer[i - 1];
            } else if (i % 3 == 2) {
                green = buffer[i - 1];
            } else if (i % 3 == 0) {
                blue = buffer[i - 1];
                ColorPixel colorPixel(red, green, blue);
                pixels.push_back(colorPixel);
            }
            i++;
        }
        delete[] buffer;

        ///---SEPARATE FROM EVERYTHING ELSE


    } else if (ascii) {
        int i = 1;
        int red, green, blue;
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


