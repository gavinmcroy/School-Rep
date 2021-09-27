//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include "Plane.h"

Plane::Plane(const vzl::Vector &position, const vzl::Vector &normalDirection, const vzl::Color &color) : position(
        position), normalDirection(normalDirection), color(color) {
    std::cout<<"Plane created"<<std::endl;

}

double Plane::intersection(const Ray &ray) const {
    return 0;
}

const vzl::Color Plane::getColor() const {
    return vzl::Color();
}

vzl::Color Plane::shade(const vzl::Vector &P, const Light &L) const {
    return vzl::Color();
}

