//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#include "Triangle.h"

vzl::Triangle::Triangle() {
    std::vector<Vector> face;
    int pPad = 1;
    int nPad = -1;

    /**** FIRST TRIANGLE RENDERED MUST HAVE A DISTANCE OF 1-2 BETWEEN EACH EDGE *****/
    Vector vector1(drand48(), pPad + drand48(), pPad + drand48());
    Vector vector2(nPad * (pPad + drand48()), nPad * (pPad + drand48()), nPad * (pPad + drand48()));
    Vector vector3(pPad + drand48(), nPad * (pPad + drand48()), pPad + drand48());
    vector1.normalize();
    vector2.normalize();
    vector3.normalize();
    face.push_back(vector1);
    face.push_back(vector2);
    face.push_back(vector3);

    triangleColor.emplace_back(drand48(), drand48(), drand48(), 0);

    /* Keep track of vectors */
    for (const auto &i : face) {
        triangleCords.push_back(i);
    }

  //  debugInformation();
    setEdgeVectors();
    setTriangleArea();
    setAspectRatio();
    setNormalVector();
    face.clear();
}

/* This condition is assuming the no param constructor has already been created.
 * Inputted vertex's are assumed to have been normalized */
vzl::Triangle::Triangle(const vzl::Vector &vertex1, const vzl::Vector &vertex2) {
    /* Triangle generated must use two previous vertices */
    std::cout<<"Style 2 created"<<std::endl;
    std::vector<Vector> face;
    int pPad = 1;
    int nPad = -1;
    Vector vector3(pPad + drand48(), nPad * (pPad + drand48()), pPad + drand48());
    vector3.normalize();
    face.push_back(vertex1);
    face.push_back(vertex2);
    face.push_back(vector3);

    triangleColor.emplace_back(drand48(), drand48(), drand48(), 0);
    for (const auto &i : face) {
        triangleCords.push_back(i);
    }

   // debugInformation();
    setEdgeVectors();
    setTriangleArea();
    setAspectRatio();
    setNormalVector();
    face.clear();
}

vzl::Triangle::~Triangle() = default;

void vzl::Triangle::setNormalVector() {
    double x = ((edgeVectors[0].Y() * edgeVectors[1].Z()) -
                (edgeVectors[0].Z() * edgeVectors[1].Y()));
    double y = ((edgeVectors[0].Z() * edgeVectors[1].X()) -
                (edgeVectors[0].X() * edgeVectors[1].Z()));
    double z = ((edgeVectors[0].X() * edgeVectors[1].Y()) -
                (edgeVectors[0].Y()) * edgeVectors[1].X());
    unit_normal.set(x, y, z);
    unit_normal.normalize();

    std::cout << "Normal vector " << unit_normal.X() << " " << unit_normal.Y() << " "
              << unit_normal.Z() << std::endl;
}

void vzl::Triangle::setAspectRatio() {
    /* Aspect ratio code */
    double v1v2Length = length(triangleCords[0], triangleCords[1]);
    double v1v3Length = length(triangleCords[0], triangleCords[2]);
    double v2v3Length = length(triangleCords[1], triangleCords[2]);
    double max = 0.0;
    double min = 0.0;
    /* Find max */
    if (v2v3Length > v1v3Length && v2v3Length > v1v2Length) {
        max = v2v3Length;
    } else if (v1v3Length > v2v3Length && v2v3Length > v1v2Length) {
        max = v1v3Length;
    } else {
        max = v1v2Length;
    }

    /* Find min */
    if (v2v3Length < v1v3Length && v2v3Length < v1v2Length) {
        min = v2v3Length;
    } else if (v1v3Length < v2v3Length && v2v3Length < v1v2Length) {
        min = v1v3Length;
    } else {
        min = v1v2Length;
    }
    aspect_ratio = max / min;
    std::cout << "Aspect ratio " << aspect_ratio << std::endl;
    /* Aspect ratio code */
}

void vzl::Triangle::setTriangleArea() {
    /* Calculating triangle area */
    /* Find cross product (v1v2 v1v3) */
    Vector crossProduct = edgeVectors[0] ^ edgeVectors[1];
    area = .5 * crossProduct.magnitude();
    std::cout << "Triangle area " << triangleArea() << std::endl;
    /* Calculating triangle area */
}

void vzl::Triangle::setEdgeVectors() {
    //V1 V2
    Vector v1v2 = triangleCords[1] - triangleCords[0];
    //V1 V3
    Vector v1v3 = triangleCords[2] - triangleCords[0];
    //V2 V3
    Vector v2v3 = triangleCords[2] - triangleCords[1];
    edgeVectors.push_back(v1v2);
    edgeVectors.push_back(v1v3);
    edgeVectors.push_back(v2v3);
}

void vzl::Triangle::debugInformation() {
    /* DEBUG INFORMATION */
    double v1v2Length = length(triangleCords[0], triangleCords[1]);
    double v1v3Length = length(triangleCords[0], triangleCords[2]);
    double v2v3Length = length(triangleCords[1], triangleCords[2]);
    std::cout << "Data X , Y , Z " << triangleCords[0].X() << " " << triangleCords[0].Y()
              << triangleCords[0].Z() << std::endl;
    std::cout << "Data X , Y , Z " << triangleCords[1].X() << " " << triangleCords[1].Y()
              << triangleCords[1].Z() << std::endl;
    std::cout << "Data X , Y , Z " << triangleCords[2].X() << " " << triangleCords[2].Y()
              << triangleCords[2].Z() << std::endl;
    std::cout << "Edge 1 Length " << v1v2Length << std::endl;
    std::cout << "Edge 2 Length " << v1v3Length << std::endl;
    std::cout << "Edge 3 Length " << v2v3Length << std::endl;
}


const vzl::Color &vzl::Triangle::wall_color(int index) const {
    return triangleColor[index];
}

const vzl::Vector &vzl::Triangle::threeEdgeVector(int index) const {
    return edgeVectors[index];
}

const vzl::Vector vzl::Triangle::unitNormal() const {
    return unit_normal;
}

const double vzl::Triangle::triangleArea() const {
    return area;
}

const double vzl::Triangle::aspectRatio() const {
    return aspect_ratio;
}

double vzl::Triangle::length(const Vector &v1, const Vector &v2) {
    return sqrt(pow((v1.X() - v2.X()), 2) + pow((v1.Y() - v2.Y()), 2) +
                pow((v1.Z() - v2.Z()), 2));
}


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
//    triangleCords.push_back(face);
//    triangleColor.push_back(Color(drand48(), drand48(), drand48(), 0));
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
//    triangleCords.push_back(face);
//    triangleColor.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();

/********************************************************************************/

// Faces based on urc


/*********************************************************************************/

//    face.push_back(urc);
//    face.push_back(Vector(urc[0], urc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], urc[2]));
//    triangleCords.push_back(face);
//    triangleColor.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();

/* Aspect Ratio. Find inRadius*/
/* max length / min */
//    double perimeter = edgeLength1 + edgeLength2 + edgeLength3;
//    double semiPerimeter = .5 * perimeter;
//    double inRadius = area / semiPerimeter;
//    double circumRadius = (edgeLength1 * edgeLength2 * edgeLength3) / (4 * inRadius * semiPerimeter);
//    double aspectRatio = circumRadius / (2 * inRadius);
//    std::cout << "PERIMETER " << perimeter << std::endl;
//    std::cout << "inRadius " << inRadius << std::endl;
//    std::cout << "circumRadius " << circumRadius << std::endl;
//    std::cout << "Aspect ratio " << aspectRatio << std::endl;