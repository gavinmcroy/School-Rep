/*
   Created by Gavin McRoy on 9/9/2020.
*/
#include <cmath>
#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

double Point::getXValue() {
    return x;
}

double Point::getYValue() {
    return y;
}


double Point::calcDistance(Point point1, Point point2) {
    return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}

Point &Point::operator=(const Point &rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

bool Point::operator==(const Point &rhs) {
    if ((this->x == rhs.x) && ((this->y) == rhs.y)) {
        return true;
    } else
        return false;
}