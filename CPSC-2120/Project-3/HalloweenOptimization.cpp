//
// Created by Gavin McRoy on 11/3/2020.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include "HalloweenOptimization.h"


bool howToSort(HalloweenOptimization::Candy c1, HalloweenOptimization::Candy c2) {
    return c1.tastiness > c2.tastiness;
}

HalloweenOptimization::HalloweenOptimization(std::string &s) {
    std::ifstream inputFile;
    inputFile.open("candy.txt");
    if (inputFile.fail()) {
        std::cout << "File error" << std::endl;
        exit(1);
    }
    std::cout << "Reading in file " << std::endl;
    double weight, tastiness;
    while (inputFile >> weight >> tastiness) {
        candy.emplace_back(weight, tastiness);
    }
    /* Create our 3 empty bags */
    for (int i = 0; i < NUM_BAGS; i++) {
        bags.emplace_back();
    }

}

int HalloweenOptimization::greedyImplementation() {
    int maxTastiness = 0;
    std::sort(candy.begin(), candy.end(), howToSort);

    for (int i = 0; i < candy.size(); i++) {
        //    for (int j = 0; j < candy.size(); j++) {
        //      if(!candy.at(i).hasVisited){

        //    }
        std::cout << "Weight " << candy.at(i).weight << " Tastiness: " << candy.at(i).tastiness << std::endl;
    }
    // }
    return 0;
}
