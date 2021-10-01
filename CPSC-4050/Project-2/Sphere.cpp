//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include <cmath>
#include "Sphere.h"

Sphere::Sphere(const vzl::Vector &position, double radius, const vzl::Color &color) : position(position),
                                                                                      radius(radius), color(color) {
    /* TODO calculate normal */
    normal = ;
    std::cout << "Sphere created" << std::endl;
}

double Sphere::intersection(const Ray &r) const {
    /* [d_Hat = r.Direction] [R_0 = r.Position] [p_C = position] [R = radius]*/
    double safteyCalculation = sqrt((std::pow(r.getDirection() * (r.getPosition() - position), 2) +
                                    std::pow(radius, 2)) - std::pow((r.getPosition() - position).magnitude(), 2));
    if (safteyCalculation < 0) {
        return NO_INTERSECTION;
    }
    /* This means there is one possible intersection */
    if (safteyCalculation == 0) {
        double t = -r.getDirection() * (r.getPosition() - position);
        /* if possible intersection test failed */
        if (t < 0) {
            return NO_INTERSECTION;
        }
    }

    /* Our two possible solutions to the quadratic */
    double tPlus = (-r.getDirection() * (r.getPosition() - position)) + safteyCalculation;
    double tMinus = (-r.getDirection() * (r.getPosition() - position)) - safteyCalculation;

    /* If both of these are negative reject */
    if (tPlus < 0 && tMinus < 0) {
        return NO_INTERSECTION;
    }

    /* Essentially clearing out the variable. At this point only one can be wrong. Setting the cleared
     * variable to the max ensures that when we will return the smallest */
    if (tPlus < 0) {
        tPlus = std::numeric_limits<double>::max();
    }
    if (tMinus < 0) {
        tMinus = std::numeric_limits<double>::max();
    }

    double min = tMinus < tPlus ? tMinus : tPlus;
    vzl::Vector point = r.getPosition() + min * r.getDirection();
    /* return Tminus if its smallest, else tPlus */

    return (r.getPosition()-point).magnitude();
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
