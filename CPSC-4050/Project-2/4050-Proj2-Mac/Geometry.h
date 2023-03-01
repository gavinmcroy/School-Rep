//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Light.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"

#ifndef PROJECT_2_GEOMETRY_H
#define PROJECT_2_GEOMETRY_H


class Geometry {
public:



    const double NO_INTERSECTION = -1.0;

    virtual double intersection(const Ray &r) const = 0; /*{ return -1.0; };*/

    virtual const vzl::Color getColor() const = 0; /*{ return vzl::Color(1, 1, 1, 1); }; */

    virtual vzl::Color shade(const vzl::Vector &P, const Light &L) const = 0; /*{ return vzl::Color(1, 1, 1, 1); };*/
};


#endif //PROJECT_2_GEOMETRY_H
