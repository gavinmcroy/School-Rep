//
// Created by Gavin McRoy on 11/3/2020.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "HalloweenOptimization.h"

int calculationsFound = 0;

bool howToSort(HalloweenOptimization::Candy c1, HalloweenOptimization::Candy c2) {
    return c1.ratio > c2.ratio;
}

HalloweenOptimization::HalloweenOptimization(std::string &s) {
    srand(time(nullptr));
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
    /* IMPORTANT NOTE bag.at(0) REPRESENTS NOT INSIDE THE BAG */
    bagCollection.reserve(4);
    for (int i = 0; i < NUM_BAGS; i++) {
        bagCollection.emplace_back();
    }

}

int HalloweenOptimization::greedyImplementation() {

    for (unsigned int i = 0; i < candy.size(); i++) {
        candy.at(i).ratio = (candy.at(i).tastiness / (double) candy.at(i).weight);
    }
    std::sort(candy.begin(), candy.end(), howToSort);

    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (unsigned int j = 0; j < candy.size(); j++) {
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
    /* This randomizes candy so that every bag is valid, if candy did not fit we just place it outside the bag */
    for (unsigned int i = 0; i < bagCollection.size(); i++) {
        bagCollection.at(i).bag.clear();
        bagCollection.at(i).currentWeight = 0;
    }
    for (unsigned int i = 0; i < candy.size(); i++) {
        /* IMPORTANT NOTE bag.at(0) REPRESENTS NOT INSIDE THE BAG */
        unsigned int randomNumber = (rand() % 3) + 1;
        /* If a particular bag is maxed out on weight, place it outside of the bag */
        if (bagCollection.at(randomNumber).currentWeight + candy.at(i).weight > Bag::MAX_WEIGHT) {
            bool emptyIsOnlyOption = true;
            for (unsigned int j = 1; j < bagCollection.size(); j++) {
                /* Avoid adding it back to itself */
                if (j == randomNumber) {
                    continue;
                }
                /* We found a valid bag to place it in */
                if (bagCollection.at(j).currentWeight + candy.at(i).weight < Bag::MAX_WEIGHT) {
                    bagCollection.at(j).bag.push_back(candy.at(i));
                    candy.at(i).isInBag = true;
                    bagCollection.at(j).currentWeight += candy.at(i).weight;
                    emptyIsOnlyOption = false;
                    break;
                }
            }
            /* The rest of the bags are full we have to place it outside of the bag */
            if (emptyIsOnlyOption) {
                bagCollection.at(0).bag.push_back(candy.at(i));
                candy.at(i).isInBag = false;
            }

        }/* The weight was already valid so place our candy into a randomly chosen bag */
        else {
            bagCollection.at(randomNumber).bag.push_back(candy.at(i));
            candy.at(i).isInBag = true;
            bagCollection.at(randomNumber).currentWeight += candy.at(i).weight;
        }
    }
}

int HalloweenOptimization::refineImplementation() {
    int refinement = 1000;
    bool isOptimizing = true;
    std::vector<int> answers;
    std::vector<Bag> optimalBag;
    answers.reserve(refinement);
    int maxTastiness = 0;
    for (int z = 0; z < refinement; z++) {
        randomizeCandy(candy);
        isOptimizing = true;
        while (isOptimizing) {
            isOptimizing = false;

            /* IMPORTANT NOTE bag.at(0) REPRESENTS NOT INSIDE THE BAG */
            for (unsigned int i = 1; i < bagCollection.size(); i++) {
                for (unsigned int j = 0; j < bagCollection.at(i).bag.size(); j++) {
                    unsigned int swapVal = j % bagCollection.at(0).bag.size();
                    /* Update the bags weight by taking the current weight - subtracting by whats there and
                     * adding the to be swapped element */

                    /* Dont swap duplicates */
                    if (j == swapVal) {
                        continue;
                    }
                    bagCollection.at(i).currentWeight = bagCollection.at(i).currentWeight -
                                                        bagCollection.at(i).bag.at(j).weight +
                                                        bagCollection.at(i).bag.at(swapVal).weight;
                    bagCollection.at(i).bag.at(swapVal).weight = bagCollection.at(i).bag.at(j).weight;
                    std::swap(bagCollection.at(i).bag.at(j), bagCollection.at(i).bag.at(swapVal));
                    int currentCandyTastiness = calculateCandyTastiness();
                    if (maxTastiness < currentCandyTastiness) {
                        optimalBag = bagCollection;
                        maxTastiness = currentCandyTastiness;
                        answers.push_back(maxTastiness);
                        isOptimizing = true;
                    }
                }
            }
        }
    }
    /* TODO Move to its own function */
    std::ofstream out;
    out.open("debug.txt");
    int max = 0;
    out << "ITERATIVE REFINEMENT " << std::endl;
    for (unsigned int i = 1; i < optimalBag.size(); i++) {
        out << "BAG ----------------------- " << std::endl;
        for (int j = 0; j < optimalBag.at(i).bag.size(); j++) {
            out << i << ". " << "WEIGHT: " << optimalBag.at(i).bag.at(j).weight << std::endl;
            out << i << ". " << "TASTINESS: " << optimalBag.at(i).bag.at(j).tastiness << std::endl;
        }
    }
    for (int i = 0; i < answers.size(); i++) {
        if (answers.at(i) > max) {
            max = answers.at(i);
        }
    }
    return max;
}

std::vector<int> uniqueSolutions;
int val = 0;

int HalloweenOptimization::prunedExhaustiveSearch(int start) {
    if (start == candy.size()-3) {
        uniqueSolutions.push_back(calculateCandyTastinessO());
        calculationsFound++;
        return 0;
    }
    for (int c = 0; c < bagCollection.size(); c++) {
        /* Symmetry */
        if(start == 0){
            if(c==bagCollection.size()/2){
                break;
            }
        }
        if (isValid(c, start)) {
            /* Place Candy */
            bagCollection.at(c).bag.push_back(candy.at(start));
            bagCollection.at(c).currentWeight += candy.at(start).weight;
            bagCollection.at(c).currentTastiness += candy.at(start).tastiness;
            prunedExhaustiveSearch(start + 1);
            /* Remove Candy */
            bagCollection.at(c).bag.pop_back();
            bagCollection.at(c).currentWeight -= candy.at(start).weight;
            bagCollection.at(c).currentTastiness -= candy.at(start).tastiness;
        }
    }
    return 0;
}

void HalloweenOptimization::resetForPrune() {

    for (int i = 0; i < bagCollection.size(); i++) {
        bagCollection.at(i).bag.clear();
        bagCollection.at(i).currentWeight = 0;
        bagCollection.at(i).currentTastiness = 0;
    }
//    for(int i = 0; i < candy.size()-1; i++){
//        bagCollection.at(0).bag.push_back(candy.at(i));
////    }
//    bagCollection.at(1).bag.push_back((candy.at(candy.size()-1)));

}


int HalloweenOptimization::findMax() {
    int max = 0;
    for (int i = 0; i < uniqueSolutions.size(); i++) {
        if (uniqueSolutions.at(i) > max) {
            max = uniqueSolutions.at(i);
        }
    }
    return max;
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
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (unsigned int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            weightC += bagCollection.at(i).bag.at(j).weight;
            //double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            //std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "WEIGHT " << weightC << std::endl;
    //std::cout << "IS VALID " << isInvalid() << std::endl;
    std::cout << "Randomization Testing" << std::endl;
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (unsigned int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            double weight = bagCollection.at(i).bag.at(j).weight;
            double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "BEFORE " << std::endl;
    randomizeCandy(candy);
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (unsigned int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            double weight = bagCollection.at(i).bag.at(j).weight;
            double tastiness = bagCollection.at(i).bag.at(j).tastiness;
            std::cout << "Bag :" << i << " Candy Present " << weight << " " << tastiness << std::endl;
        }
    }
    std::cout << "AFTER " << std::endl;
}

int HalloweenOptimization::calculateCandyTastiness() {
    int counter = 0;
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (unsigned int j = 0; j < bagCollection.at(i).bag.size(); j++) {
            counter += bagCollection.at(i).bag.at(j).tastiness;
        }
    }
    return counter;
}

int HalloweenOptimization::calculateCandyTastinessO() {
    int counter = 0;
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        counter += bagCollection.at(i).currentTastiness;
    }
    return counter;
}


