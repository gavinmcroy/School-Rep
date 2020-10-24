//
// Created by Gavin McRoy on 10/21/2020.
//
#include <iostream>
#include "NQueenSolver.h"

int tmp = 0;

NQueenSolver::NQueenSolver(int size) {
    this->size = size;
    index = size - 1;
    totalSolutionsDetected = 0;
    symmetryValue = size;

    if (size % 2 == 1) {
        symmetryValue = 0; /* */
    } else {
        symmetryValue = size / 2;
    }

    board = new char *[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
}

/* Solves the N queen problem (input 0 for start) */
int NQueenSolver::check_row(int row) {
    if (row == size) {
        /* Condition for a odd #pivot */
        totalSolutionsDetected++;
        return 0;
    }
    //if(isValid())
    for (int c = 0; c < size; c++) {
        if (isValid(row, c)) {
            board[row][c] = 'X';
            check_row(row + 1);
            board[row][c] = '-';
        }
    }
}

/* Checks if a queens placement is valid */
bool NQueenSolver::isValid(const int r, const int c) {

    /* Detect for vertical and horizontal */
    for (int i = 0; i < size; i++) {
        /* Horizontal */
        if (board[i][c] == 'X') {
            return false;
        }
        /* Vertical */
        if (board[r][i] == 'X') {
            return false;
        }
    }

    /* Check right diagonal given position (r,c) Starts bottom right */
    int columns = 0;
    int start = r + c;
    /* Protects bounds on board */
    if (start > index) {
        columns = start - index;
        start = index;
    }
    for (int i = start; i >= 0; i--) {
        if (board[i][columns] == 'X') {
            return false;
        }
        if (columns == index) {
            break;
        }
        columns++;
    }

    /* Detect for left diagonals given position (r,c)  Starts top left */
    columns = r + c;
    /* Protects bounds on board */
    if (r > c) {
        start = r - c;
        columns = 0;
    } else if (columns > index) {
        start = 0;
        columns = abs(c - r);
    } else {
        start = 0;
        columns = c - r;
    }
    for (int i = start; i < size; i++) {
        if (board[i][columns] == 'X') {
            return false;
        }
        if (columns == index) {
            break;
        }
        columns++;
    }
    return true;
}

int NQueenSolver::get_solution() {
    return totalSolutionsDetected;
}