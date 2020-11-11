//
// Created by Gavin McRoy on 11/3/2020.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "HalloweenOptimization.h"

int calculationsFound = 0;

bool howToSort(HalloweenOptimization::Candy c1, HalloweenOptimization::Candy c2) {
    return c1.ratio > c2.ratio;
}

HalloweenOptimization::HalloweenOptimization(std::string &fileName) {
    tastinessOverall = 0;
    uniqueSolutions.reserve(21805580);
    bagCollection.reserve(NUM_BAGS);
    candy.reserve(16);

    double weight, tastiness;
    srand(time(nullptr));

    std::ifstream inputFile;
    inputFile.open("candy.txt");

    if (inputFile.fail()) {
        std::cout << "File error" << std::endl;
        exit(1);
    }
    std::cout << "Reading in file " << std::endl;

    while (inputFile >> weight >> tastiness) {
        candy.emplace_back(tastiness, weight);
    }
    /* Create our 3 empty bags */
    /* IMPORTANT NOTE bag.at(0) REPRESENTS NOT INSIDE THE BAG */
    for (int i = 0; i < NUM_BAGS; i++) {
        bagCollection.emplace_back();
    }

}

int HalloweenOptimization::greedyImplementation() {

    for (auto & i : candy) {
        i.ratio = (i.tastiness / (double) i.weight);
    }
    std::sort(candy.begin(), candy.end(), howToSort);

    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (auto & j : candy) {
            if ((bagCollection.at(i).currentWeight + j.weight) < Bag::MAX_WEIGHT && !j.hasVisited) {
                bagCollection.at(i).bag.push_back(j);
                bagCollection.at(i).currentWeight += j.weight;
                j.hasVisited = true;
            }
        }
    }
    outputToFile("GREEDY IMPLEMENTATION ",bagCollection);
    double counter = calculateCandyTastiness();
    return (int) counter;
}

void HalloweenOptimization::randomizeCandy(std::vector<HalloweenOptimization::Candy> &c) {
    /* This randomizes candy so that every bag is valid, if candy did not fit we just place it outside the bag */
    for (auto & i : bagCollection) {
        i.bag.clear();
        i.currentWeight = 0;
    }
    for (auto & i : candy) {
        /* IMPORTANT NOTE bag.at(0) REPRESENTS NOT INSIDE THE BAG */
        unsigned int randomNumber = (rand() % 3) + 1;
        /* If a particular bag is maxed out on weight, place it outside of the bag */
        if (bagCollection.at(randomNumber).currentWeight + i.weight > Bag::MAX_WEIGHT) {
            bool emptyIsOnlyOption = true;
            for (unsigned int j = 1; j < bagCollection.size(); j++) {
                /* Avoid adding it back to itself */
                if (j == randomNumber) {
                    continue;
                }
                /* We found a valid bag to place it in */
                if (bagCollection.at(j).currentWeight + i.weight < Bag::MAX_WEIGHT) {
                    bagCollection.at(j).bag.push_back(i);
                    //candy.at(i).isInBag = true;
                    bagCollection.at(j).currentWeight += i.weight;
                    emptyIsOnlyOption = false;
                    break;
                }
            }
            /* The rest of the bags are full we have to place it outside of the bag */
            if (emptyIsOnlyOption) {
                bagCollection.at(0).bag.push_back(i);

            }

        }/* The weight was already valid so place our candy into a randomly chosen bag */
        else {
            bagCollection.at(randomNumber).bag.push_back(i);
            bagCollection.at(randomNumber).currentWeight += i.weight;
        }
    }
}

int HalloweenOptimization::refineImplementation() {
    int refinement = 1000;
    bool isOptimizing;
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
    outputToFile("ITERATIVE REFINEMENT ",optimalBag);
    int max = 0;
    for (int answer : answers) {
        if (answer > max) {
            max = answer;
        }
    }
    return max;
}


int HalloweenOptimization::prunedExhaustiveSearch(unsigned int start) {
    if (start == candy.size()-3) {
        uniqueSolutions.push_back(tastinessOverall-bagCollection.at(0).currentTastiness);
        return 0;
    }
    for (unsigned int c = 0; c < bagCollection.size(); c++) {
        /* Symmetry */
        if(start == 0) {
            if (c == bagCollection.size() / 2) {
                break;
            }
        }else if(start == 1){
            if(c==bagCollection.size()-1){
                break;
            }
        }
        calculationsFound++;
        /* Pruning */
        if (isValid(c, start)) {
            /* Place Candy */
            bagCollection.at(c).bag.push_back(candy.at(start));
            bagCollection.at(c).currentWeight += candy.at(start).weight;
            bagCollection.at(c).currentTastiness += candy.at(start).tastiness;
            tastinessOverall+=candy.at(start).tastiness;
            prunedExhaustiveSearch(start + 1);
            /* Remove Candy */
            bagCollection.at(c).bag.pop_back();
            bagCollection.at(c).currentWeight -= candy.at(start).weight;
            bagCollection.at(c).currentTastiness -= candy.at(start).tastiness;
            tastinessOverall -= candy.at(start).tastiness;
        }
    }
    return 0;
}

void HalloweenOptimization::resetForPrune() {
    /* Reset everything to default */
    for (auto & i : bagCollection) {
        i.bag.clear();
        i.currentWeight = 0;
        i.currentTastiness = 0;
        tastinessOverall = 0;
    }
}


int HalloweenOptimization::findMax() {
    int max = 0;
    for (int uniqueSolution : uniqueSolutions) {
        if (uniqueSolution > max) {
            max = uniqueSolution;
        }
    }
    return max;
}

void HalloweenOptimization::debugPrintStatements() {
    double weightC = 0;
    for (unsigned int i = 1; i < bagCollection.size(); i++) {
        for (auto & j : bagCollection.at(i).bag) {
            weightC += j.weight;
        }
    }
    std::cout << "WEIGHT " << weightC << std::endl;
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
        for (auto & j : bagCollection.at(i).bag) {
            counter += j.tastiness;
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


bool HalloweenOptimization::isValid(unsigned int bagIndex, unsigned int candyIndex) {
    return bagCollection.at(bagIndex).currentWeight + candy.at(candyIndex).weight < Bag::MAX_WEIGHT;
}

void HalloweenOptimization::outputToFile(const std::string& fileHeaderName, std::vector<Bag> &optimalBag) {
    std::ofstream out;
    out.open("debug.txt",std::fstream::app);
    out << fileHeaderName << std::endl;
    for (unsigned int i = 1; i < optimalBag.size(); i++) {
        out << "BAG ----------------------- " << std::endl;
        for (unsigned int j = 0; j < optimalBag.at(i).bag.size(); j++) {
            out << i << ". " << "WEIGHT: " << optimalBag.at(i).bag.at(j).weight << std::endl;
            out << i << ". " << "TASTINESS: " << optimalBag.at(i).bag.at(j).tastiness << std::endl;
        }
    }
}

int HalloweenOptimization::calculationOptimizer() const {
    return uniqueSolutions.size();
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