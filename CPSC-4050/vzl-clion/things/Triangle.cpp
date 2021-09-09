//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#include "Triangle.h"

vzl::Triangle::Triangle() {
    std::vector<Vector> face;
    int pPad = 1;
    int nPad = -1;
    bool debug = true;

    /* This is what actually draws the faces of the 3D triangle */
    /* Randomization comes from the parameter passed to constructor */
    /**** FIRST TRIANGLE RENDERED MUST HAVE A DISTANCE OF 1-2 BETWEEN EACH EDGE *****/
/****************************************************************************/
    Vector vector1(drand48(), pPad + drand48(), pPad + drand48());
    Vector vector2(nPad * (pPad + drand48()), nPad * (pPad + drand48()), nPad * (pPad + drand48()));
    Vector vector3(pPad + drand48(), nPad * (pPad + drand48()), pPad + drand48());
    vector1.normalize();
    vector2.normalize();
    vector3.normalize();
    face.push_back(vector1);
    face.push_back(vector2);
    face.push_back(vector3);

    /* DEBUG INFORMATION */

        std::cout << "Data X , Y , Z " << face.at(0).X() << " " << face.at(0).Y() << face.at(0).Z() << std::endl;
        std::cout << "Data X , Y , Z " << face.at(1).X() << " " << face.at(1).Y() << face.at(1).Z() << std::endl;
        std::cout << "Data X , Y , Z " << face.at(2).X() << " " << face.at(2).Y() << face.at(2).Z() << std::endl;
        std::cout << "Edge 1 Length" << length(face.at(0), face.at(1)) << std::endl;
        std::cout << "Edge 2 Length" << length(face.at(0), face.at(2)) << std::endl;
        std::cout << "Edge 3 Length" << length(face.at(1), face.at(2)) << std::endl;
    walls.push_back(face);
    wall_colors.emplace_back(drand48(), drand48(), drand48(), 0);
    face.clear();

    /**** SECOND TRIANGLE RENDERED MUST USE 2 VERTEX + RANDOM *****/
/********************************************************************************/
//    Vector vector4 = Vector(pPad + drand48(), nPad * (pPad * drand48()), pPad + drand48());
//    vector4.normalize();
//
//    face.push_back(vector1);
//    face.push_back(vector2);
//    face.push_back(vector4);
//
////    face.push_back(llc);
////    face.push_back(Vector(llc[0], llc[1], urc[2]));
////    face.push_back(Vector(urc[0], llc[1], urc[2]));
////    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    walls.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();


    /**** THIRD TRIANGLE RENDERED MUST USE 2 VERTEX + RANDOM *****/
/****************************************************************************/
    /* Bottom left faded green */
//    Vector vector5 = vector4;
//    /* Bottom left neon green */
//    Vector vector6 = vector3;
//    /* Bottom right faded green*/
//    Vector vector7 = vector2;
////    face.push_back(vector5);
////    face.push_back(vector6);
////    face.push_back(vector7);
////    face.push_back(llc);
////    face.push_back(Vector(llc[0], urc[1], llc[2]));
////    face.push_back(Vector(urc[0], urc[1], llc[2]));
////    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    walls.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();

/********************************************************************************/

// Faces based on urc


/*********************************************************************************/

//    face.push_back(urc);
//    face.push_back(Vector(urc[0], urc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], urc[2]));
//    walls.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();
}

vzl::Triangle::~Triangle() = default;

const std::vector<vzl::Vector> &vzl::Triangle::triangle_wall(int index) const {
    return walls[index];;
}

const vzl::Color &vzl::Triangle::wall_color(int index) const {
    return wall_colors[index];;
}

const std::vector<vzl::Vector> &vzl::Triangle::threeEdgeVector() const {
    return edgeVectors;
}

const double vzl::Triangle::unitNormal() const {
    return 0;
}

const double vzl::Triangle::triangleArea() const {
    return 0;
}

const double vzl::Triangle::aspectRatio() const {
    return 0;
}

double vzl::Triangle::length(const Vector &v1, const Vector &v2) {
    return sqrt(pow((v1.X() - v2.X()), 2) + pow((v1.Y() - v2.Y()), 2) +
                pow((v1.X() - v2.X()), 2));
}
