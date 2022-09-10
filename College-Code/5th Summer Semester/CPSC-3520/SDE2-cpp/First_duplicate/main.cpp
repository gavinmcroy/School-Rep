#include <iostream>
#include <vector>

int findDupe(std::vector<int> &list);

int firstNonRepeating(std::vector<int> &list);

int main() {
    std::vector<int> myVec = {1, 2, 3, 4, 5, 6, 1};
    std::cout << findDupe(myVec) << std::endl;
    std::cout << firstNonRepeating(myVec) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findDupe(std::vector<int> &list) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = i; j < list.size(); j++) {
            if (j != i) {
                if (list.at(i) == list.at(j)) {
                    return list.at(i);
                }
            }
        }
    }
    return -1;
}

int firstNonRepeating(std::vector<int> &list) {
    bool state = true;
    for (int i = 0; i < list.size(); i++) {
        state = false;
        for (int j = i; j < list.size(); j++) {
            if (j != i) {
                if (list.at(i) == list.at(j)) {
                    state = true;
                }
            }
        }
        if (!state) {
            return list.at(i);
        }
    }
    return -1;
}


