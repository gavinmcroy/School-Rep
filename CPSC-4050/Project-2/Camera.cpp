//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Camera.h"

Camera::Camera(vzl::Vector position, vzl::Vector viewDirection, vzl::Vector upDirection, double fov, double aspectRatio) : position(
        position), viewDirection(viewDirection), upDirection(upDirection), fov(fov), aspectRatio(aspectRatio) {}

vzl::Vector Camera::view(double x, double y) const {
    return vzl::Vector();
}
