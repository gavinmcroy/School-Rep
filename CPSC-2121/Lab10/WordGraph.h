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

    std::map <Node,bool> beenThere;
    std::map <Node,Node> predecessor;
    std::map<Node,std::vector<Node>> neighbors;

public:
    /* Reads file in */
    WordGraph(const std::string& fileName);


    void generateAdjacencyList();

    bool visit(const Node& myVal);

//    std::pair<int,int> convertWordIntoIndex(const std::string& start, const std::string& end);
//
//    void breadthFirstSearch(int i, int j);

    void printPath(Node x, Node y);

    void readInputFromUser();

    std::string getStart();


};


#endif //LAB10_WORDGRAPH_H
