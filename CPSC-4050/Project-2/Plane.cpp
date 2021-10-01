//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include "Plane.h"

Plane::Plane(const vzl::Vector &position, const vzl::Vector &normalDirection, const vzl::Color &color) : position(
        position), normalDirection(normalDirection), color(color) {
    std::cout << "Plane created" << std::endl;

}

double Plane::intersection(const Ray &ray) const {
    // vzl::Vector intersection = (vzl::Vector)((ray.getPosition() - position) * normalDirection) / (vzl::Vector)(ray.getDirection() * normalDirection);
    double t = ((ray.getPosition() - position) * normalDirection) / (ray.getDirection() * normalDirection);

    /* No intersection test parameters */
    if (t < 0) {
        return NO_INTERSECTION;
    }

    if ((ray.getDirection() * normalDirection) == 0) {
        return NO_INTERSECTION;
    }

    vzl::Vector point = ray.getPosition() + t * ray.getDirection();

    const vzl::Vector &rayPos = ray.getPosition();
    return sqrt(pow((rayPos.X() - point.X()), 2) + pow((rayPos.Y() - point.Y()), 2) +
                pow((rayPos.Z() - point.Z()), 2));
}

const vzl::Color Plane::getColor() const {
    return vzl::Color();
}

vzl::Color Plane::shade(const vzl::Vector &P, const Light &L) const {
    vzl::Vector light = (L.getPosition() - P) / ((L.getPosition() - P).magnitude());

    double f = normalDirection * light;
    if (f < 0.0) {
        f = 0.0;
    }
    return (L.getColor() * color) * (float)f;
}

