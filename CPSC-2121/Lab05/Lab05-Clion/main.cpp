#include <iostream>
#include<fstream>
#include <vector>
#include<algorithm>

int main() {

    std::ifstream input;
    std::vector<std::pair<double, double>> cuts;
    double firstReadVal = 0;
    double secondReadVal = 0;
    int numberOfCuts = 0;
    int totalIntersections = 0;

    input.open("cuts.txt");
    while (input >> firstReadVal >> secondReadVal) {
        if (firstReadVal > secondReadVal) {
            cuts.emplace_back(secondReadVal, firstReadVal);
        } else {
            cuts.emplace_back(firstReadVal, secondReadVal);
        }
        numberOfCuts++;
    }


    /* [N = numberOfCuts and P = Total Intersections ] 1 + N + P */
    std::cout << "O(N)^2 Solution is loading..." << std::endl;
    std::sort(cuts.begin(), cuts.end());

    for (int i = 0; i < cuts.size(); i++) {
        double first = cuts.at(i).first;
        double second = cuts.at(i).second;

        for (int j = i; j < cuts.size(); j++) {
            /* First condition checks to see if the second point lies within the interval and first does not
             * Second condition checks to see if the first point lies within the interval and second does not */
            if (((cuts.at(j).first < first) && (cuts.at(j).second > first) &&
                 (cuts.at(j).second < second)) ||
                ((cuts.at(j).first > first) && (cuts.at(j).first < second) && (cuts.at(j).second > second))) {
                totalIntersections++;
            }

        }
    }

    std::cout << "Number of cuts " << numberOfCuts << std::endl;
    std::cout << "Total Intersections " << totalIntersections << std::endl;
    std::cout << "Total pieces " << totalIntersections + numberOfCuts + 1;
    return 0;
}



/** Reference */
//    for (auto &cut : cuts) {
//        std::cout << cut.first << " " << cut.second << std::endl;
//    }