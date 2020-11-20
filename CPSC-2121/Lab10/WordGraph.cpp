//
// Created by Gavin McRoy on 11/14/2020.
//
#include <iostream>
#include <fstream>
#include <queue>
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
        stringSet.insert(buffer, counter);
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

//    std::vector<std::string> s = neighbors["grape"];
//    for (auto &i : s) {
//        std::cout << i << std::endl;
//    }

    std::cout << "Dictionary Loaded" << std::endl;
}


std::string WordGraph::breadthFirstSearch(const Node &source) {
    for (const Node &a : allWords) {
        distance[a] = allWords.size();
    }
    distance[source] = 0;
    queue<Node> toVisit;
    toVisit.push(source);

    string lastVisisted = "";

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        lastVisisted = x;
        toVisit.pop();
        for (const Node &n : neighbors[x]) {
            if (distance[n] == allWords.size()) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }
    }
    return lastVisisted;
}

std::vector<int> values;
int val = 0;

int WordGraph::findLongest() {
    distance.clear();
    val = 0;
    predecessor.clear();

    for (int i = 0; i < allWords.size(); i++) {
        string tmp = breadthFirstSearch(allWords.at(i));
        val = distance[tmp];
        values.push_back(val);
        distance.clear();
        predecessor.clear();
    }

    int max = -1;
    for (int i = 0; i < values.size(); i++) {
        if (values.at(i) > max) {
            max = values.at(i);
        }
    }
    return max;
}
//
//int WordGraph::calcDistance() {
//    //if(y.empty()) return;
//    if (x != y) {
//        printPath(x, predecessor[y]);
//        std::cout << predecessor[y] << std::endl;
//    }
//}

void WordGraph::readInputFromUser() {
    std::cout << "Enter starting position " << std::endl;
    std::cin >> start;
    std::cout << "Enter goal position" << std::endl;
    std::cin >> end;
}

std::string WordGraph::getStart() {
    return start;
}

std::string WordGraph::getGoal() {
    return end;
}


void WordGraph::printPath(const Node &x, const Node &y) {
    if (y.empty()) return;
    if (x != y) {
        val++;
        printPath(x, predecessor[y]);
        //std::cout <<val <<" " <<predecessor[y] << std::endl;
    }
}