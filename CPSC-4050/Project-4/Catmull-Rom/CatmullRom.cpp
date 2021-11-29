#include "CatmullRom.h"
#include <iostream>

CatmullRom::CatmullRom()
        : Curve() {

}

void CatmullRom::pointAdd() {
    const int MIN_SIZE = 4;
    if (points.size() < MIN_SIZE) {
        return;
    }

    int new_control_point_index = points.size() - 1;
    int pt = new_control_point_index - 2;
    for (int i = 0; i <= step; i++) {
        double u = (double) i / (double) step;

        addNode(interpolate(u, points[pt - 1], points[pt], points[pt + 1], points[pt + 2]));
    }
}

Vector CatmullRom::interpolate(double u, const Vector &P0, const Vector &P1, const Vector &P2, const Vector &P3) {
    Vector point;
    /* -1 is more of a absolute function concept */
    point = u * u * u * ((-1) * P0 + 3 * P1 - 3 * P2 + P3) / 2;
    point += u * u * (2 * P0 - 5 * P1 + 4 * P2 - P3) / 2;
    point += u * ((-1) * P0 + P2) / 2;
    point += P1;

    return point;
}

CatmullRom::~CatmullRom() {

}

