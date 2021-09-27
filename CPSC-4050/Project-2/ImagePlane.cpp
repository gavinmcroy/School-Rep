//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "ImagePlane.h"

ImagePlane::ImagePlane(double nX, double nY) : nX(nX), nY(nY){

}

vzl::Color ImagePlane::get(int i, int j) const {
    return vzl::Color();
}

void ImagePlane::set(int i, int j, const vzl::Color &C) {

}
