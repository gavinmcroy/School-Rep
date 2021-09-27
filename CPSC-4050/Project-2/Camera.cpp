//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Camera.h"

Camera::Camera(double position, double viewDirection, double upDirection, double fov, double aspectRatio) : position(
        position), viewDirection(viewDirection), upDirection(upDirection), fov(fov), aspectRatio(aspectRatio) {}

vzl::Vector Camera::view(double x, double y) const {
    return vzl::Vector();
}
