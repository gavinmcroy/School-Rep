//
// Created by Gavin Taylor Mcroy on 10/20/21.
//
#include <vector>
#include "Face.h"
#include "../include/Vector.h"

using namespace vzl;

#ifndef VZL_CLION_NGON_H
#define VZL_CLION_NGON_H


class Ngon {
public:
    Ngon(const std::vector<Vector> &vertices,
         const std::vector<Vector> &norms,
         const std::vector<Vector> &s_t,
         const Face &face);

    size_t ngonSize() const;

    bool faceValues(size_t i, Vector &p, Vector &n, Vector &tc) const;

    bool setFaceValues(size_t i, Vector &p, Vector &n, Vector &tc) const;

};


#endif //VZL_CLION_NGON_H
