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
    Masking() = default;

    static ImageSpec readImage(const std::string &inputFile, char *&image);

    static void writeImage(const std::string &outputFile, int width, int height, char *image);

    static void RGBtoHSV(int r, int g, int b, double &h, double &s, double &v);

    static const int MAX_OUTPUT_CHANNELS = 3;
};


#endif //MASKING_MASKING_H
