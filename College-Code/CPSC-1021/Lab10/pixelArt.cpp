#include<fstream>
#include<iostream>
#include"pixelArt.h"

void pixelArt::readArts(const string &fileName) {
    std::ifstream inFile(fileName, std::ios::in);
    if (!inFile) {
         std::cout << "File open error" << std::endl;
    }
    //---Read char by char and convert to int, pushes vector back once it fills row
    char tmp;
    int i = 1;
    vector<int> v1;
    while (inFile >> tmp) {
        int val = tmp - '0';
        v1.push_back(val);
        if (i % w == 0) {
            pixels.push_back(v1);
            v1.clear();
        }
        i++;
    }
}

pixelArt::pixelArt(int iw, int ih) : w(iw), h(ih) {

}

//int pixelArt::getPixel(int i, int j) {
//
//}

int pixelArt::getW() {
    return w;
}

int pixelArt::getH() {
    return h;
}


pixelArt pixelArt::operator+(int num) {
    for (unsigned int i = 0; i < pixels.size(); i++) {
        for (unsigned int j = 0; j < pixels[i].size(); j++) {
            pixels[i][j] = pixels[i][j] + num;
        }
    }
    return *this;
}

pixelArt pixelArt::operator-(int num) {
    for (unsigned int i = 0; i < pixels.size(); i++) {
        for (unsigned int j = 0; j < pixels[i].size(); j++) {
            pixels[i][j] = pixels[i][j] - num;
        }
    }
    return *this;
}

pixelArt pixelArt::operator+(const pixelArt &pa) {
    for (unsigned int i = 0; i < pixels.size(); i++) {
        for (unsigned int j = 0; j < pixels[i].size(); j++) {
            pixels[i][j] = pixels[i][j] + pa.pixels[i][j];
        }
    }
    return *this;
}
//---9 = ' '
ostream &operator<<(ostream &os, const pixelArt &pa) {
    for (unsigned int i = 0; i < pa.pixels.size(); i++) {
        for (unsigned int j = 0; j < pa.pixels[i].size(); j++) {
            if (pa.pixels[i][j] == 9) {
                os << " ";
            } else {
                os << pa.pixels[i][j];
            }
        }
        os << endl;
    }
    return os;
}

