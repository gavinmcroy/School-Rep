//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"

#ifndef PROJECT_2_SPHERE_H
#define PROJECT_2_SPHERE_H


class Sphere {
public:
    Sphere(const vzl::Vector &position, double radius, const vzl::Color &color);

    double intersection(const Ray &r) const;

    const vzl::Color getColor() const;

    vzl::Color shade(const vzl::Vector &p, const Light &l) const;

private:
    vzl::Vector position;
    double radius;
    vzl::Color color;
};


#endif //PROJECT_2_SPHERE_H
