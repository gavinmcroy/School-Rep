//
// Created by Gavin Taylor Mcroy on 10/20/21.
//

#ifndef VZL_CLION_FACE_H
#define VZL_CLION_FACE_H

#include <iostream>
#include <vector>
#include "../include/Vector.h"

class Face {
private:
    size_t numVertices;
    std::vector<size_t> vertex;
    std::vector<size_t> normal;
    std::vector<size_t> st;
public:
    Face(const std::vector<size_t> &vertex, const std::vector<size_t> &normal,
         const std::vector<size_t> &s_t);

    size_t getSize() const;

    size_t getVertex(size_t i) const;

    size_t getNormal(size_t i) const;

    size_t getST(size_t i) const;

};


#endif //VZL_CLION_FACE_H
