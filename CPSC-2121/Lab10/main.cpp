#include <iostream>
#include "WordGraph.h"

int main() {
    WordGraph wordGraph("words5.txt");
    std::string start;
    std::string goal;


    wordGraph.readInputFromUser();
    start = wordGraph.getStart();


    wordGraph.generateAdjacencyList();
    wordGraph.breadthFirstSearch(start);
    wordGraph.markPath(start,goal);
    /* Mark path */
    return 0;
}
