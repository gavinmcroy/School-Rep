//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#include "Triangle.h"

vzl::Triangle::Triangle() {
    /* First triangle rendered must have a distance of 1-2 between each point */
    Vector vector1(drand48(), drand48(), drand48());
    Vector vector2(drand48(), -1 * drand48(), drand48());
    Vector vector3(-1 * drand48(), -1 * drand48(), -1 * drand48());

    /* Bruteforce method for generating triangles of required length if previous vectors
     * fail to satisfy requirement */
    double v1v2Length = length(vector1, vector2);
    double v1v3Length = length(vector1, vector3);
    double v2v3Length = length(vector2, vector3);
    while ((v1v2Length > MAX_LENGTH || v1v2Length < MIN_LENGTH) ||
           (v1v3Length > MAX_LENGTH || v1v3Length < MIN_LENGTH) ||
           (v2v3Length > MAX_LENGTH || v2v3Length < MIN_LENGTH)) {
        vector1 = Vector(drand48(), drand48(), drand48());
        vector2 = Vector(drand48(), drand48(), drand48());
        vector3 = Vector(drand48(), drand48(), drand48());
        v1v2Length = length(vector1, vector2);
        v1v3Length = length(vector1, vector3);
        v2v3Length = length(vector2, vector3);
    }

    /* Save coordinates */
    triangleCords.push_back(vector1);
    triangleCords.push_back(vector2);
    triangleCords.push_back(vector3);
    triangleColor.emplace_back(drand48(), drand48(), drand48(), 0);

    /* Init */
    setEdgeVectors();
    setTriangleArea();
    setAspectRatio();
    setNormalVector();
    debugInformation();
}

/* This condition is assuming the no param constructor has already been created. */
vzl::Triangle::Triangle(const vzl::Vector &vertex1, const vzl::Vector &vertex2) {

    /* Triangle generated must use two previous vertices. We are picking one random vert. */
    Vector vector3(drand48(), drand48(), drand48());

    /* Search in a bruteforce manner for a vector that satisfies the length requirements if
     * randomly generated vector does not satisfy */
    int x = 1;
    double v1v3Length = length(vertex1, vector3);
    double v2v3Length = length(vertex2, vector3);
    while ((v1v3Length > MAX_LENGTH || v1v3Length < MIN_LENGTH) ||
           (v2v3Length > MAX_LENGTH || v2v3Length < MIN_LENGTH)) {
        vector3 = Vector(x * drand48(), x * drand48(), x * drand48());
        v1v3Length = length(vertex1, vector3);
        v2v3Length = length(vertex2, vector3);
        x *= -1;
    }

    /* Save our coordinates */
    triangleCords.push_back(vertex1);
    triangleCords.push_back(vertex2);
    triangleCords.push_back(vector3);
    triangleColor.emplace_back(drand48(), drand48(), drand48(), 0);

    /* Init */
    setEdgeVectors();
    setTriangleArea();
    setAspectRatio();
    setNormalVector();
    debugInformation();
}

vzl::Triangle::~Triangle() = default;

void vzl::Triangle::setNormalVector() {
    int v1v2 = 0;
    int v1v3 = 1;
    double x = ((edgeVectors[v1v2].Y() * edgeVectors[v1v3].Z()) -
                (edgeVectors[v1v2].Z() * edgeVectors[v1v3].Y()));
    double y = ((edgeVectors[v1v2].Z() * edgeVectors[v1v3].X()) -
                (edgeVectors[v1v2].X() * edgeVectors[v1v3].Z()));
    double z = ((edgeVectors[v1v2].X() * edgeVectors[v1v3].Y()) -
                (edgeVectors[v1v2].Y()) * edgeVectors[v1v3].X());
    unit_normal.set(x, y, z);
    unit_normal.normalize();
}

void vzl::Triangle::setAspectRatio() {
    /* v1 = 0, v2 = 1, v3 = 2 */
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
}

void vzl::Triangle::setTriangleArea() {
    /* Find cross product (v1v2 v1v3) */
    Vector crossProduct = edgeVectors[0] ^ edgeVectors[1];
    area = .5 * crossProduct.magnitude();
}

void vzl::Triangle::setEdgeVectors() {
    /* V1 V2 */
    Vector v1v2 = triangleCords[1] - triangleCords[0];
    /* V1 V3 */
    Vector v1v3 = triangleCords[2] - triangleCords[0];
    /* V2 V3 */
    Vector v2v3 = triangleCords[2] - triangleCords[1];
    edgeVectors.push_back(v1v2);
    edgeVectors.push_back(v1v3);
    edgeVectors.push_back(v2v3);
}

void vzl::Triangle::debugInformation() {
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
    std::cout << "Aspect ratio " << aspect_ratio << std::endl;
    std::cout << "Triangle area " << triangleArea() << std::endl;
    std::cout << "Normal vector " << unit_normal.X() << " " << unit_normal.Y() << " "
              << unit_normal.Z() << std::endl;

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