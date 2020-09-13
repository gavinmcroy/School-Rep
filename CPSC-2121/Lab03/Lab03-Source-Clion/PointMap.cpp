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
            //std::cout<< x << " " <<y<<std::endl;
//            if(count==10){
//                break;
//            }
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
    int counter = 0;
    /* Breaks table in 3x3 squares and iterates through */

    for (int x = 0; x < b-1; x += 3) {
        for (int y = 0; y < b-1; y += 3) {
            /* Prevents going out of bounds */
            if ((x + 1 < 1000 && y + 1 < 1000) && (table[x + 1][y + 1] != nullptr)) {
                center = table[x + 1][y + 1]->point;
            }
            /* Iterate through 3x3 square and calculate shortest distance */
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    if (table[i][j] == nullptr) {
                        continue;
                    }
                    /* Check chained elements */
                    Node* tmp = table[i][j];
                        while(tmp!= nullptr){

                            /* Make sure center is not compared with itself */
                            if (tmp->point == center) {
                                tmp = tmp->next;
                                continue;
                            }
                            /* Calculate distance and check if it is smaller than current val */
                            tmpDistance = Point::calcDistance(center, tmp->point);
                            if (tmpDistance < shortestDistance) {
                                shortestDistance = tmpDistance;
                            }
                            tmp = tmp->next;
                        }
//                    if(table[i][j]->next!= nullptr){
//                        counter++;
//                    }
//
//                    /* Make sure center is not compared with itself */
//                    if (table[i][j]->point == center) {
//                        continue;
//                    }
//                    tmpDistance = Point::calcDistance(center, table[i][j]->point);
//                    if (tmpDistance < shortestDistance) {
//                        shortestDistance = tmpDistance;
//                    }
                }
            }
        }

    }

    std::cout<<counter<<std::endl;
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
    int count = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            Node* tmp = table[i][j];

            if (table[i][j] == nullptr) {
                count++;
                continue;
            }
//            std::cout << "X: " << (table[i][j])->point.getXValue()
//                      << "    Y: " << (table[i][j])->point.getYValue() << std::endl;
        }

    }
    std::cout<<count<<std::endl;
}