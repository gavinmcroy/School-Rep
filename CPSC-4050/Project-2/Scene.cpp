//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include "Scene.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"
#include "Triangle.h"
#include "Sphere.h"

Scene::Scene() : camera(vzl::Vector(0, 0, 0), vzl::Vector(0, 0, 1),
                        vzl::Vector(0, 1, 0), 90, 1.33),
                 imagePlane(1024, 768),
                 pointLight(vzl::Vector(-1, -1, 7), vzl::Color(1, 1, 1, 1)) {
    /* TODO build our geometric objects */
    /* Plane0 */
    scene.push_back(Plane(vzl::Vector(0, 2, 0), vzl::Vector(0, -1, 0),
                          vzl::Color(1, 1, 1, 1)));
    /* Plane1 */
    scene.push_back(Plane(vzl::Vector(0, -2, 0), vzl::Vector(0, 1, 0),
                          vzl::Color(1, 1, 1, 1)));
    /* Plane2 */
    scene.push_back(Plane(vzl::Vector(-2, 0, 0), vzl::Vector(1, 0, 0),
                          vzl::Color(1, 0, 0, 1)));
    /* Plane3 */
    scene.push_back(Plane(vzl::Vector(2, 0, 0), vzl::Vector(-1, 0, 0),
                          vzl::Color(0, 1, 0, 1)));
    /* Plane4 */
    scene.push_back(Plane(vzl::Vector(0, 0, 10), vzl::Vector(0, 0, -1),
                          vzl::Color(1, 1, 1, 1)));
    /* Triangle0 */
    scene.push_back(Triangle(vzl::Vector(-1.5, .6, 5), vzl::Vector(-1.8, .9, 5),
                             vzl::Vector(-1.7, .4, 5), vzl::Color(244.0 / 255.0, 102.0 / 255.0, 0, 1)));
    /* Triangle 1 */
    scene.push_back(Triangle(vzl::Vector(-1.8, .9, 5), vzl::Vector(-1.7, 0.4, 5),
                             vzl::Vector(1.1, 3.25, 3), vzl::Color(244.0 / 255.0, 102.0 / 255.0, 0, 1)));
    /* Triangle 2 */
    scene.push_back(Triangle(vzl::Vector(-1.7, .4, 5), vzl::Vector(1.1, 3.25, 3),
                             vzl::Vector(-1.5, .6, 5), vzl::Color(0, 245 / 255.0, 102.0 / 255.0, 1)));
    /* Triangle 3 */
    scene.push_back(Triangle(vzl::Vector(1.1,3.25,3),vzl::Vector(-1.5,.6,6.5),
                             vzl::Vector(-1.8,.9,5),vzl::Color(102.0/255.0,0,245.0/255.0,1)));
    /* Sphere */
    scene.push_back(Sphere(vzl::Vector(1.1,1.25,7),1.0,vzl::Color(.5,.5,1,1)));
    std::cout << "Scene generated" << std::endl;
}

vzl::Color Scene::trace(Ray &r) {
    /* Returns color that is computed by shade method of closest object. Black if no intersection*/
    return vzl::Color();
}
