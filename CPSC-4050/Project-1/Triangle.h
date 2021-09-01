//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#include <vector>
#ifndef PROJECT_1_TRIANGLE_H
#define PROJECT_1_TRIANGLE_H


class Triangle {

    /* Are these triangles 3 points on 2D or 3D
     * Does each triangle cord need to be (x,y,z) */
    Triangle(int cord1,int cord2,int cord3);

    const std::vector<int> threeEdgeVector() const ;

    const std::vector<int> unitNormal() const ;

    const double triangleArea() const ;

    const double triangleAspectRatio() const;

};


#endif //PROJECT_1_TRIANGLE_H
