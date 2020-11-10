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
            ratio = 0;
        }

        Candy &operator=(const Candy &c) = default;
    };

    struct Bag {
        std::vector<Candy> bag;
        int currentWeight;
        int currentTastiness;
        static const int MAX_WEIGHT = 2000;

        Bag() {
            currentWeight = 0;
            currentTastiness = 0;
        }
    };

    int tastinessOverall;
    std::vector<int> uniqueSolutions;
    std::vector<Candy> candy;
    std::vector<Bag> bagCollection;

    explicit HalloweenOptimization(std::string &fileName);

    int greedyImplementation();

    int refineImplementation();

    int prunedExhaustiveSearch(unsigned int start);

    void resetForPrune();

    int findMax();

    void debugPrintStatements();

    int calculationOptimizer() const;

    static void outputToFile(const std::string& fileHeaderName, std::vector<Bag> &optimalBag);

private:
    const int NUM_BAGS = 4;

    void randomizeCandy(std::vector<Candy> &c);

    int calculateCandyTastiness();

    int calculateCandyTastinessO();

    bool isValid(unsigned int bagIndex, unsigned int candyIndex);

};


#endif //PROJECT_3_HALLOWEENOPTIMIZATION_H
