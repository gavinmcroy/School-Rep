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
    public:
        Triangle();

        ~Triangle();

        const std::vector<Vector> &triangle_wall(int index) const;

        const Color &wall_color(int index) const;

        size_t nb_walls() const {
            return vertex.size();
        }

        const Vector &threeEdgeVector(int index) const;

        const vzl::Vector unitNormal() const;

        const double triangleArea() const;

        const double aspectRatio() const;

        std::vector<std::vector<Vector>> vertex;


    private:
        double area;
        double aspect_ratio;

        Vector unit_normal;

        std::vector<Vector> edgeVectors;

        std::vector<Color> wall_colors;


        double length(const Vector &v1, const Vector &v2);

    };

}
#endif //VZL_CLION_TRIANGLE_H
