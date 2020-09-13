/*
   Created by Gavin McRoy on 9/9/2020.
*/
#include<fstream>
#include<limits>
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

        /* Load data into table */
        std::cout << "Loading Data..." << std::endl;
        while (file >> x >> y) {
            Point point(x, y);
            insert(point);
        }
        std::cout << "Loading Complete!" << std::endl;
    } else {
        std::cout << "File Not Found" << std::endl;
    }
}

//---[x,y] You hash x and y together to find the location to place the point object. That
//--- then is your head pointer. Some may hash together but 1000 is the best choice since
//--- theoretically every value could hash to exactly one point which is the most effecient possibility for a
//--- hash table
int PointMap::hashValue(double val) const {
    return (int) (val * b);
}

/* Inserts data into 2D hash table */
void PointMap::insert(Point point) {

    int hashX = hashValue(point.getXValue());
    int hashY = hashValue(point.getYValue());

    /* Initializes head pointer if null */
    if (table[hashX][hashY] == nullptr) {
        Node *newNode = new Node(point, nullptr);
        table[hashX][hashY] = newNode;
        return;
        /* Inserts elements in the front */
    } else if (table[hashX][hashY] != nullptr) {
        Node *newNode = new Node(point, table[hashX][hashY]);
        table[hashX][hashY] = newNode;
    }

}

/* TODO Implement */
void PointMap::calculateShortestDistance() const {
    double shortestDistance = std::numeric_limits<double>::max();
    double tmpDistance = 0.0;
    Point center = table[1][1]->point;

    //---Test Cell
    for (int x = 0; x < b; x += 2) {
        for (int y = 0; y < b; y += 2) {
            if ((x+1<1000 && y+1<1000) && (table[x + 1][y + 1] != nullptr)) {
                center = table[x + 1][y + 1]->point;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (table[i][j] == nullptr) {
                        continue;
                    }
                    if (table[i][j]->point == center) {
                        continue;
                    }
                    tmpDistance = Point::calcDistance(center, table[i][j]->point);
                    if (tmpDistance < shortestDistance) {
                        shortestDistance = tmpDistance;
                    }
                }
            }
        }

    }
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            if (table[i][j] == nullptr) {
//                continue;
//            }
//            if (table[i][j]->point == center) {
//                continue;
//            }
//            tmpDistance = Point::calcDistance(center, table[i][j]->point);
//            if (tmpDistance < shortestDistance) {
//                shortestDistance = tmpDistance;
//            }
//        }
//    }

    std::cout << "The shortest distance calculated is : " << shortestDistance << std::endl;

}

/* TODO Modified for debug */
void PointMap::printData() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] == nullptr) {
                continue;
            }
            std::cout << "X: " << (table[i][j])->point.getXValue()
                      << "    Y: " << (table[i][j])->point.getYValue() << std::endl;
        }
    }
}