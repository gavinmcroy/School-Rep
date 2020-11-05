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

double TSP::calculateTourDistance(std::vector<int> &t) {
    double currentDistance = 0;
    for (unsigned int i = 0; i < t.size(); i++) {
        /* Special case for comparing last city to start city */
        int previous = 0;
        int current = 0;
        if (i + 1 >= t.size()) {
            previous = t.at(0);
            current = t.at(t.size() - 1);
            currentDistance += sqrt(pow((cityLocations.at(previous).x - cityLocations.at(current).x), 2) +
                                    pow((cityLocations.at(previous).y - cityLocations.at(current).y), 2));
        }
            /* Compare city 1 distance to city 2, then city 2 to city 3 and add it up */
        else {
            previous = t.at(i);
            current = t.at(i + 1);
            currentDistance += sqrt(pow((cityLocations.at(previous).x - cityLocations.at(current).x), 2) +
                                    pow((cityLocations.at(previous).y - cityLocations.at(current).y), 2));
        }
    }
    return currentDistance;
}

double TSP::calculateTourWithPoints(unsigned int start, unsigned int ending) {
    double distance = 0;
    if (start == 0 && ending == tour.size() - 1) {
        return calculateTourDistance(tour);
    }
    /* Special case for linking last city to first */
    if (start == 0) {
        /* We need to tie the last city to the starting city I need to find distance from last to start */
        unsigned int lastCityIndex = tour.at(tour.size() - 1);
        unsigned int firstCityIndex = tour.at(start);
        distance += sqrt(pow((cityLocations.at(lastCityIndex).x - cityLocations.at(firstCityIndex).x), 2) +
                         pow((cityLocations.at(lastCityIndex).y - cityLocations.at(firstCityIndex).y), 2));
        /* If we are on index 49 we want to lap over to the next index would be 0 */
        if (ending + 1 >= tour.size()) {
            distance += sqrt(pow((cityLocations.at(tour.at(ending)).x - cityLocations.at(0).x), 2) +
                             pow((cityLocations.at(tour.at(ending)).y - cityLocations.at(0).y), 2));
        } else {
            distance += sqrt(pow((cityLocations.at(tour.at(ending)).x - cityLocations.at(tour.at(ending + 1)).x), 2) +
                             pow((cityLocations.at(tour.at(ending)).y - cityLocations.at(tour.at(ending + 1)).y), 2));
        }

    } else {
        distance += sqrt(pow((cityLocations.at(tour.at(start - 1)).x - cityLocations.at(tour.at(start)).x), 2) +
                         pow((cityLocations.at(tour.at(start - 1)).y - cityLocations.at(tour.at(start)).y), 2));
        if (ending + 1 >= tour.size()) {
            distance += sqrt(pow((cityLocations.at(tour.at(ending)).x - cityLocations.at(0).x), 2) +
                             pow((cityLocations.at(tour.at(ending)).y - cityLocations.at(0).y), 2));
        } else {
            distance += sqrt(pow((cityLocations.at(tour.at(ending + 1)).x - cityLocations.at(tour.at(ending)).x), 2) +
                             pow((cityLocations.at(tour.at(ending + 1)).y - cityLocations.at(tour.at(ending)).y), 2));
        }
    }


    return distance;

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
        randomizeTour(tour);
        /* Initial tour distance */
        double calculation = calculateTourDistance(tour);
        bool beingOptimized = true;
        /* While its being optimized  */
        while (beingOptimized) {
            beingOptimized = false;
            for (unsigned int x = 0; x < tour.size(); x++) {
                for (unsigned int j = x + 1; j < tour.size(); j++) {
                    /* Reverse the tour and see if the distance is reduced */
                    if (calculation < absoluteMin) {
                        optimalTour = tour;
                        absoluteMin = calculation;
                    }
                    double currentDistance = calculateTourWithPoints(x, j);
                    reverseTour(x, j, tour);
                    double predictedGain = calculateTourWithPoints(x, j);

                    /* If (this is an improvement) { update calculation } */
                    if (predictedGain < currentDistance) {
                        calculation = calculation - currentDistance + predictedGain;
                        beingOptimized = true;
                    } else {
                        /* Flip tour back to original state since change did not help */
                        reverseTour(x, j, tour);
                    }
                }
            }
        }
    }
    return calculateTourDistance(optimalTour);
}




