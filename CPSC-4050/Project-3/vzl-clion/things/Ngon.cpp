//
// Created by Gavin Taylor Mcroy on 10/20/21.
//
#include <iostream>
#include "Ngon.h"

Ngon::Ngon(const std::vector<vzl::Vector> &vertices, const std::vector<vzl::Vector> &norms,
           const std::vector<vzl::Vector> &s_t, const Face &face) : vertices(), norms(), sT(), face() {
    std::cout << "nGon overridden constructor" << std::endl;
}

Ngon::Ngon() {
    std::cout << "nGon default constructor" << std::endl;
}

size_t Ngon::getNgonSize() const {
    return ngonSize;
}

bool Ngon::faceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    return false;
}

bool Ngon::setFaceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    return false;
}



