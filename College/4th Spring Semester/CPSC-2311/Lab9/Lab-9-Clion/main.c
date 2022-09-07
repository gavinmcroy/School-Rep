#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "functions.h"

/*********************
 * Gavin McRoy
 * CPSC 2310 Lab 9
 * gmcroy
 * Lab Section - 002
 *********************/

int main() {

    printf("absValue -> TEST %d\n", absValue(-1));
    printf("Real thing %d\n", -1 * -1);
    assert(absValue(-1) == (-1 * -1));
    printf("\n");

    printf("binaryAnd -> TEST %d\n", binaryAnd(3345, 5));
    printf("Real thing %d\n", 3345 & 5);
    assert(binaryAnd(3345, 5) == (3345 & 5));
    printf("\n");

    printf("binaryNotOR -> TEST %d\n", binaryNotOr(15, 3));
    printf("Real thing %d\n", ~(15 | 3));
    assert(binaryNotOr(15, 3) == ~(15 | 3));
    printf("\n");

    printf("binaryOR -> TEST %d\n", binaryOr(3335, 5));
    printf("Real thing %d\n", (3335 | 5));
    assert(binaryOr(3335, 5) == (3335 | 5));
    printf("\n");

    printf("BinaryXor -> TEST %d\n", binaryXor(4556, 5));
    printf("Real thing %d\n", 4556 ^ 5);
    assert(binaryXor(4556, 5) == (4556 ^ 5));
    printf("\n");

    printf("unsignedAddOk -> TEST %d\n", unsignedAddOK(UINT_MAX - 1, 14));
    printf("Should be %d\n", 0);
    assert(unsignedAddOK(UINT_MAX - 1, 14) == 0);
    printf("\n");

    printf("twosAddOk -> TEST %d\n", twosAddOk(INT_MAX - 2, 23));
    printf("Should be 0\n");
    assert(twosAddOk(INT_MAX - 2, 23) == 0);
    printf("\n");

    printf("twosSubstractOk -> TEST %d\n", twosSubtractOK(INT_MIN + 3, 435));
    printf("Should be 0\n");
    assert(twosSubtractOK(INT_MIN + 3, 435) == 0);
    printf("\n");

    return 0;
}
