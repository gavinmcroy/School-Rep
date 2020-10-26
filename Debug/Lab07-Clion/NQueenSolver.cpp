//
// Created by Gavin McRoy on 10/21/2020.
//
#include <iostream>
#include "NQueenSolver.h"

NQueenSolver::NQueenSolver(int size) {
    this->size = size;
    index = size - 1;
    totalSolutionsDetected = 0;

    if (size % 2 == 1) {
        isOdd = true;
    } else {
        isOdd = false;
    }
    /* Allocate memory for Size x Size board*/
    board = new char *[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }
    /* Assign empty positions denoted by '-' */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
}

int val = 0;

/* Solves the N queen problem (input 0 for start) */
int NQueenSolver::check_row(int row) {
    if (row == size) {
        /* Condition for a odd board size */
        if (!isOdd) {
            totalSolutionsDetected += 2;
        } else {
            totalSolutionsDetected++;
        }
        return 0;
    }
    for (int c = 0; c < size; c++) {
        /* Symmetry only for the first row */
        if (row == 0) {
            /* If the board is a odd number this prevents miscalculations from 7/2 = 3 by accounting
             * for the center part of the board meaning solutions are being ++ instead of +=2 */
            if (c == (size / 2) + 1) {
                isOdd = true;
            }
            if (c == size / 2 && !isOdd) {
                isOdd = false;
                break;
            }
        }
        /* Purge boards that are already invalid by checking if its a valid placement*/
        if (isValid(row, c)) {
            board[row][c] = 'X';
            check_row(row + 1);
            board[row][c] = '-';
        }
    }
    return 0;
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

    /* Check right diagonal given position (r,c) Starts bottom left. This works by
     * calculating the index (r,c) on the board for which the diagonal begins, it then checks if there
     * is any queens there (represented by X) */
    int columns = 0;
    int start = r + c;
    /* Protects bounds on board */
    if (start > index) {
        columns = start - index;
        start = index;
    }
//    for (int i = start; i >= 0; i--) {
//        /* Invalid position detected */
//        if (board[i][columns] == 'X') {
//            return false;
//        }
//        if (columns == index) {
//            break;
//        }
//        columns++;
//    }

    /* Detect for left diagonals given position (r,c)  Starts top left This works similarly to right
     * diagonal but comes with many more base conditions. Condition for if(r>c) its to the left of the center diagonal ()
     * which is the diagonal that cuts the board in half, else if columns > index is for if its on the right side of
     * the half way diagonal, else the the position is inside the half diagonal */
    int columns1 = r + c;
    int start1 = 0;
    /* Protects bounds on board and left of center diagonal*/
    if (r > c) {
        start1 = r - c;
        columns1 = 0;
    } /* To the right of center diagonal */
    else if (columns1 > index) {
        start1 = 0;
        columns1 = abs(c - r);
    }/* columns basically is columns = 0  */
    else {
        start1 = 0;
        columns1 = c - r;
    }

    int jCounter = start;
    for (int i = start1; i < size; i++) {
        /* Invalid position detected */
        if (start1 < jCounter) {
            break;
        }
        if (board[jCounter][columns] == 'X') {
            return false;
        }

        if (board[i][columns1] == 'X') {
            return false;
        }
        if (columns1 == index) {
            break;
        }
        if (columns == index) {
            break;
        }
        columns++;
        jCounter--;
        columns1++;
    }
    return true;
}

int NQueenSolver::get_solution() {
    /* Debug statement for reducing iterations inside for loops */
    std::cout << "Total Iterations" << val << std::endl;
    return totalSolutionsDetected;
}