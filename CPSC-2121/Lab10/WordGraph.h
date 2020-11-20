//
// Created by Gavin McRoy on 11/14/2020.
//
#include <map>
#include <vector>
#include "StringIntMap.h"

#ifndef LAB10_WORDGRAPH_H
#define LAB10_WORDGRAPH_H


class WordGraph {

private:

    StringIntMap stringSet;
    std::vector<std::string> allWords;

    typedef std::string Node;
    Node start;
    Node end;

    std::map<Node, int> distance;

    std::map<Node, Node> predecessor;

    std::map<Node, std::vector<Node>> neighbors;

public:

    /* Reads file in */
    explicit WordGraph(const std::string &fileName);

    void generateAdjacencyList();

    void readInputFromUser();

    std::string getStart();

    std::string getGoal();

    std::string breadthFirstSearch(const Node &source);

    int findLongest();

    int calcDistance();

    void printPath(const Node &x, const Node &y);
};


#endif //LAB10_WORDGRAPH_H
