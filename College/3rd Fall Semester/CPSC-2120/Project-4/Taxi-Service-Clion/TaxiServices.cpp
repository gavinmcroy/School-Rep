//
// Created by Gavin Taylor Mcroy on 12/4/20.
//
#include <fstream>
#include <iostream>
#include <queue>
#include "TaxiServices.h"


TaxiServices::TaxiServices(const std::string &placesFile, const std::string &transitFile) {
    readLandMarks(placesFile);
    readTransitInformation(transitFile);
    distance.reserve(START);
    neighbors.reserve(START);
    predecessors.reserve(START);
}

void TaxiServices::readLandMarks(const std::string &placesFile) {
    std::ifstream input(placesFile);
    std::string landMark;

    for (int i = 0; i < NUM_LANDMARKS; i++) {
        input >> landMark;
        landmarkMap[landMark] = i;
    }
    input.close();
}

void TaxiServices::readTransitInformation(const std::string &transitFile) {
    std::ifstream inputFile(transitFile);
    std::string serviceName = " ";
    double cost = 0;
    std::string stopLocation = " ";

    /* Read all data into transitInformation */
    while (inputFile >> serviceName) {
        std::vector<int> stops;
        inputFile >> cost;
        transitInformation.emplace_back(cost, serviceName);

        for (int i = 0; i < NUM_LANDMARKS - 1; i++) {
            inputFile >> stopLocation;
            stops.push_back(landmarkMap[stopLocation]);
        }
        allLandMarks.push_back(stops);
    }
    inputFile.close();
}

std::vector<TaxiServices::Node> TaxiServices::findNeighbor(TaxiServices::Node &currentState) {

    std::vector<Node> localNeighbors(allLandMarks.size());

    for (int i = 0; i < allLandMarks.size(); i++) {
        Node current_nbr = GOAL;
        for (int j = 0; j < NUM_LANDMARKS - 1; j++) {
            if (getSpecificBit(currentState, j)) {
                setSpecificBit(current_nbr, allLandMarks.at(i).at(j));
            }
        }

        localNeighbors.at(i) = current_nbr;
        totalEdgeWeight[std::make_pair(currentState, current_nbr)] = transitInformation.at(i);
    }
    return localNeighbors;
}

void TaxiServices::calculateShortestPath(TaxiServices::Node source) {
    /* Use Dijktra Algorithm to find shortest path */
    distance[source] = 0;
    std::priority_queue<pin, std::vector<pin>, std::greater<>> to_visit;
    to_visit.push(std::make_pair(0, source));
    Node x;
    while (!to_visit.empty()) {
        x = to_visit.top().second;
        to_visit.pop();

        if (x == GOAL) {
            return;
        }
        for (Node &n : findNeighbor(x)) {
            double weight = totalEdgeWeight[std::make_pair(x, n)].first;
            if (distance[x] + weight < distance[n]) {
                distance[n] = distance[x] + weight;
                predecessors[n] = x;
                to_visit.push(std::make_pair(distance[n], n));
            }
        }
    }
}

bool TaxiServices::getSpecificBit(int value, int bit) {
    return (value >> bit) & 1;
}

void TaxiServices::setSpecificBit(int &value, int bit) {
    value = value | (1 << bit);
}

double TaxiServices::printPath(Node start, Node end) {
    double returnValue = 0;
    auto weightEntry = totalEdgeWeight[std::make_pair(predecessors[end], end)];

    if (start != end) {
        returnValue = printPath(start, predecessors[end]);
        std::cout << weightEntry.second << std::endl;
    }
    return returnValue + weightEntry.first;
}

void TaxiServices::buildGraph() {
    for (int i = 0; i < START; i++) {
        distance.push_back(LARGE_VAL);
        neighbors.emplace_back();
        predecessors.push_back(-1);
    }
}

void TaxiServices::determineShortestPath() {
    buildGraph();
    calculateShortestPath(START);
    std::cout << printPath(START, GOAL) << std::endl;
}

