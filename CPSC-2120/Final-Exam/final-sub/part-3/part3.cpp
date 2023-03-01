#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

/* I realized right when I finished writing this that you can probably do a much faster implementation
 * with a BST using keys corresponding to frequencies. The tree would print itself from least to greatest
 * but there are many ways to work around that */


bool sortbysec(const std::pair<int, int> &a,
               const std::pair<int, int> &b) {
    return (a.second < b.second);
}


int main() {
    std::unordered_map<int, int> myMap;
    std::pair<int, int> myPair;
    myMap.insert(myPair);


    int input;
    std::vector<int> uniqueInput;
    std::vector<std::pair<int, int>> ordered;

    while (std::cin >> input) {
        if (myMap.find(input) == myMap.end()) {
            uniqueInput.push_back(input);
            myMap.insert(std::make_pair(input, 1));
        } else {
            int tmp = myMap[input];
            tmp++;
            myMap[input] = tmp;
        }
    }
    ordered.reserve(uniqueInput.size());
    for (int &i : uniqueInput) {
        ordered.emplace_back(i, myMap[i]);
    }
    std::sort(ordered.begin(), ordered.end(), sortbysec);
    for (unsigned int i = ordered.size() - 1; i >= 0; i--) {
        std::cout << ordered.at(i).first << std::endl;
    }
    return 0;
}
