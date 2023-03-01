//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//

#include "ColorPixel.h"

ColorPixel::ColorPixel() {
    this->red = 0;
    this -> green = 0;
    this-> blue = 0;
}

ColorPixel::ColorPixel(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

ColorPixel::~ColorPixel() {

}

int ColorPixel::getRed() {
    return this->red;
}

int ColorPixel::getGreen() {
    return this->green;
}

int ColorPixel::getBlue() {
    return this->blue;
}