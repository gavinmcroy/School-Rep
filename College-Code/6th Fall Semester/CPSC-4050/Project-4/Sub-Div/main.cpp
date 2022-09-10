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

void subdivisionGeneration();

std::vector<Point> startingPoint;

int main() {
    std::ifstream input;
    input.open("points.txt");

    if (input.fail()) {
        std::cerr << "File open error" << std::endl;
        exit(1);
    }

    double x, y, z, t1, t2, t3;
    while (input >> x >> y >> z >> t1 >> t2 >> t3) {
        startingPoint.emplace_back(x, y, z);
    }

    for (int i = 0; i < 1; i++) {
        subdivisionGeneration();
    }
    std::ofstream outFile;
    outFile.open("out.txt");
    if (outFile.fail()) {
        std::cerr << "File output error" << std::endl;
        exit(1);
    }


    for (auto &i : startingPoint) {
        outFile << i.x << "," << i.y << "\n";
    }

    return 0;
}

void subdivisionGeneration() {
    /* Generate odd points*/
    const double SUB_WEIGHT = 6;
    const int GENERATE_HUNDRED_POINTS = 4;

    /* Insert odd point in between first and second */
    std::vector<Point> oddLocations;
    for (int iter = 0; iter < GENERATE_HUNDRED_POINTS; iter++) {
        for (int i = 0; i < startingPoint.size(); i += 2) {
            /* Generate Odd Point */
            Point oddLoc = (startingPoint[i] + startingPoint[i + 1]) / 2;
            oddLocations.push_back(oddLoc);
        }

        /* Now we need to move our even points. We have to be careful to not go out of bounds */
        /* I think its easier if we just straight up modify the even list with the odd list */
        for (int i = 0; i < startingPoint.size(); i++) {
            /* The first even point has no other locations around it, same with the last element, so do not modify */
            if (i == 0 || i == startingPoint.size() - 1) {
                continue;
            }
            Point wtf = startingPoint[i] * SUB_WEIGHT;
            Point debug = (startingPoint[i - 1] + wtf + startingPoint[i + 1]) / (2 + SUB_WEIGHT);
            startingPoint[i] = debug;
        }

        /* Merges even and odd points to a new line. It basically inserts even odd even odd*/
        std::vector<Point> temp;
        int evenIncrementer = 0;
        int oddIncrementer = 0;
        for (int i = 0; i < startingPoint.size() * 2; i++) {
            if (i % 2 == 1) {
                temp.push_back(startingPoint[evenIncrementer]);
                evenIncrementer++;
            } else {
                temp.push_back(oddLocations[oddIncrementer]);
                oddIncrementer++;
            }
        }
        startingPoint = temp;
    }
}
