//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Ray.h"

const vzl::Vector &Ray::getPosition() const {
    //return <#initializer#>;
}

const vzl::Vector Ray::getDirection() const {
    return vzl::Vector();
}

Ray::Ray(const vzl::Vector &position, const vzl::Vector &direction) : position(position), direction(direction) {

}
