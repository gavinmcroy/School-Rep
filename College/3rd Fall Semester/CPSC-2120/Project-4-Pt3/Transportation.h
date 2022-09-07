//
// Created by Gavin McRoy on 12/3/2020.
//
#include <map>
#include <unordered_map>
#include <vector>
#ifndef PROJECT_4_PT3_TRANSPORTATION_H
#define PROJECT_4_PT3_TRANSPORTATION_H


class Transportation {

    struct TransportationServices {
        std::string providerName;
        double cost;
        std::vector<int> dropOff;
    };

private:

    unsigned short startState;

    std::vector<TransportationServices> allServices;

    std::unordered_map<std::string,int> pickUpLocation;

    std::vector<std::string> landMarks;

    void readInPlaces(const std::string &placesFile);

    void readInTransit(const std::string &transitFile);

    void buildGraph();

public:
    explicit Transportation(const std::string& placesFile, const std::string &transitFile);


};


#endif //PROJECT_4_PT3_TRANSPORTATION_H
