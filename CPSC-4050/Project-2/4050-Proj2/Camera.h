//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include "Vector.h"

#ifndef PROJECT_2_CAMERA_H
#define PROJECT_2_CAMERA_H

class Camera {
public:
    Camera(const vzl::Vector& position, const vzl::Vector& viewDirection, const vzl::Vector& upDirection,
           double fov, double aspectRatio);

    vzl::Vector view(double x, double y) const;

    double getFov() const ;
    double getAspectRatio() const;
    vzl::Vector getPosition() const;

private:
    vzl::Vector position;
    vzl::Vector viewDirection;
    vzl::Vector upDirection;
    double fov;
    double aspectRatio;



};


#endif //PROJECT_2_CAMERA_H
