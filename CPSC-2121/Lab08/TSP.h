//
// Created by Gavin McRoy on 11/1/2020.
//

#ifndef LAB08_TSP_H
#define LAB08_TSP_H
#include <vector>

class TSP {

    struct Point{
        double x;
        double y;
        Point(double x , double y){
            this->x = x;
            this->y = y;
        }
    };

    std::vector<Point> cityLocations;
    std::vector<int> tour;
public:
    TSP();


};


#endif //LAB08_TSP_H
