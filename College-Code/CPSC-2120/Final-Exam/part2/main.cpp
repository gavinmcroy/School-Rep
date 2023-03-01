#include <iostream>
#include "WordGraph.h"

int main() {
    WordGraph wordGraph("words5.txt");
    std::string start = "cruel";
    std::string goal = "final";


   // wordGraph.readInputFromUser();
    //start = wordGraph.getStart();
    //goal = wordGraph.getGoal();


    wordGraph.generateAdjacencyList();
    // wordGraph.breadthFirstSearch(start);
    // wordGraph.printPath(start, goal);


    //int x = wordGraph.findLongest();
    //std::cout << "Distance : " << x << std::endl;



    int x = wordGraph.printPath(start,goal);
    if(wordGraph.printPath(start,goal)==0){



        std::cout<<"No path"<<std::endl;
    }
    return 0;
}
