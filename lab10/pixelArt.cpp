#include<fstream>
#include<iostream>
#include"pixelArt.h"

void pixelArt::readArts(string fileName) {
    std::ifstream inFile(fileName, std::ios::in);
    if (inFile) {
        std::cout << "File opened" << std::endl;
    } else {
        std::cout << "File open error" << std::endl;
    }
    ////---DEBUG
    char tmp;
    int i = 1;
    vector<int> v1;
    while (inFile >> tmp) {
        v1.push_back(tmp - '0');
        if (i % w == 0) {
            v1.push_back('\n');
            pixels.push_back(v1);
            v1.clear();
        }
        i++;
    }
    printVector();
    ////---DEBUG
}

pixelArt::pixelArt(int iw, int ih) : w(iw), h(ih) {

}

int pixelArt::getPixel(int i, int j) {

}

int pixelArt::getW() {
    return w;
}

int pixelArt::getH() {
    return h;
}


pixelArt pixelArt::operator+(int num) {

}

pixelArt pixelArt::operator-(int num) {

}

pixelArt pixelArt::operator+(const pixelArt &pa) {

}

ostream &operator<<(ostream &os, const pixelArt &pa) {

}

void pixelArt::printVector() {
    for (int i = 0; i < pixels.size(); i++) {
        for (int j = 0; j < pixels[i].size(); j++) {
            if (pixels[i][j] == 0) {
                cout << pixels[i][j];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
