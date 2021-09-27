//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"
#include "Geometry.h"

#ifndef PROJECT_2_SPHERE_H
#define PROJECT_2_SPHERE_H


class Sphere : Geometry {
public:
    Sphere(const vzl::Vector &position, double radius, const vzl::Color &color);

    double intersection(const Ray &r) const override;

    const vzl::Color getColor() const override;

    vzl::Color shade(const vzl::Vector &p, const Light &l) const override;

private:
    vzl::Vector position;
    double radius;
    vzl::Color color;
};


#endif //PROJECT_2_SPHERE_H
