/*
   Created by Gavin McRoy on 9/9/2020.
*/
#include<iostream>
#include "Point.h"

#ifndef LAB03_SOURCE_CLION_POINTMAP_H
#define LAB03_SOURCE_CLION_POINTMAP_H


class PointMap {
public:
    struct Node {
        Point point;
        Node *next;

        Node(Point p, Node *n) {
            point = p;
            next = n;
        }

        Node(){
            next = nullptr;
        }
    };

    int b = 1000;
    Node *** table;
    std::ifstream file;

    int hashValue(double val) const;

public:
    PointMap();

    ~PointMap();

    void readFileIntoTable(const std::string &fileName);

    void insert(Point point);

    void calculateShortestDistance() const;

    void printData();

};


#endif //LAB03_SOURCE_CLION_POINTMAP_H
