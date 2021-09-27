//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Sphere.h"

Sphere::Sphere(const vzl::Vector &position, double radius, const vzl::Color &color) : position(position),
                                                                                      radius(radius), color(color) {}

double Sphere::intersection(const Ray &r) const {
    return 0;
}

const vzl::Color Sphere::getColor() const {
    return vzl::Color();
}

vzl::Color Sphere::shade(const vzl::Vector &p, const Light &l) const {
    return vzl::Color();
}
