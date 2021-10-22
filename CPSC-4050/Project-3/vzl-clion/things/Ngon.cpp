//
// Created by Gavin Taylor Mcroy on 10/20/21.
//
#include <iostream>
#include "Ngon.h"

Ngon::Ngon(const std::vector<vzl::Vector> &vertices, const std::vector<vzl::Vector> &norms,
           const std::vector<vzl::Vector> &s_t, const Face &face) {
    this->vertices = vertices;
    this->norms = norms;
    this->sT = s_t;
    std::cout << "nGon overridden constructor" << std::endl;
    totalVertices = vertices.size();
    /* TODO bug with vertices not being copied */
}

Ngon::Ngon() {
    totalVertices = 0;
    std::cout << "nGon default constructor" << std::endl;
}

size_t Ngon::getNgonSize() const {
    return totalVertices;
}


/* For the input vertex index i, provide
the vertex position P, vertex normal N,
and vertex texture coordinate tc to the
values in the last three items of the sig-
nature, and return true. If i is not a
valid index, do not alter P, N, tc, and
return false. */
bool Ngon::faceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    if(i >= totalVertices || i < 0){
        return false;
    }
    p = vertices[i];
    n = norms[i];
    tc = sT[i];
    return true;
}

/* For the input vertex index i, set the
vertex position P, vertex normal N, and
vertex texture coordinate tc to the val-
ues in the last three items of the sig-
nature, and return true. If i is not a
valid index, do not changes the values
and return false. */
bool Ngon::setFaceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    if(i >= totalVertices || i < 0){
        return false;
    }
    //vertices[i] = p;
    //norms[i] = n;
    //sT[i] = tc;
    return true;
}



