#include <stdio.h>
#include <assert.h>
#include "diagonal.h"


int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    assert(in != NULL);
    int sz = 0;
    int **data = readData(in, &sz);
    assert(data != NULL);
    calculateDiagonal(sz, data);

    return 0;
}
