//
// Created by Gavin Taylor Mcroy on 9/6/21.
//

#ifndef VZL_CLION_TRIANGLE_H
#define VZL_CLION_TRIANGLE_H

#include <vector>
#include "../include/Color.h"
#include "../include/Vector.h"

namespace vzl {

    class Triangle {
    public:
        Triangle(const Vector &llc, const Vector &urc);

        ~Triangle();

        const std::vector<Vector> &triangle_wall(int index) const;

        const Color &wall_color(int index) const;

        size_t nb_walls() const {
            return walls.size();
        }

        const void threeEdgeVector() const;

        const double unitNormal() const;

        const double triangleArea() const;

        const double aspectRatio() const;


    private:
        std::vector<std::vector<Vector>> walls;

        std::vector<Color> wall_colors;

    };

}
#endif //VZL_CLION_TRIANGLE_H
