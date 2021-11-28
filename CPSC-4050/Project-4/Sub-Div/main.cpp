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

void subdivisionGeneration(std::vector<Point> &p);


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
    std::cout<<"END"<<std::endl;


    subdivisionGeneration(points);

    //Point r = points[0]/2;
    // std::cout << r.x << " " << r.y << " " << r.z << std::endl;

    return 0;
}

void subdivisionGeneration(std::vector<Point> &p) {
    /* Generate odd points*/
    const int subWeight = 6;
    /* Insert odd point in between first and second */
    int insertionPoint = 1;
    std::vector<Point> oddLocations;
    for (int i = 0; i < p.size(); i += 2) {
        /* Generate Odd Point */
        Point oddLoc = (p[i] + p[i + 1]) / 2;
        oddLocations.push_back(oddLoc);
    }

    /* Merges even and odd points to a new line. It basically inserts even odd even odd*/
    std::vector<Point> finalAnswer;
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
        std::cout << finalAnswer[i].x << "," << finalAnswer[i].y << "\n"; //<<; //finalAnswer[i].z << std::endl;
    }

}
