//
// Created by Gavin McRoy on 11/10/2020.
//
#include <iostream>
#include <algorithm>
#include <string>
#include "Jugs.h"

Jugs::Jugs() {
    processStepsTaken = new Jugs::ProcessingSolution("start", -1, -1, nullptr);
    states = nullptr;
    this->A = 0;
    this->B = 0;
    this->X = 0;
}

bool Jugs::solve(int j1Param, int j2Param, const std::string &previousMove) {
    int tempJ1;
    int tempJ2;

    /* Solution has been found */
    if (j1Param + j2Param == X) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    // other base case: been here before
    if (states[j1Param][j2Param].hasBeenThere) {
        return false;
    }

    // mark this state as visited
    states[j1Param][j2Param].hasBeenThere = true;

    /* Fill up jug 1(A) */
    if (solve(A, j2Param, "fill jug 1  ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    /* empty out jug 1(A) */
    if (solve(0, j2Param, "empty jug 1 ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    /* pour Jug 1(A) into Jug 2(B) */
    tempJ1 = j1Param;
    tempJ2 = j2Param;

    int jug2RemainingToFill = B - tempJ2;
    if (jug2RemainingToFill > tempJ1) {
        tempJ2 += tempJ1;
        tempJ1 = 0;
    } else {
        tempJ2 = B;
        tempJ1 -= jug2RemainingToFill;
    }

    if (solve(tempJ1, tempJ2, "pour 1->2   ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    /* Fill up jug 2(B) */
    if (solve(j1Param, B, "fill jug 2  ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    /* Empty out jug 2(B) */
    if (solve(j1Param, 0, "empty jug 2 ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    }

    /* Jug 2(B) into Jug 1(A) */
    tempJ1 = j1Param;
    tempJ2 = j2Param;

    int jug1RemainingToFill = A - tempJ1;
    if (jug1RemainingToFill >= tempJ2) {
        tempJ1 += tempJ2;
        tempJ2 = 0;
    } else {
        tempJ1 = A;
        tempJ2 -= jug1RemainingToFill;
    }

    if (solve(tempJ1, tempJ2, "pour 2->1   ")) {
        processStepsTaken = new ProcessingSolution(previousMove, j1Param, j2Param, processStepsTaken);
        return true;
    } else {
        return false;
    }
}

void Jugs::printOutSolutionBeautifully() {
    while (processStepsTaken->next != nullptr) {
        std::cout << processStepsTaken->move;
        std::cout << " [a=" << processStepsTaken->jug1;
        std::cout << ", b=" << processStepsTaken->jug2;
        std::cout << "]\n";
        processStepsTaken = processStepsTaken->next;
    }
}

void Jugs::getUserInput() {
    std::cout << "Enter A: ";
    std::cin >> A;
    std::cout << "Enter B: ";
    std::cin >> B;
    std::cout << "Enter X: ";
    std::cin >> X;
    std::cout << std::endl;

    /* if the desired amount of water is greater than the total capacity of both jugs return */
    if (X > A + B) {
        std::cout << "Impossible!\n";
        return;
    }

    allocateStates();

    /* solve and print solution unless no solution is found */
    if (solve(0, 0, "start")) {
        printOutSolutionBeautifully();
    } else {
        std::cout << "Impossible!\n";
    }
}

void Jugs::allocateStates() {
    /* create our 2D array of states */
    states = new State *[A + 1];
    for (int i = 0; i < A + 1; i++) states[i] = new State[B + 1];

    /* initialize each state's "been there" values to false */
    for (int a = 0; a < A; a++) {
        for (int b = 0; b < B; b++) {
            states[a][b].hasBeenThere = false;
        }
    }
}