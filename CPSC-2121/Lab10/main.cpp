#include <iostream>
#include "WordGraph.h"

int main() {
    WordGraph wordGraph("words5.txt");
    std::string start;
    std::string goal;


    std::cout << "Enter starting position " << std::endl;
    std::cin >> start;
    std::cout << "Enter goal position" << std::endl;
    std::cin >> goal;

    std::pair<int,int> myPair = wordGraph.convertWordIntoIndex(start,goal);
    std::cout<<myPair.first <<" " << myPair.second <<std::endl;
    wordGraph.generateAdjacencyList();
    wordGraph.breadthFirstSearch(myPair.first,myPair.second);
    return 0;
}
