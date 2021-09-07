//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#include "Triangle.h"

vzl::Triangle::Triangle(const vzl::Vector &llc, const vzl::Vector &urc) {
    std::vector<Vector> face;

    /* This is what actually draws the faces of the 3D triangle */
    /* Randomization comes from the parameter passed to constructor */
/****************************************************************************/
//    face.push_back(llc);
    face.push_back(Vector(llc[0], llc[1], urc[2]));
    face.push_back(Vector(llc[0], urc[1], urc[2]));
    face.push_back(Vector(llc[0], urc[1], llc[2]));

    walls.push_back(face);
    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
    face.clear();

/********************************************************************************/


//    face.push_back(llc);
//    face.push_back(Vector(llc[0], llc[1], urc[2]));
//    face.push_back(Vector(urc[0], llc[1], urc[2]));
//    face.push_back(Vector(urc[0], llc[1], llc[2]));
//    walls.push_back(face);
//    wall_colors.push_back(Color(drand48(), drand48(), drand48(), 0));
//    face.clear();


/****************************************************************************/

//    face.push_back(llc);
//    face.push_back(Vector(llc[0], urc[1], llc[2]));
//    face.push_back(Vector(urc[0], urc[1], llc[2]));
//    face.push_back(Vector(urc[0], llc[1], llc[2]));
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

const void vzl::Triangle::threeEdgeVector() const {
    return;
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
