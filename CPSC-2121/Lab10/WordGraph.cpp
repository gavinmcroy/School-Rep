//
// Created by Gavin McRoy on 11/14/2020.
//
#include <iostream>
#include <fstream>
#include "WordGraph.h"

WordGraph::WordGraph(const std::string &fileName) {
    std::fstream inputFile;
    inputFile.open(fileName);
    allWords.reserve(25000);

    if (inputFile.fail()) {
        std::cout << "File error" << std::endl;
        exit(1);
    }

    std::string buffer;
    int counter = 0;
    while (inputFile >> buffer) {
        stringSet.insert(buffer,counter);
        allWords.push_back(buffer);
        counter++;
    }
    inputFile.close();

}

void WordGraph::generateAdjacencyList() {
    for (auto word : allWords) {
        std::vector<Node> oneWordDifference;
        /* print out all words that differ by exactly one character */
        std::string searchedWord = word;
        for (unsigned int i = 0; i < word.size(); i++) {
            char temp = word[i];
            for (char j = 'a'; j <= 'z'; j++) {
                word[i] = j;
                if (stringSet.find(word) && (word != searchedWord)) {
                    oneWordDifference.push_back(word);
                }
            }
            word[i] = temp;
        }
        neighbors.insert(std::make_pair(word, oneWordDifference));
    }
    std::vector<std::string> s = neighbors["grape"];

    for (auto &i : s) {
        std::cout << i << std::endl;
    }

    std::cout << "Dictionary Loaded" << std::endl;
}

std::pair<int,int> WordGraph::convertWordIntoIndex(const std::string& begin, const std::string& ending) {
    start = stringSet[begin];
    end = stringSet[ending];
    return std::make_pair(stringSet[begin],stringSet[ending]);
}

//void WordGraph::breadthFirstSearch(int i, int j) {
//    if(i==)
//}
