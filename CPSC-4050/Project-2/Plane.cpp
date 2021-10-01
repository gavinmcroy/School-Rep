//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include "Plane.h"

//https://docs.w3cub.com/cpp/types/numeric_limits/epsilon
template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp) {
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x - y) <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
           // unless the result is subnormal
           || std::abs(x - y) < std::numeric_limits<T>::min();
}

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

    if (almost_equal(ray.getDirection() * normalDirection, 0.0, 2)) {
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
    return (L.getColor() * color) * (float) f;
}

