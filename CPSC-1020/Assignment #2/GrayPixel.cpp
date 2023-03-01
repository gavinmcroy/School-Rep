//
// Created by Gavin Taylor Mcroy on 2/29/2020 AD.
//

#include "GrayPixel.h"


GrayPixel::GrayPixel(int intensity){
    this->intensity = intensity;
}

GrayPixel::~GrayPixel(){

}

int GrayPixel::getIntensity(){
    return intensity;
}