//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "ImagePlane.h"

ImagePlane::ImagePlane(int nX, int nY) : nX(nX), nY(nY) {
    data = new vzl::Color[nX * nY];
    /* TODO temporary test of setting everything to white */
    for (int i = 0; i < nX * nY; i++) {
        data[i] = vzl::Color(1, 1, 1, 1);
    }
}

vzl::Color ImagePlane::get(int i, int j) const {
    return data[i + j * nX];
}

void ImagePlane::set(int i, int j, const vzl::Color &C) {
    data[i + j * nX] = C;
}

int ImagePlane::getNX() {
    return nX;
}

int ImagePlane::getNY() {
    return nY;
}
