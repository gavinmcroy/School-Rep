//
// Created by Gavin McRoy on 9/12/2020.
//
#include "Point.h"
#include<iostream>

#ifndef LAB03_SOURCE_CLION_POINTMAP_H
#define LAB03_SOURCE_CLION_POINTMAP_H


class PointMap {
private:
    struct Node {
        Point point;
        Node *next;

        Node(Point p, Node *n) {
            //point = ;
            next = n;
        }

        Node() {
            Point p(0, 0);
            next = NULL;
        }
    };

};


#endif //LAB03_SOURCE_CLION_POINTMAP_H
