#include <iostream>
#include "WordGraph.h"

int main() {
    WordGraph wordGraph("words5.txt");
    std::string start;
    std::string goal;


    wordGraph.readInputFromUser();
    start = wordGraph.getStart();
//    std::pair<int,int> myPair = wordGraph.convertWordIntoIndex(start,goal);
//    std::cout<<myPair.first <<" " << myPair.second <<std::endl;
    wordGraph.generateAdjacencyList();
    if (wordGraph.visit(start)) {
        std::cout << "Solution Detected" << std::endl;
    } else {
        std::cout << "No Solution Detected " << std::endl;
    }


//    wordGraph.breadthFirstSearch(myPair.first,myPair.second);
    return 0;
}
