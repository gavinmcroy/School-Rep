//
// Created by Gavin McRoy on 10/21/2020.
//
#include <iostream>
#include "NQueenSolver.h"

NQueenSolver::NQueenSolver(int size) {
    this->size = size;
    count = 0;
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
        count++;
        return 0;
    }
    for (int c = 0; c < size; c++) {
        board[row][c];
    }
    /* Put queen at (r,c) */
    /* check_row(row+1)*/

    return check_row(row + 1);
}

/* Checks if a queens placement is valid */
bool NQueenSolver::isValid(const int r, const int c) {
    //---Check Vertical
    for (int i = 0; i < size; i++) {
        if(board[i][c]=='X'){
            return false;
        }
        /*for (int j = i + 1; j < size; j++) {
            if (board[j][c] == 'X') {
                return false;
            }
        } */
    }
    //---Check horizontal
    for (int i = 0; i < size; i++) {
        if(board[r][i]=='X'){
            return false;
        }
        /*
        for (int j = i + 1; j < size; j++) {
            if (board[r][j] == 'X') {
                return false;
            }
        } */
    }
    //---Check diagonal
    int y = c;
    for (int i = r; i >= 0; i--) {
        if (board[i][y] == 'X') {
            // std::cout<<"DETECTION RIGHT DIAGONAL "<<std::endl;
            return false;
        }
        y++;
    }
    /* Detect for left diagonals given position (r,c) */
    y = c;
    for (int i = r; i < size; i++) {
        if (board[i][y] == 'X') {
            //std::cout<<"DETECTION LEFT DIAGONAL "<<std::endl;
            return false;
        }
        y++;
    }
    return true;
}