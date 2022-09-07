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

/* Destructor */
PointMap::~PointMap() {
    for (int i = 0; i < b; i++) {
        delete[] table[i];
    }
    delete[] table;
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
    int count = 0;

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;

        /* Load data into table */
        std::cout << "Loading Data..." << std::endl;
        while (file >> x >> y) {
            Point point(x, y);
            insert(point);
            count++;
        }
        std::cout << "Loading Complete!" << std::endl;
    } else {
        std::cout << "File Not Found" << std::endl;
    }
}

//---[x,y] You hash x and y together to find the location to place the point object. That
//--- then is your head pointer. Some may hash together but 1000 is the best choice since
//--- theoretically every value could hash to exactly one point which is the most efficient possibility for a
//--- hash table as 1000*1000 = 1 million
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
/* Calculate shortest distance of one million points */
void PointMap::calculateShortestDistance() const {
    double shortestDistance = std::numeric_limits<double>::max();
    double tmpDistance = std::numeric_limits<double>::max();
//    Point center = table[1][1]->point;

    for (int x = 0; x < b - 1; x++) {
        for (int y = 0; y < b - 1; y++) {
            /* Protective bounds on array */
            if (x - 1 >= 0 && x + 1 < b && y - 1 >= 0 && y + 1 < b) {
                /* Make sure the center element is not null */
                if (table[x][y] == nullptr) {
                    continue;
                }
                /* Compare center element to surrounding 3x3 area. x-1 is making it one left x+1 is making it right one
                 * y-1 is making it down one and y+1 is making it up 1 forming a 3x3 square */
                for (int i = x - 1; i <= x + 1; i++) {
                    for (int j = y - 1; j <= y + 1; j++) {
                        /* Make sure surrounding square is not null */
                        if (table[i][j] == nullptr) {
                            continue;
                        }
                        /* Check chained elements and compare with center value */
                        for (Node *tmp = table[i][j]; tmp != nullptr; tmp = tmp->next) {
                            /* Make sure center is not compared with itself [X][Y] IS CENTER */
                            if (tmp->point == table[x][y]->point) {
                                continue;
                            }
                            tmpDistance = Point::calcDistance(table[x][y]->point, tmp->point);
                            if (tmpDistance < shortestDistance) {
                                shortestDistance = tmpDistance;
                            }
                        }
                    }
                }


            }
        }
    }
    std::cout << "The shortest distance calculated is : " << shortestDistance << std::endl;

}

/* TODO Modified for debug usage only not intended to function properly */
//void PointMap::printData() {
//    int count = 0;
//    for (int i = 0; i < b; i++) {
//        for (int j = 0; j < b; j++) {
//            Node *tmp = table[i][j];
//
//            if (table[i][j] == nullptr) {
//                count++;
//                continue;
//            }
////            std::cout << "X: " << (table[i][j])->point.getXValue()
////                      << "    Y: " << (table[i][j])->point.getYValue() << std::endl;
//        }
//
//    }
//    std::cout << count << std::endl;
//}