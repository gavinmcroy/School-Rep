#include "Curve.h"

Curve::Curve()
        : step(100) {

}

void Curve::addWayPoint(const Vector &point) {
    points.push_back(point);
    pointAdd();
}


void Curve::addNode(const Vector &node) {
    nodes.push_back(node);


    if (nodes.size() == 1) {
        distances.push_back(0);
    } else {
        int new_node_index = nodes.size() - 1;
        double segmentDistance = (nodes[new_node_index] - nodes[new_node_index - 1]).magnitude();
        distances.push_back(segmentDistance + distances[new_node_index - 1]);
    }
}

Curve::~Curve() {

}
