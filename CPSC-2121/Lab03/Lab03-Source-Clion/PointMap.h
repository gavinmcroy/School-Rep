//
// Created by Gavin McRoy on 9/12/2020.
//
#include<iostream>
#include "Point.h"

#ifndef LAB03_SOURCE_CLION_POINTMAP_H
#define LAB03_SOURCE_CLION_POINTMAP_H


class PointMap {
private:
    struct Node {
        Point point;
        Node *next;

        Node(Point p, Node *n) {
            point = p;
            next = n;
        }
    };

    int b = 1000;
    Node ***table;
    std::ifstream file;

    int hashValue(int val);

public:
    PointMap();

};


#endif //LAB03_SOURCE_CLION_POINTMAP_H
