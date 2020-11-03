//
// Created by Gavin McRoy on 11/3/2020.
//

#include <vector>


#ifndef PROJECT_3_HALLOWEENOPTIMIZATION_H
#define PROJECT_3_HALLOWEENOPTIMIZATION_H


class HalloweenOptimization {
public:

    struct Candy {
        int tastiness;
        int weight;
        bool hasVisited;

        Candy(int tastiness, int weight) {
            this->tastiness = tastiness;
            this->weight = weight;
            hasVisited = false;
        }
    };

    struct Bag {
        std::vector<Candy> bag;
        int currentWeight;
        const int MAX_WEIGHT = 2000;

        Bag() {
            currentWeight = 0;
        }
    };

    std::vector<Candy> candy;
    std::vector<Bag> bags;


    explicit HalloweenOptimization(std::string &s);

    int greedyImplementation();

private:
    const int NUM_BAGS = 3;

};


#endif //PROJECT_3_HALLOWEENOPTIMIZATION_H
