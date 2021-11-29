#include <iostream>
#include <fstream>
#include <vector>



typedef struct Point {
    double x;
    double y;
    double z;

    Point(double, double, double);

    Point operator+(Point &) const;

    Point operator/(double val) const;

    Point operator*(double val) const;

} Point;

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point Point::operator+(Point &p) const {
    Point point(0, 0, 0);
    point.x = this->x + p.x;
    point.y = this->y + p.y;
    point.z = this->z + p.z;
    return {this->x + p.x, this->y + p.y, this->z + p.z};
}

Point Point::operator/(double val) const {
    return {this->x / val, this->y / val, this->z / val};
}

Point Point::operator*(double val) const {
    return {this->x * val, this->y * val, this->z * val};
}

std::vector<Point> finalAnswer;

std::vector<Point> & subdivisionGeneration(std::vector<Point> &p);


int main() {
    std::ifstream input;
    input.open("points.txt");
    std::vector<Point> points;

    if (input.fail()) {
        std::cerr << "File open error" << std::endl;
        exit(1);
    }

    double x, y, z, t1, t2, t3;
    while (input >> x >> y >> z >> t1 >> t2 >> t3) {
        points.emplace_back(x, y, z);
        std::cout << x << "," << y << "\n"; //<<; //finalAnswer[i].z << std::endl;
    }
    std::cout << "END" << std::endl;

    for(int i = 0; i < 3; i++){
        points = subdivisionGeneration(points);
    }

    for(int i = 0; i < points.size(); i++){
        if(points[i].x < 0.0000000001){
            continue;
        }
        std::cout<<points[i].x <<","<<points[i].y<<"\n";
    }

    //Point r = points[0]/2;
    // std::cout << r.x << " " << r.y << " " << r.z << std::endl;

    return 0;
}

std::vector<Point> & subdivisionGeneration(std::vector<Point> &p) {
    /* Generate odd points*/
    const double SUB_WEIGHT = 6;
    /* Insert odd point in between first and second */
    std::vector<Point> oddLocations;
    for (int i = 0; i < p.size(); i += 2) {
        /* Generate Odd Point */
        Point oddLoc = (p[i] + p[i + 1]) / 2;
        oddLocations.push_back(oddLoc);
    }

    /* Now we need to move our even points. We have to be careful to not go out of bounds */
    /* I think its easier if we just straight up modify the even list with the odd list */
   // for (int i = 0; i < p.size(); i++) {
        /* The first even point has no other locations around it, same with the last element, so skip */
//        if (i == 0 || i == p.size() - 1) {
//            continue;
//        }
//        Point wtf = p[i] * SUB_WEIGHT;
//        Point debug = (oddLocations[i - 1] + wtf + oddLocations[i + 1]) / (2 + SUB_WEIGHT);
//        p[i] = debug;
   // }

    /* Merges even and odd points to a new line. It basically inserts even odd even odd*/
    finalAnswer.clear();
    int evenIncrementer = 0;
    int oddIncrementer = 0;
    for (int i = 0; i < p.size() * 2; i++) {
        if (i % 2 == 0) {
            finalAnswer.push_back(p[evenIncrementer]);
            evenIncrementer++;
        } else {
            finalAnswer.push_back(oddLocations[oddIncrementer]);
            oddIncrementer++;
        }
    }
    return finalAnswer;

}
