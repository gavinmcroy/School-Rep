//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Triangle.h"

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


Triangle::Triangle(const vzl::Vector &vertex0, const vzl::Vector &vertex1, const vzl::Vector &vertex2,
                   const vzl::Color &color) : vertex0(vertex0), vertex1(vertex1), vertex2(vertex2), color(color) {
    /* Normal vector to the triangle (Also the plane) */
    normal = (vertex1 - vertex0) ^ (vertex2 - vertex0);
    std::cout << "Triangle created" << std::endl;
}


double Triangle::intersection(const Ray &r) const {
    /* point(t) = start + (T-solveFor)direction */
    /* Distance from the origin (0,0,0) to plane */
    double D = normal * vertex0;

    /* Ray is parallel (N * R) therefore no intersection */
    if (almost_equal(normal * r.getDirection(),0.0,2)) {
        return NO_INTERSECTION;
    }

    /* TODO negative may need to be removed since z is not negative? */
    double t = (normal * r.getPosition() + D) / (normal * r.getDirection());

    /* if t < 0 then the triangle is "Behind" the ray */
    if (t < 0.0) {
        return NO_INTERSECTION;
    }
    vzl::Vector point = r.getPosition() + t * r.getDirection();

/*  inside outside test for our triangle */
    vzl::Vector edge0 = vertex1 - vertex0;
    vzl::Vector edge1 = vertex2 - vertex1;
    vzl::Vector edge2 = vertex0 - vertex2;
    vzl::Vector C0 = point - vertex0;
    vzl::Vector C1 = point - vertex1;
    vzl::Vector C2 = point - vertex2;

    if (!((normal * (edge0 ^ C0)) > 0 && (normal * (edge1 ^ C1)) > 0 &&
          (normal * (edge2 ^ C2)) > 0)) {
        return NO_INTERSECTION;
    }

    /* TODO returning distance from ray to point of intersection */
//    double temp = (rayPos-point).magnitude();
    //double temp2 = sqrt(pow((rayPos.X() - point.X()), 2) + pow((rayPos.Y() - point.Y()), 2) +
      //                  pow((rayPos.Z() - point.Z()), 2));
    /* Distance in between starting point and calculated point */
    return (r.getPosition()-point).magnitude();
}

const vzl::Color Triangle::getColor() const {
    return color;
}

vzl::Color Triangle::shade(const vzl::Vector &P, const Light &L) const {
    /* L_hat = (PL - Pi) / |PL - Pi| where PL = pointLightLoc Pi = Point Intersection */
    vzl::Vector light = (L.getPosition() - P) / ((L.getPosition() - P).magnitude());

    double f = normal * light;
    if (f < 0.0) {
        f = 0.0;
    }
    return (L.getColor() * color) * (float)f;
}