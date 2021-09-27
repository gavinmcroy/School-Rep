//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include "Scene.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"

Scene::Scene() : camera(vzl::Vector(0, 0, 0), vzl::Vector(0, 0, 1),
                        vzl::Vector(0, 1, 0), 90, 1.33),
                 imagePlane(1024, 768),
                 pointLight(vzl::Vector(-1, -1, 7), vzl::Color(1, 1, 1, 1)) {
    /* TODO build our geometric objects */
    scene.push_back(Plane(vzl::Vector(0, 2, 0), vzl::Vector(0, -1, 0),
                          vzl::Color(1, 1, 1, 1)));

    std::cout << "Scene generated" << std::endl;
}

vzl::Color Scene::trace(Ray &r) {
    /* Returns color that is computed by shade method of closest object. Black if no intersection*/
    return vzl::Color();
}
