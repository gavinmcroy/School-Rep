/*
   Created by Gavin McRoy on 9/9/2020.
*/

#ifndef LAB03_SOURCE_CLION_POINT_H
#define LAB03_SOURCE_CLION_POINT_H


class Point {

private:
    double x;
    double y;

public:
    Point(double x, double y);

    Point();

    double getXValue();

    double getYValue();

    static double calcDistance(Point point1, Point point2);

    Point &operator=(const Point &rhs);

    bool operator==(const Point &rhs);

};


#endif //LAB03_SOURCE_CLION_POINT_H
