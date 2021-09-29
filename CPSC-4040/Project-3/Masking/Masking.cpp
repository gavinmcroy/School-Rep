//
// Created by Gavin Taylor Mcroy on 9/28/21.
//

#include "Masking.h"


Masking::Masking(const std::string &input, const std::string &output) {
    this->inputFile = input;
    this->outputFile = output;
    imageSpec = readImage();
    preformMask();
//   double h,s,v;
//    RGBtoHSV(20,113,53,h,s,v);
//    std::cout<<h<<std::endl;
    writeImage();

}

Masking::~Masking() {
    delete image;
    delete imagePixel;
}

void Masking::preformMask() {
    double h, s, v;
    /* Producing a four channel version of the image */
    for (int i = 0; i < (imageSpec.height * imageSpec.width); i++) {
        /* Set alpha channel based on range of hue value by converting to HSV and selecting h = 120 */
        RGBtoHSV(imagePixel->r, imagePixel->g, imagePixel->b, h, s, v);
        /* convert to alpha = 0 if H is in epsilon range, else 255 */
        if (h <= 141.3 && h >= 141.2) {
            /* (20,113,53) */
            imagePixel[i].a = 0;
        } else {
            imagePixel[i].a = 255;
        }
    }
    std::cout << "Mask preformed" << std::endl;
}

ImageSpec Masking::readImage() {
    auto input = ImageInput::open(inputFile);
    if (!input) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }
    ImageSpec imageSpec1 = input->spec();
    image = new unsigned char[imageSpec1.width * imageSpec1.height * imageSpec1.nchannels];
    imagePixel = new Pixel[imageSpec1.width * imageSpec1.height];
    input->read_image(TypeDesc::UINT8, image);

    /* Convert to a imagePixel struct */
    int secondaryCounter = 0;
    for (int i = 0; i < (imageSpec1.width * imageSpec1.height * imageSpec1.nchannels); i++) {
        /* R */
        if (i % 3 == 0) {
            imagePixel[secondaryCounter].r = image[i];
        }/* G */
        else if (i % 3 == 1) {
            imagePixel[secondaryCounter].g = image[i];
        }/* B */
        else if (i % 3 == 2) {
            imagePixel[secondaryCounter].b = image[i];
            secondaryCounter++;
        }
    }

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
    /* We have a new image that has not been updated. Clear and make new one */
    delete[] image;
    image = new unsigned char[imageSpec.width * imageSpec.height * MAX_OUTPUT_CHANNELS];

    int secondaryCounter = 0;
    for (int i = 0; i < (imageSpec.width * imageSpec.height * MAX_OUTPUT_CHANNELS); i++) {
        /* R */
        if (i % MAX_OUTPUT_CHANNELS == 0) {
            image[i] = imagePixel[secondaryCounter].r;
        }/* G */
        else if (i % MAX_OUTPUT_CHANNELS == 1) {
            image[i] = imagePixel[secondaryCounter].g;
        }/* B */
        else if (i % MAX_OUTPUT_CHANNELS == 2) {
            image[i] = imagePixel[secondaryCounter].b;
        }  /* A + we have gone through all channels, next pixel */
        else if (i % MAX_OUTPUT_CHANNELS == 3) {
            image[i] = imagePixel[secondaryCounter].a;
            secondaryCounter++;
        }
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
