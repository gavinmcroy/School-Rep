//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"

#ifndef PROJECT_2_PLANE_H
#define PROJECT_2_PLANE_H


class Plane {
public:
    double intersection(const Ray &ray) const;

    const vzl::Color getColor() const;

    vzl::Color shade(const vzl::Vector &P, const Light &L) const;

private:
    vzl::Vector position;
    vzl::Vector normalDirection;
    vzl::Color color;
};


#endif //PROJECT_2_PLANE_H
