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
    Masking(const std::string &inputFile, const std::string &outputFile);

    void preformMask();

    ImageSpec readImage();

    void writeImage();

private:
    char *image;
    char *modifiedImage;
    std::string inputFile;
    std::string outputFile;
    ImageSpec imageSpec;

    void RGBtoHSV(int r, int g, int b, double &h, double &s, double &v);

    const int MAX_OUTPUT_CHANNELS = 4;
};


#endif //MASKING_MASKING_H
