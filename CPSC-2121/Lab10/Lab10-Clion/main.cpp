#include <iostream>
#include "WordGraph.h"

int main() {
    WordGraph wordGraph("words5.txt");
    std::string start;
    std::string goal;


   // wordGraph.readInputFromUser();
    //start = wordGraph.getStart();
    //goal = wordGraph.getGoal();


    wordGraph.generateAdjacencyList();
    // wordGraph.breadthFirstSearch(start);
    // wordGraph.printPath(start, goal);


    int x = wordGraph.findLongest();
    std::cout << "Distance : " << x << std::endl;
    /* Mark path */
    return 0;
}
