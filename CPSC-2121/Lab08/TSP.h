//
// Created by Gavin McRoy on 11/1/2020.
//

#ifndef LAB08_TSP_H
#define LAB08_TSP_H

#include <vector>
#include <string>

class TSP {
    const int N = 1000;

    struct Point {
        double x;
        double y;

        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }
    };

    std::vector<Point> cityLocations;
    std::vector<int> tour;

    double calculateTourDistance();

    void randomizeTour();

    void reverseTour(int start, int ending);

public:
    explicit TSP(const std::string &fileName);

    double calculateOptimalTour();
};


#endif //LAB08_TSP_H
