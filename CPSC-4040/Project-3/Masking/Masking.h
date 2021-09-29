//
// Created by Gavin Taylor Mcroy on 9/28/21.
//
#include <OpenImageIO/imageio.h>
#include <iostream>

OIIO_NAMESPACE_USING

#ifndef MASKING_MASKING_H
#define MASKING_MASKING_H

#define maximum(x, y, z) ((x) > (y)? ((x) > (z)? (x) : (z)) : ((y) > (z)? (y) : (z)))
#define minimum(x, y, z) ((x) < (y)? ((x) < (z)? (x) : (z)) : ((y) < (z)? (y) : (z)))


class Masking {
public:
    typedef struct Pixel {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    } Pixel;

    Masking(const std::string &inputFile, const std::string &outputFile);

    ~Masking();

    void preformMask();

    ImageSpec readImage();

    void writeImage();

private:
    unsigned char *image;
    Pixel * imagePixel;

    std::string inputFile;
    std::string outputFile;
    ImageSpec imageSpec;

    static void RGBtoHSV(int r, int g, int b, double &h, double &s, double &v);

    const int MAX_OUTPUT_CHANNELS = 4;
};


#endif //MASKING_MASKING_H
