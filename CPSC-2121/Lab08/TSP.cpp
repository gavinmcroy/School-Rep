//
// Created by Gavin McRoy on 11/1/2020.
//
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <limits>
#include <chrono>
#include "TSP.h"

TSP::TSP(const std::string &fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    cityLocations.reserve(50);
    tour.reserve(50);
    absoluteMin = std::numeric_limits<double>::max();

    if (inFile.fail()) {
        std::cout << "File error" << std::endl;
        exit(1);
    }
    /* Read in city points */
    double x, y;
    while (inFile >> x >> y) {
        cityLocations.emplace_back(x, y);
    }
    std::cout << "File read in " << std::endl;
    /* Fill in tour with corresponding city indices */
    for (unsigned int i = 0; i < cityLocations.size(); i++) {
        tour.push_back(i);
    }

    inFile.close();
}

double TSP::calculateTourDistance() {
    double currentDistance = 0;
    for (unsigned int i = 0; i < tour.size(); i++) {
        /* Special case for comparing last city to start city */
        int previous = 0;
        int current = 0;
        if (i + 1 >= tour.size()) {
            previous = tour.at(0);
            current = tour.at(tour.size() - 1);
            currentDistance += sqrt(pow((cityLocations.at(previous).x - cityLocations.at(current).x), 2) +
                                    pow((cityLocations.at(previous).y - cityLocations.at(current).y), 2));
        }
            /* Compare city 1 distance to city 2, then city 2 to city 3 and add it up */
        else {
            previous = tour.at(i);
            current = tour.at(i + 1);
            currentDistance += sqrt(pow((cityLocations.at(previous).x - cityLocations.at(current).x), 2) +
                                    pow((cityLocations.at(previous).y - cityLocations.at(current).y), 2));
        }
    }
    return currentDistance;
}

void TSP::randomizeTour(std::vector<int> &t) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(tour.begin(), tour.end(), std::default_random_engine(seed));
}

void TSP::reverseTour(unsigned int start, unsigned int ending, std::vector<int> &t) {
    for (unsigned int i = start; i < ending; i++) {
        int tmpVal = t.at(i);
        t.at(i) = t.at(ending);
        t.at(ending) = tmpVal;
        ending--;
        if (ending == i) {
            break;
        }
    }
}

void TSP::outputTour() {
    /* Its easier to copy paste from a file */
    std::ofstream outputFile;
    outputFile.open("Output.txt");
    for (int i : optimalTour) {
        outputFile << i << " ";
    }
    outputFile.close();
}

double TSP::calculateOptimalTour() {
    /* Generate 1000 possible solutions and pick the best */
    for (int i = 0; i < 1000; i++) {
        double minDistancePerSolution = std::numeric_limits<double>::max();
        randomizeTour(tour);
        bool beingOptimized = true;

        /* While its being optimized  */
        while (beingOptimized) {
            beingOptimized = false;
            for (unsigned int x = 0; x < tour.size(); x++) {
                for (unsigned int j = x + 1; j < tour.size(); j++) {
                    /* Reverse the tour and see if the distance is reduced */
                    reverseTour(x, j, tour);
                    double calculation = calculateTourDistance();
                    if (calculation < absoluteMin) {
                        optimalTour = tour;
                        absoluteMin = calculation;
                    }
                    if (calculation < minDistancePerSolution) {
                        beingOptimized = true;
                        minDistancePerSolution = calculation;
                    } else {
                        /* Flip tour back to original state since change did not help */
                        reverseTour(x, j, tour);
                    }
                }
            }
        }
    }
    return absoluteMin;
}


