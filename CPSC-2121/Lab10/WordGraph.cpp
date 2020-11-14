//
// Created by Gavin McRoy on 11/14/2020.
//
#include <iostream>
#include <fstream>
#include "WordGraph.h"

WordGraph::WordGraph(const std::string &fileName) {
    std::fstream inputFile;
    inputFile.open(fileName);
    if (inputFile.fail()) {
        std::cout << "File error" << std::endl;
        exit(2);
    }


}
