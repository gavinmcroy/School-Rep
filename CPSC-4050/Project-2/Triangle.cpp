//
// Created by Gavin Taylor Mcroy on 9/27/21.
//

#include "Triangle.h"

Triangle::Triangle(const vzl::Vector &vertex0, const vzl::Vector &vertex1, const vzl::Vector &vertex2,
                   const vzl::Color &color) : vertex0(vertex0), vertex1(vertex1), vertex2(vertex2), color(color) {
    std::cout<<"Triangle created"<<std::endl;
}


double Triangle::intersection(const Ray &r) const {
    return 0;
}

const vzl::Color Triangle::getColor() const {
    return vzl::Color();
}

vzl::Color Triangle::shade(const vzl::Vector &P, const Light &L) const {
    return vzl::Color();
}