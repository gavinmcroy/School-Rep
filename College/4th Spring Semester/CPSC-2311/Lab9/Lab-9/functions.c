/*********************
 * Gavin McRoy
 * CPSC 2310 Lab 9
 * gmcroy
 * Lab Section - 002
 *********************/
#include "functions.h"
#include <limits.h>

/*
 * absValue - returns the absolute value of x
 *   Example: absValue(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absValue(int val) {
    int const mask = val >> (28);
    return ((val + mask) ^ mask);
}

/*
 * binaryAnd - x&y using only ~ and |
 *   Example: binaryAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binaryAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * binaryNotOr - ~(x|y) using only ~ and &
 *   Example: binaryNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binaryNotOr(int x, int y) {
    int test = ~(~x & ~y);
    return ~test;
}

/*
 * binaryOr - x|y using only ~ and &
 *   Example: binaryOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binaryOr(int x, int y) {
    return ~(~x & ~y);
}

/*
 * binaryXor - x^y using only ~ and &
 *   Example: binaryXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binaryXor(int x, int y) {
    int test = ~(~x & ~y);
    int val = ~(x & y);
    return test & val;
}

/*
 * unsignedAddOk - determines if two unsigned int's can be added
 * without an overflow
 * Legal ops: all
 */

int unsignedAddOK(unsigned x, unsigned y) {
    if (UINT_MAX - x <= y) {
        return 0;
    }
    return x + y;
}

/*
 * twosAddOk - determines if two int's can be added
 * without an overflow
 * Legal ops: all
 */

int twosAddOk(int x, int y) {
    if ((x < 0 && y < 0 && x + y >= 0) || (x >= 0 && y >= 0 && x + y < 0)) {
        return 0;
    }
    return x + y;
}


/*
 *  int twosSubOk - Determine whether arguments can be subracted
 *  without overflow
 *  Legal ops: all
 */

int twosSubtractOK(int x, int y) {
    if (x > y) {
        if (y - x > 0) {
            return 0;
        }
    } else {
        if (x - y > 0) {
            return 0;
        }
    }
    return x - y;
}

