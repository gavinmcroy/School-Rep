#include <iostream>
#include <fstream>
#include "Point.h"
#include "PointMap.h"

int main() {

    PointMap map;
    map.readFileIntoTable("points.txt");

    std::cout << "Hello, World!" << std::endl;
    return 0;



/*** [DEBUG]
    ------------
    Point point(1,2);
    Point point1(3,4);
    point = point1;
    std::cout<<point.x<<" "<<point.y<<std::endl;
    std::cout<<point1.x<<" "<<point1.y<<std::endl;
    double x = Point::calcDistance(point,point1);

    std::cout<<std::setprecision(10)<<x<<std::endl;
    ------------
    [DEBUG] ***/
}
