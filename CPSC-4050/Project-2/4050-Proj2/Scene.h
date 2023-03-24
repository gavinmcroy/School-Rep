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


OIIO_NAMESPACE_USING

class Scene {
private:
    std::vector<Geometry *> scene;
    Camera camera;
    ImagePlane imagePlane;
    Light pointLight;

    vzl::Color trace(Ray &r);

public:
    Scene();

    void mainRenderLoop();

    void outputRender();

};


#endif //PROJECT_2_SCENE_H
