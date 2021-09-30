//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Camera.h"

Camera::Camera(const vzl::Vector& position, const vzl::Vector& viewDirection, const vzl::Vector& upDirection,
               double fov, double aspectRatio) : position(
        position), viewDirection(viewDirection), upDirection(upDirection), fov(fov), aspectRatio(aspectRatio) {

}

vzl::Vector Camera::view(double x, double y) const {
    /* TODO implement */
    return vzl::Vector();
}
