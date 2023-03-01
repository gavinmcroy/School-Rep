//
// Created by Gavin McRoy on 12/3/2020.
//
#include <fstream>
#include <iostream>
#include <limits>
#include <cmath>
#include "Transportation.h"

Transportation::Transportation(const std::string &myString, const std::string &transitFile) {
    startState = std::numeric_limits<unsigned short>::max();
    
    //std::cout<<startState<<std::endl;
    //std::cout<<pow(2,16);
    readInPlaces(myString);
    readInTransit(transitFile);

}

void Transportation::readInPlaces(const std::string &placesFile) {
    std::ifstream input;
    input.open(placesFile);

    if (input.fail()) {
        std::cout << "File IO error for " << placesFile << std::endl;
        exit(1);
    }

    int iterator = 0;
    std::string buffer;
    while (input >> buffer) {
        pickUpLocation.insert(std::make_pair(buffer, iterator));
        landMarks.push_back(buffer);
        iterator++;
    }

}

void Transportation::readInTransit(const std::string &transitFile) {
    std::ifstream input;
    input.open(transitFile);

    /* Destinations */
    if (input.fail()) {
        std::cout << "File IO error for " << transitFile << std::endl;
    }

    TransportationServices services;
    while (input >> services.providerName >> services.cost) {
        for (int i = 0; i < pickUpLocation.size() - 1; i++) {
            std::string tmp;
            input >> tmp;
            services.dropOff.push_back(pickUpLocation[tmp]);
        }
        allServices.push_back(services);
        services.dropOff.clear();
    }

    /* Debug Test Statements */
    std::cout << "Testing pick up and drop off" << std::endl;
    std::cout << pickUpLocation["schilleter_dining_hall"] << std::endl;
    std::cout << allServices.at(0).providerName << " " << landMarks.at(allServices.at(0).dropOff.at(0));
    /* Debug Test Statements */
}

void Transportation::buildGraph() {

}
