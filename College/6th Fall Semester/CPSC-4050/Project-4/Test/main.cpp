#include <iostream>
#include <fstream>
#include "subdivisioncurve.h"

int main() {
    SubdivisionCurveEvaluator sub;
    std::vector<Point> points;
    std::ifstream input;
    input.open("points.txt");
    if (input.fail()) {
        exit(1);
    }

    double x, y, z, t1, t2, t3;
    while (input >> x >> y >> z >> t1 >> t2 >> t3) {
        points.emplace_back(x, y);
    }
    std::vector<Point> finalAnswer;

    std::ofstream out;
    out.open("test.txt");
    sub.evaluateCurve(points, finalAnswer, 5000, false, false, 200);
    for (int i = 0; i < finalAnswer.size(); i++) {
        out << finalAnswer[i].x << "," << finalAnswer[i].y << std::endl;
    }
    return 0;
}
