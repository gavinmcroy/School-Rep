//
// Created by Gavin Taylor Mcroy on 12/4/20.
//
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <limits>

#ifndef PLEASEWORK_TAXISERVICES_H
#define PLEASEWORK_TAXISERVICES_H


class TaxiServices {
    const int NUM_LANDMARKS = 16;
    const int START = 65535;
    const int GOAL = 32768;
    const int LARGE_VAL = std::numeric_limits<int>::max();
private:

    typedef int Node;
    typedef std::pair<Node,Node> nodePair;
    typedef std::pair<double,Node> pin;

    std::vector<std::vector<Node>> neighbors;
    std::vector<Node> predecessors;
    std::vector<double> distance;
    std::map<nodePair, std::pair<double,std::string>> totalEdgeWeight;

    std::vector<std::vector<int>> allLandMarks;
    std::vector<std::pair<double,std::string>> transitInformation;
    std::unordered_map<std::string,int> landmarkMap;

    void readLandMarks(const std::string &placesFile);

    void readTransitInformation(const std::string &transitFile);

    std::vector<Node> findNeighbor(Node &currentState);

    void buildGraph();

    void calculateShortestPath(Node source);

    static bool getSpecificBit(int value , int bit);

    static void setSpecificBit(int &value, int bit);

    double printPath(Node start, Node end);



public:
    TaxiServices(const std::string &placesFile, const std::string &transitFile);

    void determineShortestPath();
};


#endif //PLEASEWORK_TAXISERVICES_H
