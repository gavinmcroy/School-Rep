//
// Created by Gavin Taylor Mcroy on 10/20/21.
//

#include "Face.h"

size_t Face::getSize() const {
    return numVertices;
}

/* Somewhat confusing to mentally picture, but there are 3 vertices that make up a faces.
 * All the faces locations are stored inside Ngon. All a faces stores is the index at which the vertex lives inside
 * nGon. So since 3 vertices make up a faces, we pick which vertices index we are interested in, which
 * is the location where it lives inside Ngon*/
size_t Face::getVertex(size_t i) const {
    return vertex[i];
}

size_t Face::getNormal(size_t i) const {
    return normal[i];
}

size_t Face::getST(size_t i) const {
    return st[i];
}
