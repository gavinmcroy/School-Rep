#include <iostream>
#include "NQueenSolver.h"

/* X represents position of queen on the board */

void debugIsValid(int r, int c);

int main(int argv, char *argc[]) {
    /* Change to take command line input */
    int argument = atoi(argc[1]);
    debugIsValid(7, 7);
    NQueenSolver nQueenSolver(14);
    nQueenSolver.check_row(0);
    std::cout << "Unique Solutions: " << nQueenSolver.get_solution();
    return 0;
}

void debugIsValid(const int r, const int c) {
    const int SIZE = 9;
    const int index = SIZE - 1;
    char board[SIZE][SIZE] = {};
    // const int r = 0;
    //const int c = 5;

    int columns = 0;
    /* Creates right diagonal on board */
//    for (int i = SIZE - 1; i >= 0; i--) {
//        board[i][columns] = 'X';
//        columns++;
//    }
    /* Creates left diagonal on board */
    columns = 0;
//    for (int i = 0; i < SIZE; i++) {
//        board[i][columns] = 'X';
//        columns++;
//    }

    /* Fill in all empty elements with other character */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X') {
                board[i][j] = '-';
            }
        }
    }

    /* Detect for vertical */

    for (int i = 0; i < SIZE; i++) {
//        if (board[i][c] == 'X') {
//            std::cout << "DETECTION VERTICAL " << std::endl;
//            break;
//        }
//        if (board[r][i] == 'X') {
//            std::cout << "DETECTION HORIZONTAL " << std::endl;
//            break;
//        }
        board[i][c] = 'X';
        board[r][i] = 'X';
    }

    /* Detect for right diagonals given position (r,c) */
    columns = 0;
    int start = r + c;
    /* Protects bounds on board */
    if (start > index) {
        columns = start - index;
        start = index;
    }
    for (int i = start; i >= 0; i--) {
//        if (board[i][columns] == 'X') {
//            std::cout << "DETECTION RIGHT DIAGONAL " << std::endl;
//            break;
//        }
        board[i][columns] = 'X';
        if (columns == index) {
            break;
        }
        columns++;
    }
    /* Detect for left diagonals given position (r,c)  Starts top left */
    /* columns = start - 8;
       start = 8;
    */
    columns = r + c;
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
    for (int i = start; i < SIZE; i++) {
        //std::cout<<board[i][c];
//        if (board[i][columns] == 'X') {
//            std::cout << "DETECTION LEFT DIAGONAL " << std::endl;
//            break;
//        }
        board[i][columns] = 'X';
        if (columns == index) {
            break;
        }
        columns++;
    }


    /* Print Board */
    std::cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
