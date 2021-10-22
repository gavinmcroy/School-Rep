//
// Created by Gavin Taylor Mcroy on 10/20/21.
//

#ifndef VZL_CLION_FACE_H
#define VZL_CLION_FACE_H

#include <iostream>

class Face {
private:
    size_t numVertices;
    size_t vertex;
    size_t normal;
    size_t st;
public:
    size_t getSize() const;

    size_t getVertex(size_t i) const;

    size_t getNormal(size_t i) const;

    size_t getST(size_t i) const;

};


#endif //VZL_CLION_FACE_H
