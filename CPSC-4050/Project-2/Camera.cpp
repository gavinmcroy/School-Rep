//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Camera.h"

Camera::Camera(const vzl::Vector &position, const vzl::Vector &viewDirection, const vzl::Vector &upDirection,
               double fov, double aspectRatio) : position(
        position), viewDirection(viewDirection), upDirection(upDirection), fov(fov), aspectRatio(aspectRatio) {

}

double Camera::getFov() const {
    return fov;
}

double Camera::getAspectRatio() const {
    return aspectRatio;
}

vzl::Vector Camera::getPosition() const {
    return position;
}


vzl::Vector Camera::view(double x, double y) const {
    vzl::Vector rHat = viewDirection ^ upDirection; //(move outside)
    vzl::Vector pixelPos = (x * rHat) + (y * upDirection);

    /* dHat = (x_arrow + nC_hat) / | x_arrow + nC_hat | */
    return (pixelPos + viewDirection) / ((pixelPos + viewDirection).magnitude());

}

