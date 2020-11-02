//
// Created by Gavin McRoy on 11/1/2020.
//

#include "TSP.h"
#include <fstream>
#include <iostream>
#include <cmath>

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
    /* Read in file */
    double x, y;
    while (inFile >> x >> y) {
        cityLocations.emplace_back(x, y);
    }
    std::cout << "File read in " << std::endl;

    for (int i = 0; i < cityLocations.size(); i++) {
        tour.push_back(i);
    }
    outputFile.open("Output.txt");
    for (int i = 0; i < cityLocations.size(); i++) {
        outputFile << i << " ";
    }
    outputFile.close();
    inFile.close();
}

double TSP::calculateTourDistance() {
    double currentDistance = 0;
    for (int i = 0; i < tour.size(); i++) {
        /* Special case for comparing last city to start city */
        if (i + 1 >= tour.size()) {
            currentDistance += sqrt(pow((cityLocations.at(0).x - cityLocations.at(tour.size() - 1).x), 2) +
                                    pow((cityLocations.at(0).y - cityLocations.at(tour.size() - 1).y), 2));
        }
            /* Compare city 1 distance to city 2, then city 2 to city 3 and add it up */
        else {
            currentDistance += sqrt(pow((cityLocations.at(i).x - cityLocations.at(i + 1).x), 2) +
                                    pow((cityLocations.at(i).y - cityLocations.at(i + 1).y), 2));
        }
    }
    return currentDistance;
}

double TSP::calculateOptimalTour() {
    return calculateTourDistance();
}


