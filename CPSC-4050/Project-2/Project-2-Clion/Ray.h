//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"

#ifndef PROJECT_2_RAY_H
#define PROJECT_2_RAY_H


class Ray {
private:
    vzl::Vector position;
    vzl::Vector direction;
public:
    Ray(const vzl::Vector &position, const vzl::Vector &direction);

    const vzl::Vector &getPosition() const;

    const vzl::Vector getDirection() const;

};


#endif //PROJECT_2_RAY_H
