//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef OPEN_TEST_WARP_H
#define OPEN_TEST_WARP_H

#include <iostream>
#include "matrix.h"

class Warp {
private:
    Matrix3D matrix3D;
public:
    Warp();

    void inputSequence(Matrix3D & M);

    void rotate(Matrix3D &M, float theta);


};


#endif //OPEN_TEST_WARP_H
