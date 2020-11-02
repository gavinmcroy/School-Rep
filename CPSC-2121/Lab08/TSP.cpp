//
// Created by Gavin McRoy on 11/1/2020.
//
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include "TSP.h"


TSP::TSP(const std::string &fileName) {
    std::ifstream inFile;
    std::ofstream outputFile;
    inFile.open(fileName);
    cityLocations.reserve(50);
    tour.reserve(50);

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
    for (int i = 0; i < cityLocations.size(); i++) {
        tour.push_back(i);
    }

    /* Testing output */
    randomizeTour();
    outputFile.open("Output.txt");
    for (int i = 0; i < tour.size(); i++) {
        outputFile << tour.at(i) << " ";
    }
    outputFile << std::endl;
    //reverseTour(0, 49);
    for (int i = 0; i <= 49; i++) {
        outputFile << tour.at(i) << " ";
    }
    outputFile.close();

    inFile.close();
}

double TSP::calculateTourDistance() {
    double currentDistance = 0;
    for (int i = 0; i < tour.size(); i++) {
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

void TSP::randomizeTour() {
    std::shuffle(tour.begin(), tour.end(), std::mt19937(std::random_device()()));
}

void TSP::reverseTour(int start, int ending) {
    for (int i = start; i < ending; i++) {
        int tmp = tour.at(i);
        tour.at(i) = tour.at(ending);
        tour.at(ending) = tmp;
        ending--;
        if (ending == i) {
            break;
        }
    }
}

double TSP::calculateOptimalTour() {
    for(int i =0 ; i < tour.size(); i++){
        for(int j = 0; j < tour.size(); j++){

        }
    }
    return calculateTourDistance();
}


