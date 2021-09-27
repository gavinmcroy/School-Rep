//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"
#include "Color.h"
#include "Ray.h"

#ifndef PROJECT_2_TRIANGLE_H
#define PROJECT_2_TRIANGLE_H


class Triangle {
public:
    Triangle(const vzl::Vector &vertex0, const vzl::Vector &vertex1, const vzl::Vector &vertex2,
             const vzl::Color &color);

    double intersection(const Ray &r) const;

    const vzl::Color getColor() const;

    vzl::Color shade(const vzl::Vector &P, const Light &L);
private:
    vzl::Vector vertex0;
    vzl::Vector vertex1;
    vzl::Vector vertex2;
    vzl::Color color;
};


#endif //PROJECT_2_TRIANGLE_H
