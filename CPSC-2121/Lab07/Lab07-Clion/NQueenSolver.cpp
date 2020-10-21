//
// Created by Gavin McRoy on 10/21/2020.
//
#include <iostream>
#include "NQueenSolver.h"

NQueenSolver::NQueenSolver(int size){
    this->size = size;
    count = 0;
    board = new char*[size];
    for(int i = 0; i < size; i++){
        board[i] = new char[size];
    }
}

/* Solves the N queen problem (input 0 for start) */
int NQueenSolver::check_row(int row){
    if(row == size){
        count++;
        return 0;
    }
    for(int c = 0; c < size; c++){
        board[row][c];
    }
    /* Put queen at (r,c) */
    /* check_row(row+1)*/
    
    return check_row(row + 1);
}

/* Checks if a queens placement is valid */
bool NQueenSolver::isValid(int r, int c){
    return true;
}