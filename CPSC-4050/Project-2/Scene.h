//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <vector>
#include "Geometry.h"
#include "Color.h"
#include "Ray.h"
#include "Camera.h"
#include "ImagePlane.h"
#ifndef PROJECT_2_SCENE_H
#define PROJECT_2_SCENE_H


class Scene {
private:
    std::vector<Geometry *> scene;
    Camera camera;
    ImagePlane imagePlane;
    Light pointLight;

public:
    Scene();

    void mainRenderLoop();

    vzl::Color trace(Ray &r);

};


#endif //PROJECT_2_SCENE_H
