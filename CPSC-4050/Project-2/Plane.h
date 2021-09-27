//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"
#include "Geometry.h"

#ifndef PROJECT_2_PLANE_H
#define PROJECT_2_PLANE_H


class Plane : public Geometry {
public:
    Plane(const vzl::Vector &position, const vzl::Vector &normalDirection, const vzl::Color &color);

    double intersection(const Ray &ray) const override;

    const vzl::Color getColor() const override;

    vzl::Color shade(const vzl::Vector &P, const Light &L) const override;

private:
    vzl::Vector position;
    vzl::Vector normalDirection;
    vzl::Color color;
};


#endif //PROJECT_2_PLANE_H
