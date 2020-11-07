//
// Created by Gavin McRoy on 11/3/2020.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include "HalloweenOptimization.h"


bool howToSort(HalloweenOptimization::Candy c1, HalloweenOptimization::Candy c2) {
    return c1.ratio > c2.ratio;
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
        candy.emplace_back(tastiness, weight);
    }
    /* Create our 3 empty bags */
    bagCollection.reserve(3);
    for (int i = 0; i < NUM_BAGS; i++) {
        bagCollection.emplace_back();
    }

}

int HalloweenOptimization::greedyImplementation() {

    for (int i = 0; i < candy.size(); i++) {
        candy.at(i).ratio = (candy.at(i).tastiness / (double) candy.at(i).weight);
    }
    std::sort(candy.begin(), candy.end(), howToSort);

    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < candy.size(); j++) {
            if ((bagCollection.at(i).currentWeight + candy.at(j).weight) < Bag::MAX_WEIGHT && !candy.at(j).hasVisited) {
                bagCollection.at(i).bag.push_back(candy.at(j));
                bagCollection.at(i).currentWeight += candy.at(j).weight;
                candy.at(j).hasVisited = true;
            }
        }
    }
    double counter = calculateCandyTastiness();
    return (int) counter;
}

void HalloweenOptimization::randomizeCandy(std::vector<HalloweenOptimization::Candy> &c) {
    for (int i = 0; i < bagCollection.size(); i++) {
        bagCollection.at(i).bag.clear();
    }
    srand(time(nullptr));

    for (int i = 0; i < candy.size(); ++i) {
        int randomNumber = rand() % 3;
        // std::cout << (int)dist(mt) << "\n";
        bagCollection.at(randomNumber).bag.push_back(candy.at(i));
    }
}

int HalloweenOptimization::refineImplementation() {
    int refinement = 1000;
    std::vector<int> solutions;
    bool isOptimizing = true;
    for (int z = 0; z < refinement; z++) {
        randomizeCandy(candy);
        isOptimizing = true;
        while (isOptimizing) {
            isOptimizing = false;
            for (int i = 0; i < bagCollection.size(); i++) {
                for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
                    for (int x = 0; x < bagCollection.size(); x++) {
                        /* Take candy that is to be moved */
                        Candy c = bagCollection.at(i).bag.at(j);
                        /* Delete the candy that is to be moved from the vector */
                        bagCollection.at(i).bag.erase(bagCollection.at(i).bag.begin() + (j-1));
                        /* Update the bags weight to accommodate the moved candy */
                        bagCollection.at(i).currentWeight -=c.weight;
                        /* Prevent adding candy back to its original position */
                        if (x == i) {
                            continue;
                        }

                        /* Add candy back to its new bag */
                        bagCollection.at(x).bag.push_back(c);
                        /* The bag is no longer valid */
                        if (bagCollection.at(x).currentWeight > Bag::MAX_WEIGHT) {
                            /* Greedily add elements until valid */
                            isOptimizing = true;
                        }
                    }
                    //bagCollection.at(i).bag.at(j).weight;
                }
            }
        }
    }
    return 0;
}

void HalloweenOptimization::debugPrintStatements() {
    //randomizeCandy(candy);
//    for (int i = 0; i < candy.size(); i++) {
//        std::cout << "Weight " << candy.at(i).weight << " Tastiness: " << candy.at(i).tastiness << " Ratio: " <<
//                  candy.at(i).ratio << std::endl;
//    }
    // Candy c(1,2);
    // Candy candy1(5,5);
    //candy1 = c;
    //std::cout<<c.weight<<std::endl;
    //std::cout<<c.tastiness<<std::endl;


    double weightC = 0;
    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            weightC += bagCollection.at(i).bag.at(j).weight;
            //double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            //std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "WEIGHT " << weightC << std::endl;
    //std::cout << "IS VALID " << isInvalid() << std::endl;
    std::cout << "Randomization Testing" << std::endl;
    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            double weight = bagCollection.at(i).bag.at(j).weight;
            double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "BEFORE " << std::endl;
    randomizeCandy(candy);
    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            double weight = bagCollection.at(i).bag.at(j).weight;
            double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "AFTER " << std::endl;
}

int HalloweenOptimization::calculateCandyTastiness() {
    double counter = 0;
    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            counter += bagCollection.at(i).bag.at(j).tastiness;
        }
    }
    return (int) counter;
}

bool HalloweenOptimization::isInvalid(int index) {
    double weight = 0;
    for (int i = 0; i < bagCollection.size(); i++) {
        for (int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            weight += bagCollection.at(i).bag.at(j).tastiness;
            if (weight > Bag::MAX_WEIGHT) {
                return false;
            }
        }
        weight = 0;
    }
    return true;
}

void HalloweenOptimization::operator=(const Candy &c) {

    //Candy candy1(c.tastiness,c.weight);
    //candy1.hasVisited = c.hasVisited;
}