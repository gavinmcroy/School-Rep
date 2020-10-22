#include <iostream>
#include "NQueenSolver.h"
#include "Hash.h"

/* X represents position of queen on the board */

int recursion(int x) {
    if (x > 100) {
        return 0;
    }
    // std::cout<<x<<std::endl;
    return x + 1;
}

void debugIsValid(int r, int c);

int main() {

    debugIsValid(5,7);
    NQueenSolver nQueenSolver(8);
    Hash hash;
    //std::cout<<nQueenSolver.check_row(0)<<std::endl;
    //std::cout<<recursion(0)<<std::endl;



    return 0;
}

void debugIsValid(const int r, const int c){
    const int SIZE = 9;
    char board[SIZE][SIZE] = {};
   // const int r = 0;
    //const int c = 5;

    int columns = 0;
    /* Creates right diagonal on board */
    for (int i = SIZE - 1; i >= 0; i--) {
        board[i][columns] = 'X';
        columns++;
    }
    /* Creates left diagonal on board */
    columns = 0;
    for (int i = 0; i < SIZE; i++) {
        board[i][columns] = 'X';
        columns++;
    }

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
        if (board[i][c] == 'X') {
            std::cout << "DETECTION VERTICAL " << std::endl;
            break;
        }
    }
    /* Detect for horizontal */
    for (int i = 0; i < SIZE; i++) {
        if (board[r][i] == 'X') {
            std::cout << "DETECTION HORIZONTAL " << std::endl;
            break;
        }
    }

    /* Detect for right diagonals given position (r,c) */
    columns = c;
    for (int i = r; i >= 0; i--) {
        //std::cout<<board[i][c];
        if (board[i][columns] == 'X') {
            std::cout << "DETECTION RIGHT DIAGONAL " << std::endl;
            break;
        }
        columns++;
    }
    /* Detect for left diagonals given position (r,c) */
    columns = c;
    for (int i = r; i < SIZE; i++) {
        //std::cout<<board[i][c];
        if (board[i][columns] == 'X') {
            std::cout << "DETECTION LEFT DIAGONAL " << std::endl;
            break;
        }
        if(columns == 0){
            break;
        }
        columns--;
    }


    /* Print Board */
    cout << "  ";
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