bool HalloweenOptimization::isValid(int bagIndex, int candyIndex) {
    /* This currently is checking if adding a specified candy to a bag is valid */
    /* TODO this can be made faster by keeping track of candyWeight instead of re adding it */
    //int weight = 0;

//    for (unsigned int j = 0; j < bagCollection.at(bagIndex).bag.size(); j++) {
//        weight += bagCollection.at(bagIndex).bag.at(j).weight;
//        calculationsFound++;
//    }

//    if (weight + candy.at(candyIndex).weight > Bag::MAX_WEIGHT) {
//        return false;
//    }
//    if (bagCollection.at(bagIndex).currentWeight + candy.at(candyIndex).weight > Bag::MAX_WEIGHT) {
//        return false;
//    }

    return bagCollection.at(bagIndex).currentWeight + candy.at(candyIndex).weight < Bag::MAX_WEIGHT;
}

int HalloweenOptimization::calculationOptimizer() {
    return calculationsFound;
}



















//                    std::cout<<"BEFORE "<<std::endl;
//                    std::cout<<"1. "<<bagCollection.at(i).bag.at(j).tastiness << " "
//                    <<bagCollection.at(i).bag.at(j).weight << std::endl;
//                    std::cout<<"2. "<<bagCollection.at(i).bag.at(swapVal).tastiness << " " <<
//                    bagCollection.at(i).bag.at(swapVal).weight << std::endl;
//std::swap(bagCollection.at(i).bag.at(j), bagCollection.at(i).bag.at(swapVal));
//                    std::cout<<"AFTER "<<std::endl;
//
//                    std::cout<<"1. "<<bagCollection.at(i).bag.at(j).tastiness << " "
//                             <<bagCollection.at(i).bag.at(j).weight << std::endl;
//                    std::cout<<"2. "<<bagCollection.at(i).bag.at(swapVal).tastiness << " " <<
//                             bagCollection.at(i).bag.at(swapVal).weight << std::endl;