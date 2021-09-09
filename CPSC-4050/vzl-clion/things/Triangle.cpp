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

    /* DEBUG INFORMATION */
    double edgeLength1 = length(face.at(0), face.at(1));
    double edgeLength2 = length(face.at(0), face.at(2));
    double edgeLength3 = length(face.at(1), face.at(2));
    std::cout << "Data X , Y , Z " << face.at(0).X() << " " << face.at(0).Y() << face.at(0).Z() << std::endl;
    std::cout << "Data X , Y , Z " << face.at(1).X() << " " << face.at(1).Y() << face.at(1).Z() << std::endl;
    std::cout << "Data X , Y , Z " << face.at(2).X() << " " << face.at(2).Y() << face.at(2).Z() << std::endl;
    std::cout << "Edge 1 Length " << edgeLength1 << std::endl;
    std::cout << "Edge 2 Length " << edgeLength2 << std::endl;
    std::cout << "Edge 3 Length " << edgeLength3 << std::endl;
    vertex.push_back(face);
    wall_colors.emplace_back(drand48(), drand48(), drand48(), 0);

    //V1 V2
    Vector v1v2 = vector2 - vector1;
    //V1 V3
    Vector v1v3 = vector3 - vector1;
    //V2 V3
    Vector v2v3 = vector3 - vector2;

    edgeVectors.push_back(v1v2);
    edgeVectors.push_back(v1v3);
    edgeVectors.push_back(v2v3);


    /* Calculating triangle area */
    /* Find cross product. 1/2 * magnitude(cross product) */
    Vector crossProduct = v1v2 ^ v1v3;
    area = .5 * crossProduct.magnitude();
    std::cout << "Triangle area " << triangleArea() << std::endl;
    /* Calculating triangle area */

    /* Aspect ratio code */
    double max;
    double min;
    /* Find max */
    if(edgeLength3 > edgeLength2 && edgeLength3 > edgeLength1){
        max = edgeLength3;
    }else if(edgeLength2 > edgeLength3 && edgeLength3 > edgeLength1){
        max = edgeLength2;
    }else{
        max = edgeLength1;
    }

    /* Find min */
    if(edgeLength3 < edgeLength2 && edgeLength3 < edgeLength1){
        min = edgeLength3;
    }else if(edgeLength2 < edgeLength3 && edgeLength3 < edgeLength1){
        min = edgeLength2;
    }else{
        min = edgeLength1;
    }
    aspect_ratio = max / min;
    std::cout<<"Aspect ratio "<<aspect_ratio<<std::endl;
    /* Aspect ratio code */

    /* Find and set the normal vector */
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
    face.clear();
}

vzl::Triangle::~Triangle() = default;

const std::vector<vzl::Vector> &vzl::Triangle::triangle_wall(int index) const {
    return vertex[index];;
}

const vzl::Color &vzl::Triangle::wall_color(int index) const {
    return wall_colors[index];;
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
//    vertex.push_back(face);
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
//    vertex.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();

/********************************************************************************/

// Faces based on urc


/*********************************************************************************/

//    face.push_back(urc);
//    face.push_back(Vector(urc[0], urc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], urc[2]));
//    vertex.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
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