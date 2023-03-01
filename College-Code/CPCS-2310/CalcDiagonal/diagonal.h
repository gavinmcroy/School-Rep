//
// Created by Gavin McRoy on 4/21/2021.
//
#include <stdio.h>

#ifndef CALCDIAGONAL_DIAGONAL_H
#define CALCDIAGONAL_DIAGONAL_H

int** readData(FILE* fp, int* size);

void calculateDiagonal(int sz, int** mat);


#endif //CALCDIAGONAL_DIAGONAL_H
