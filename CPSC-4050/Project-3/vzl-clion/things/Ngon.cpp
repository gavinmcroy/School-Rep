//
// Created by Gavin Taylor Mcroy on 10/20/21.
//

#include "Ngon.h"

Ngon::Ngon(const std::vector<vzl::Vector> &vertices, const std::vector<vzl::Vector> &norms,
           const std::vector<vzl::Vector> &s_t, const Face &face) {

}

size_t Ngon::ngonSize() const {
    return 0;
}

bool Ngon::faceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    return false;
}

bool Ngon::setFaceValues(const size_t i, Vector &p, Vector &n, Vector &tc) const {
    return false;
}

