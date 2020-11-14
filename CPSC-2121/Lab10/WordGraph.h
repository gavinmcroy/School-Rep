//
// Created by Gavin McRoy on 11/14/2020.
//
#include <map>
#include <vector>
#ifndef LAB10_WORDGRAPH_H
#define LAB10_WORDGRAPH_H


class WordGraph {

private:

    typedef std::string Node;
    std::map <bool,bool> beenThere;
    std::map <Node,Node> predecessor;
    std::map<Node,std::vector<Node>> neighbors;

public:
    WordGraph(const std::string& fileName);


};


#endif //LAB10_WORDGRAPH_H
