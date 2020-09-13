#include <iostream>
#include <fstream>
#include "Point.h"
#include "PointMap.h"

int main() {

    PointMap map;
    std::cout << "Hello, World!" << std::endl;
    map.readFileIntoTable("points.txt");

    //map.printData();
    map.calculateShortestDistance();

//    Point point(.1,.2);
//    Point point1 (.1,.2);
//    Point point2 (.1,.2);
//    Point point3 (.1,.2);
//
//    map.insert(point);
//    map.insert(point1);
//    map.insert(point2);
//    map.insert(point3);
//    map.printData();

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
