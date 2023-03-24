//
// Created by Gavin McRoy on 11/10/2020.
//

#include <string>
#include <utility>

#ifndef PLS_WORK_JUGS_H
#define PLS_WORK_JUGS_H


class Jugs {
private:
    int A;
    int B;
    int X;

    struct State {
        bool hasBeenThere;

        State() {

            hasBeenThere = false;
        }
    };

    struct ProcessingSolution {
        std::string move;
        int jug1, jug2;
        ProcessingSolution *next;

        ProcessingSolution(std::string s, int a, int b, ProcessingSolution *n) {
            move = std::move(s);
            jug1 = a;
            jug2 = b;
            next = n;
        }
    };

    ProcessingSolution *processStepsTaken;

    State **states;

public:
    Jugs();

    bool solve(int j1Param, int j2Param, const std::string &previousMove);

    void printOutSolutionBeautifully();

    void getUserInput();

    void allocateStates();
};


#endif //PLS_WORK_JUGS_H
