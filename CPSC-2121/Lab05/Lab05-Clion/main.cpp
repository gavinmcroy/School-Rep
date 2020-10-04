#include <iostream>
#include<fstream>
#include <vector>
#include<algorithm>
#include <random>
#include "BinarySearchT.h"

int main() {

    BinarySearchT binarySearchT;
    std::ifstream input;
    std::vector<std::pair<double, double>> cuts;
    double firstReadVal = 0;
    double secondReadVal = 0;
    int numberOfCuts = 0;
    int totalIntersections = 0;
    BinarySearchT::Node *root = nullptr;

    input.open("cuts.txt");
    if (input.fail()) {
        std::cout << "Failed to open file" << std::endl;
        exit(1);
    }

    /*Testing get_rank*/
//    std::random_device rd;  /* Will be used to obtain a seed for the random number engine */
//    std::mt19937 gen(rd()); /* Standard mersenne_twister_engine seeded with rd() */
//    std::uniform_real_distribution<> dis(1.0, 100.0);
//    for (int i = 0; i < 30; i++) {
//        double val = dis(gen);
//        std::cout << val << std::endl;
//        root = binarySearchT.insert_keep_balanced(root, val);
//    }
//    std::cout << binarySearchT.get_rank(root, 2.5) << std::endl;
    /*Testing get_rank */

//    while (input >> firstReadVal >> secondReadVal) {
//        cuts.emplace_back(firstReadVal, secondReadVal);
//        cuts.emplace_back(secondReadVal, firstReadVal);
//    }

    cuts.emplace_back(190,34);
    cuts.emplace_back(34,190);
    cuts.emplace_back(110,12);
    cuts.emplace_back(12,110);
    cuts.emplace_back(110,340);
    cuts.emplace_back(340,110);
    sort(cuts.begin(), cuts.end());


//    while (input >> firstReadVal >> secondReadVal) {
//        if (firstReadVal > secondReadVal) {
//            cuts.emplace_back(secondReadVal, firstReadVal);
//        } else {
//            cuts.emplace_back(firstReadVal, secondReadVal);
//        }
//        numberOfCuts++;
//    }

    for(auto & cut : cuts){
        //std::cout<<"FIRST: "<<cuts.at(i).first << " SECOND: "<<cuts.at(i).second<<std::endl;
        root = binarySearchT.insert_keep_balanced(root,cut.first);
        /*  */
        /*int val += (binarySearchT.get_rank(root,first))Get the rank of this element in search*/
    }


    /* [N = numberOfCuts and P = Total Intersections ] 1 + N + P */
//    std::cout << "O(N)^2 Solution is loading..." << std::endl;
//    std::sort(cuts.begin(), cuts.end());

//    for (int i = 0; i < cuts.size(); i++) {
//        double first = cuts.at(i).first;
//        double second = cuts.at(i).second;
//
//        for (int j = i; j < cuts.size(); j++) {
//            /* First condition checks to see if the second point lies within the interval and first does not
//             * Second condition checks to see if the first point lies within the interval and second does not */
//            if (((cuts.at(j).first < first) && (cuts.at(j).second > first) &&
//                 (cuts.at(j).second < second)) ||
//                ((cuts.at(j).first > first) && (cuts.at(j).first < second) && (cuts.at(j).second > second))) {
//                totalIntersections++;
//            }
//
//        }
//    }

    std::cout << "Number of cuts " << numberOfCuts << std::endl;
    std::cout << "Total Intersections " << totalIntersections << std::endl;
    std::cout << "Total pieces " << totalIntersections + numberOfCuts + 1;
    return 0;
}



/** Reference */
//    for (auto &cut : cuts) {
//        std::cout << cut.first << " " << cut.second << std::endl;
//    }