//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#ifndef VZL_CLION_TRIANGLE_H
#define VZL_CLION_TRIANGLE_H

#include <vector>
#include <iostream>
#include "../include/Color.h"
#include "../include/Vector.h"

namespace vzl {

    class Triangle {
    private:
        double area;
        double aspect_ratio;

        Vector unit_normal;

        /*0 = v1v2 1 = v1v3 2 = v2v3 */
        std::vector<Vector> edgeVectors;

        std::vector<Color> triangleColor;

        void setNormalVector();

        void setAspectRatio();

        void setTriangleArea();

        void setEdgeVectors();

        void debugInformation();

        double length(const Vector &v1, const Vector &v2);

    public:
        Triangle();

        Triangle(const Vector &vertex1, const Vector &vertex2);

        ~Triangle();

        const Color &wall_color(int index) const;

        const Vector &threeEdgeVector(int index) const;

        const vzl::Vector unitNormal() const;

        const double triangleArea() const;

        const double aspectRatio() const;

        std::vector<Vector> triangleCords;

    };

}
#endif //VZL_CLION_TRIANGLE_H
