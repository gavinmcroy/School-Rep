//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef OPEN_TEST_WARP_H
#define OPEN_TEST_WARP_H

#include <iostream>
#include <OpenImageIO/imageio.h>
#include "matrix.h"

OIIO_NAMESPACE_USING

class Warp {
private:
    Matrix3D forwardMap;
    Matrix3D inverseMap;

    std::pair<int,int> newImageResolution;
    std::pair<int, int> currentImageRes;

    unsigned char * originalImage;
    unsigned char * warpedImage;

public:
    Warp();

    void inputSequence(Matrix3D & M);

    void rotate(Matrix3D &M, float theta);

    unsigned char * preformWarp(unsigned char *image , const ImageSpec& spec);

    std::pair<int,int> toForwardMap(int x, int y);

    std::pair<int, int> u(int x, int y);

    int v(int x, int y);

    void writeImage();


};


#endif //OPEN_TEST_WARP_H
