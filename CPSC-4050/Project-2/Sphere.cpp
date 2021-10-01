//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Sphere.h"

Sphere::Sphere(const vzl::Vector &position, double radius, const vzl::Color &color) : position(position),
                                                                                      radius(radius), color(color) {
    /* TODO find normal */
    std::cout << "Sphere created" << std::endl;
}

double Sphere::intersection(const Ray &r) const {

    return NO_INTERSECTION;
}

const vzl::Color Sphere::getColor() const {
    return color;
}

vzl::Color Sphere::shade(const vzl::Vector &P, const Light &L) const {
    vzl::Vector light = (L.getPosition() - P) / ((L.getPosition() - P).magnitude());
    double f = normal * light;
    if (f < 0.0) {
        f = 0.0;
    }
    return (L.getColor() * color) * (float) f;
}
