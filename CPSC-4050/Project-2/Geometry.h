//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Light.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"

#ifndef PROJECT_2_GEOMETRY_H
#define PROJECT_2_GEOMETRY_H


class Geometry {

    virtual double intersection(const Ray &r) { return -1.0; }

    virtual const vzl::Color getColor() { return vzl::Color(1, 1, 1, 1); }

    virtual vzl::Color shade(const vzl::Vector &P, const Light &L) { return vzl::Color(1, 1, 1, 1); }
};


#endif //PROJECT_2_GEOMETRY_H
