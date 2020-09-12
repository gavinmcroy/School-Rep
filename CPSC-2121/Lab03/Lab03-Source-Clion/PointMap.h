/*
   Created by Gavin McRoy on 9/9/2020.
*/
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

    int b = 100;
    Node ***table;
    std::ifstream file;

    int hashValue(double val) const;

public:
    PointMap();

    ~PointMap();

    void readFileIntoTable(const std::string &fileName);

    void insert(Point point, int hash);

    void calculateShortestDistance();

};


#endif //LAB03_SOURCE_CLION_POINTMAP_H
