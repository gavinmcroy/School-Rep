//
// Created by Gavin McRoy on 4/21/2021.
//
#include <stdlib.h>
#include <math.h>
#include "diagonal.h"

int **readData(FILE *fp, int *size) {
    fscanf(fp, "%d", size);

    int **data = (int **) malloc(sizeof(int) * (*size));
    for (int i = 0; i < *(size); i++) {
        data[i] = (int *) malloc(sizeof(int) * (*size));
    }

    for (int i = 0; i < *(size); i++) {
        for (int j = 0; j < *(size); j++) {
            fscanf(fp, "%d", &data[i][j]);
        }
    }
    return data;
}

void calculateDiagonal(int sz, int **mat) {
    int val = 0;

    //---For top left to bottom right
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (i == j) {
                val += mat[i][j];
            }
        }
    }
    printf("left:%d\n", abs(val));
    val = 0;
    //---For top right to bottom left
    int reverse = 0;
    for (int i = sz - 1; i >= 0; i--) {
        val += mat[i][reverse];
        reverse++;
    }
    printf("right:%d\n", abs(val));
}
