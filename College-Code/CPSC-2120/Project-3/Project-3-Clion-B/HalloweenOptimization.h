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
        double ratio;
        bool hasVisited;

        Candy(int tastiness, int weight) {
            this->tastiness = tastiness;
            this->weight = weight;
            hasVisited = false;
        }

        Candy &operator=(const Candy &c) = default;
    };

    struct Bag {
        std::vector<Candy> bag;
        int currentWeight;
        static const int MAX_WEIGHT = 2000;

        Bag() {
            currentWeight = 0;
        }
    };

    std::vector<Candy> candy;
    std::vector<Bag> bagCollection;

    explicit HalloweenOptimization(std::string &s);

    int greedyImplementation();

    int refineImplementation();

    void debugPrintStatements();

private:
    const int NUM_BAGS = 4;

    void randomizeCandy(std::vector<Candy> &c);

    int calculateCandyTastiness();

    bool isInvalid(int index);

};


#endif //PROJECT_3_HALLOWEENOPTIMIZATION_H
