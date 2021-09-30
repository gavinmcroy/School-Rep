//
// Created by Gavin Taylor Mcroy on 9/27/21.
//
#include <iostream>
#include <limits>
#include <OpenImageIO/imageio.h>
#include "Scene.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"
#include "Triangle.h"
#include "Sphere.h"

OIIO_NAMESPACE_USING

Scene::Scene() : camera(vzl::Vector(0, 0, 0), vzl::Vector(0, 0, 1),
                        vzl::Vector(0, 1, 0), 90, 1.33),
                 imagePlane(1024, 768),
                 pointLight(vzl::Vector(-1, -1, 7), vzl::Color(1, 1, 1, 1)) {
    /* TODO build our geometric objects */
    /* Plane0 */
//    scene.push_back(new Plane(vzl::Vector(0, 2, 0), vzl::Vector(0, -1, 0),
//                              vzl::Color(1, 1, 1, 1)));
//    /* Plane1 */
//    scene.push_back(new Plane(vzl::Vector(0, -2, 0), vzl::Vector(0, 1, 0),
//                              vzl::Color(1, 1, 1, 1)));
//    /* Plane2 */
//    scene.push_back(new Plane(vzl::Vector(-2, 0, 0), vzl::Vector(1, 0, 0),
//                              vzl::Color(1, 0, 0, 1)));
//    /* Plane3 */
//    scene.push_back(new Plane(vzl::Vector(2, 0, 0), vzl::Vector(-1, 0, 0),
//                              vzl::Color(0, 1, 0, 1)));
//    /* Plane4 */
//    scene.push_back(new Plane(vzl::Vector(0, 0, 10), vzl::Vector(0, 0, -1),
//                              vzl::Color(1, 1, 1, 1)));
    /* Triangle0 */
    scene.push_back(new Triangle(vzl::Vector(-1.5, .6, 5), vzl::Vector(-1.8, .9, 5),
                                 vzl::Vector(-1.7, .4, 5), vzl::Color(244.0 / 255.0, 102.0 / 255.0, 0, 1)));
//    /* Triangle 1 */
    scene.push_back(new Triangle(vzl::Vector(-1.8, .9, 5), vzl::Vector(-1.7, 0.4, 5),
                                 vzl::Vector(1.1, 3.25, 3), vzl::Color(244.0 / 255.0, 102.0 / 255.0, 0, 1)));
//    /* Triangle 2 */
    scene.push_back(new Triangle(vzl::Vector(-1.7, .4, 5), vzl::Vector(1.1, 3.25, 3),
                                 vzl::Vector(-1.5, .6, 5), vzl::Color(0, 245 / 255.0, 102.0 / 255.0, 1)));
//    /* Triangle 3 */
    scene.push_back(new Triangle(vzl::Vector(1.1, 3.25, 3), vzl::Vector(-1.5, .6, 6.5),
                                 vzl::Vector(-1.8, .9, 5), vzl::Color(102.0 / 255.0, 0, 245.0 / 255.0, 1)));
    /* Sphere */
//    scene.push_back(new Sphere(vzl::Vector(1.1, 1.25, 7), 1.0, vzl::Color(.5, .5, 1, 1)));
//    std::cout << "Scene generated" << std::endl;
}

void Scene::mainRenderLoop() {
    /* Cache references */
    double hFov = camera.getFov();
    double aspectRatio = camera.getAspectRatio();
    int nX = imagePlane.getNX();
    int nY = imagePlane.getNY();
    /* Vertical FOV is required to find y */
    double vFov = (2.0 * atan(((tan(hFov / 2.0))) / aspectRatio)) /* Double check formula */;
    for (int i = 0; i < imagePlane.getNX(); i++) {
        for (int j = 0; j < imagePlane.getNY(); j++) {
            /* d_hat calculation (aka ray direction of pixel) */
            double x = (-1.0 + (2.0 * i) / (nX - 1.0)) * tan(hFov / 2.0);
            double y = (-1.0 + (2.0 * j) / (nY - 1.0)) * tan(vFov / 2.0);
            vzl::Vector dHat = camera.view(x, y);

            Ray ray(camera.getPosition(), dHat);
            imagePlane.set(i, j, trace(ray));
        }
    }
}

/* Returns color that is computed by shade method of closest object. Black if no intersection*/
vzl::Color Scene::trace(Ray &r) {

    /* Remember which index the geometry had the shortest intersection distance */
    bool intersection = false;
    int index = 0;
    double minIntersectionD = std::numeric_limits<double>::max();
    for (int z = 0; z < scene.size(); z++) {
        double tempIntersection = scene[z]->intersection(r);
        /* no intersection */
        if (tempIntersection < 0) {
            continue;
        }
        if (tempIntersection < minIntersectionD) {
            minIntersectionD = tempIntersection;
            index = z;
            intersection = true;
        }
    }

    /* if no intersection return black */
    if (!intersection) {
        return vzl::Color(1, 1, 1, 1);
    }

    /* TODO you calculate ray + intersection point distance returned * direction */
    return scene[index]->shade(r.getPosition() + minIntersectionD * r.getDirection(), pointLight);
}

void Scene::outputRender() {
    /* TEMP CODE */
//    std::string inputName = "in.jpeg";
//    auto input = ImageInput::open(inputName);
//    ImageSpec imageSpec1 = input->spec();
//    auto *inputImageData = new unsigned char[imageSpec1.width * imageSpec1.height * imageSpec1.nchannels];
//    input->read_image(TypeDesc::UINT8, inputImageData);
//    input->close();
    /* TEMP CODE */


    std::string fileOutputName = "out.png";
    int numChannels = 3;
    ImageSpec imageSpec = ImageSpec(imagePlane.getNX(), imagePlane.getNY(), numChannels, TypeDesc::FLOAT);
    auto output = ImageOutput::create("out.png");
    output->open(fileOutputName, imageSpec);

    /* Basically take our color array and copy into a unsigned char array cause openImageIO likes it */
    auto *imageData = new unsigned char[imagePlane.getNX() * imagePlane.getNY() * numChannels];

    for (int i = 0; i < imagePlane.getNX(); i++) {
        for (int j = 0; j < imagePlane.getNY(); j++) {
            for (int x = 0; x < numChannels; x++) {
                /* nifty index formula for 1D array */
                int address = (j * imagePlane.getNX() + i) * numChannels;
                /* R */
                if (x == 0) {
                    imageData[address + x] =
                            (unsigned char) imagePlane.get(i, j).red() * 255; // inputImageData[address + x];
                }/* G */
                else if (x == 1) {
                    imageData[address + x] =
                            (unsigned char) imagePlane.get(i, j).green() * 255; //inputImageData[address + x];
                } /* B */
                else if (x == 2) {
                    imageData[address + x] =
                            (unsigned char) imagePlane.get(i, j).blue() * 255; //inputImageData[address + x];
                }
            }
        }
    }
    output->write_image(TypeDesc::UINT8, imageData);
    output->close();

}
