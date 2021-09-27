//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "ImagePlane.h"

ImagePlane::ImagePlane(float nX, float nY, vzl::Color *data) : nX(nX), nY(nY), data(data) {}

vzl::Color ImagePlane::get(int i, int j) const {
    return vzl::Color();
}

void ImagePlane::set(int i, int j, const vzl::Color &C) {

}
