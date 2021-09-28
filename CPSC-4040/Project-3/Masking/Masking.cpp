//
// Created by Gavin Taylor Mcroy on 9/28/21.
//

#include "Masking.h"


Masking::Masking(const std::string &input, const std::string &output) {
    this->inputFile = input;
    this->outputFile = output;
    imageSpec = readImage();
    writeImage();
}

void Masking::preformMask() {
    int h,s,v;
    bool firstTime = true;
    for(int i = 0; i < (imageSpec.height*imageSpec.width*MAX_OUTPUT_CHANNELS); i++){
        /* For every pixel (3 to 4 colors make a pixel) grab the HSV */
        if(i % imageSpec.nchannels == 0){
            /* Preventing 0 % 3 = 0 (s*/
            if(firstTime){
                firstTime = false;
            }
        }
    }
}

ImageSpec Masking::readImage() {
    auto input = ImageInput::open(inputFile);
    if (!input) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }
    ImageSpec imageSpec1 = input->spec();
    image = new char[imageSpec1.width * imageSpec1.height * imageSpec1.nchannels];
    input->read_image(TypeDesc::UINT8, image);
    input->close();
    std::cout << "Image Read" << std::endl;
    return imageSpec1;
}

void Masking::writeImage() {
    auto out = ImageOutput::create(outputFile);
    ImageSpec specOut = ImageSpec(imageSpec.width, imageSpec.height, MAX_OUTPUT_CHANNELS, TypeDesc::UINT8);
    out->open(outputFile, specOut);
    if (!out) {
        std::cerr << "Error" << std::endl;
    }
    out->write_image(TypeDesc::UINT8, image);
    out->close();
    std::cout << "Image saved " << std::endl;
}

void Masking::RGBtoHSV(int r, int g, int b, double &h, double &s, double &v) {
    double red, green, blue;
    double max, min, delta;
    red = r / 255.0;
    green = g / 255.0;
    blue = b / 255.0; /* r , g, b to 0 − 1 scale */
    max = maximum(red, green, blue);
    min = minimum(red, green, blue);
    v = max; /* value i s maximum of r , g, b */
    if (max == 0) { /* saturation and hue 0 i f value i s 0 */
        s = 0;
        h = 0;
    } else {
        s = (max - min) / max; /* saturation i s color pur i ty on scale 0 − 1 */
        delta = max - min;
        if (delta == 0) { /* hue doesn ' t matter i f saturation i s 0 */
            h = 0;
        } else {
            if (red == max) { /* otherwise , determine hue on scale 0 − 360 */
                h = (green - blue) / delta;
            } else if (green == max) {
                h = 2.0 + (blue - red) / delta;
            } else {/* (blue == max) */
                h = 4.0 + (red - green) / delta;
            }
            h = h * 60.0;
            if (h < 0) {
                h = h + 360.0;
            }
        }
    }
}
