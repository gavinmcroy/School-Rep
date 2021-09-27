//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"

#ifndef PROJECT_2_LIGHT_H
#define PROJECT_2_LIGHT_H


class Light {
public:
    const vzl::Vector &getPosition() const;

    const vzl::Color &getColor() const;

private:
    vzl::Vector position;
    vzl::Color color;
};


#endif //PROJECT_2_LIGHT_H
