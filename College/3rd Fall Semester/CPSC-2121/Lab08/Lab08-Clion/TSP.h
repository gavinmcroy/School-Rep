//
// Created by Gavin McRoy on 11/1/2020.
//

#ifndef LAB08_TSP_H
#define LAB08_TSP_H

#include <vector>
#include <string>

class TSP {

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
    std::vector<int> optimalTour;
    double absoluteMin;

    double calculateTourDistance(std::vector<int> &t);

    double calculateTourWithPoints(unsigned int start, unsigned int ending);

    void randomizeTour(std::vector<int> &t);

    void reverseTour(unsigned int start, unsigned int ending, std::vector<int> &t);

public:
    explicit TSP(const std::string &fileName);

    double calculateOptimalTour();

    void outputTour();

};


#endif //LAB08_TSP_H
