//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Triangle.h"

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
    if (normal * r.getDirection() == 0) {
        return NO_INTERSECTION;
    }

    /* TODO negative may need to be removed since z is not negative? */
    double t = -(normal * r.getPosition() + D) / (normal * r.getDirection());

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

    /* TODO How do we get the return type to match? instead of vzl::Vector we want double */
    /* TODO Short explanation on how does image plane work? */
    /* TODO Short explanation of point light functionality */
    /* TODO How am I exactly determining ray direction? */
    return 0.0;
    /* Want to return this but unable too */
    //return point;
}

const vzl::Color Triangle::getColor() const {
    return vzl::Color();
}

vzl::Color Triangle::shade(const vzl::Vector &P, const Light &L) const {
    return vzl::Color();
}