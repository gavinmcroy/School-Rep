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
    /* Lets find our T */
    double t = ((ray.getPosition() - position) * normalDirection) / (ray.getDirection() * normalDirection);

    /* No intersection test parameters */
    if (t < 0) {
        return NO_INTERSECTION;
    }

    if (almost_equal(ray.getDirection() * normalDirection, 0.0, 2)) {
        return NO_INTERSECTION;
    }

    /* Grab our intersection point */
    vzl::Vector point = ray.getPosition() + t * ray.getDirection();
    /* Return distance to ray from intersection */
    return (ray.getPosition() - point).magnitude();
}

const vzl::Color Plane::getColor() const {
    return color;
}

vzl::Color Plane::shade(const vzl::Vector &P, const Light &L) const {
    /* Little bit of lambertian shading. This function is the same for all 3 geometric objects  */
    vzl::Vector light = (L.getPosition() - P) / ((L.getPosition() - P).magnitude());
    double f = normalDirection * light;
    if (f < 0.0) {
        f = -f;
    } else {
        /* TODO found a bug. Returns less than 0 every time */
        std::cout << "Nothing" << std::endl;
    }
    return (L.getColor() * color) * (float) f;
}

