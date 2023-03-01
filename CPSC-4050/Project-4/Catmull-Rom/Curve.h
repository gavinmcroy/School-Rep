#ifndef _H__CURVE_H
#define _H__CURVE_H

#include "Vector.h"
#include <vector>
#include <cassert>

class Curve {
public:
    Curve();

    virtual ~Curve();

protected:
    std::vector<Vector> nodes;
    std::vector<double> distances;
    std::vector<Vector> points;
    int step;

    void addNode(const Vector &node);

    virtual void pointAdd() = 0;

public:
    void addWayPoint(const Vector &point);

    Vector node(int i) const { return nodes[i]; }

    __attribute__((unused)) double lengthFromStartingPoint(int i) const { return distances[i]; }

    int nodeCount() const { return static_cast<int>(nodes.size()); }

    double totalLength() const {
        assert(!distances.empty());
        return distances[distances.size() - 1];
    }

    void setSteps(int steps) { step = steps; }
};

#endif