//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Ray.h"

Ray::Ray(const vzl::Vector &position, const vzl::Vector &direction) : position(position), direction(direction) {

}

const vzl::Vector &Ray::getPosition() const {
    return position;
}

const vzl::Vector Ray::getDirection() const {
    return direction;
}

