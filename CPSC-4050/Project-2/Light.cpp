//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Light.h"

const vzl::Vector &Light::getPosition() const {
    return position;
}

const vzl::Color &Light::getColor() const {
    return color;
}
