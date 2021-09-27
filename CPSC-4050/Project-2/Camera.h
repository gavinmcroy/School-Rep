//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"

#ifndef PROJECT_2_CAMERA_H
#define PROJECT_2_CAMERA_H


class Camera {
public:
    Camera(double position, double viewDirection, double upDirection, double fov, double aspectRatio);

private:
    double position;
    double viewDirection;
    double upDirection;
    double fov;
    double aspectRatio;

    vzl::Vector view(double x, double y) const;
};


#endif //PROJECT_2_CAMERA_H
