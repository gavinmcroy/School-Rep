//
// Created by Gavin McRoy on 11/14/2020.
//
#include <iostream>
#include <fstream>
#include <queue>
#include "WordGraph.h"

std::vector<std::string> solutionAll;
std::vector<std::string> solutionMain;

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

    string lastVisited;

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        lastVisited = x;
        toVisit.pop();
        for (const Node &n : neighbors[x]) {
            if (distance[n] == allWords.size()) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }
    }
    return lastVisited;
}

std::vector<int> values;
int val = 0;

int WordGraph::findLongest() {
    distance.clear();
    predecessor.clear();
    solutionAll.clear();
    int max = 0;

    for (auto &allWord : allWords) {
       // solutionMain.clear();
        string tmp = breadthFirstSearch(allWord);
        val = distance[tmp];
        if (val > max) {
            printPath(allWord, tmp);
            solutionMain = solutionAll;
            max = val;
        }
        values.push_back(val);
        distance.clear();
        predecessor.clear();
        solutionAll.clear();
    }

   for( auto & word : solutionMain){
       std::cout<<word<<std::endl;
   }

    return max;
}

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


int WordGraph::printPath(const Node &x, const Node &y) {
    //if (y.empty()) return;
    if (x != y) {
        //val++;
        solutionAll.push_back(predecessor[y]);
        printPath(x, predecessor[y]);
        //std::cout <<val <<" " <<predecessor[y] << std::endl;
    }
    return val;
}