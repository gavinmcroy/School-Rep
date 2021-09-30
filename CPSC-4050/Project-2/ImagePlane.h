//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Color.h"
#ifndef PROJECT_2_IMAGEPLANE_H
#define PROJECT_2_IMAGEPLANE_H


class ImagePlane {

public:
    ImagePlane(int nX, int nY);

    vzl::Color get(int i, int j) const;

    void set(int i, int j, const vzl::Color &C);

    int getNX();

    int getNY();

private:
    int nX;
    int nY;

    vzl::Color * data;

};


#endif //PROJECT_2_IMAGEPLANE_H
