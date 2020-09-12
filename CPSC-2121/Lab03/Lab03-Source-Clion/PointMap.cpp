/*
   Created by Gavin McRoy on 9/9/2020.
*/
#include<fstream>
#include "PointMap.h"

PointMap::PointMap() {
    /* Allocate memory for the table */
    table = new Node **[b];
    for (int i = 0; i < b; i++)
        table[i] = new Node *[b];

    /* Initialize all head pointers to NULL */
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            table[i][j] = nullptr;
        }
    }
}

/* TODO Implement */
PointMap::~PointMap() {

}

/*** [THOUGHTS]
 * So creating b to be 1000 means for one million data elements there should be exactly
 * one data value per cell
 * Any value lower than this and the values will collide?
 * Any value higher than this and there is wasted space?
 * How do you hash values x,y together? Or do you not?
 *
 */

void PointMap::readFileIntoTable(const std::string &fileName) {
    file.open(fileName, std::ios::in);
    double x, y;

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;

        /* TODO Implement */
        while (file >> x >> y) {
            std::cout << "X: " << x << " Y: " << y << std::endl;
            /*** [TEST CODE]
            int h = hashValue(x);
            Point point(x,y);
            insert(point, h);
            */
        }
    } else {
        std::cout << "File Not Found" << std::endl;
    }
}

/* TODO How does a single hash value work for 2D elements? */
int PointMap::hashValue(double val) const {
    return (int) (val * b) - 1;
}

/* TODO Implement */
void PointMap::insert(Point point, int hash) {

}

/* TODO Implement */
void PointMap::calculateShortestDistance() {

}