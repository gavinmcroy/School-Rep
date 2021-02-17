/** CPSC 2310 Lab 4

    Nibble routines

    Nibbles are 4-bit parts of a 32 bit unsigned integer variable.  
    Nibbles are numbered 0-7 from left to right.

**/

/*********************
 * Gavin McRoy
 * CPSC 2310 Lab 4
 * gmcroy
 * Lab Section - 002
 *********************/


#include "functions.h"


unsigned int nget(unsigned int val, int position) {
    //--- Positions are 0-7, 28 is the highest possible number for keeping the left most hex value
    return val >> (28 - position * 4) & 0xf;
}

unsigned int nset(unsigned int val, unsigned int nVal, int position) {
    unsigned int mask = 0xf;
    mask = mask << (28 - (position * 4));
    mask = ~mask;
    unsigned int changedValue = val & mask;
    //---Shift n value into required nibble position
    nVal = nVal << (28 - (position * 4));
    changedValue = changedValue | nVal;
    return changedValue;
}

unsigned int nlrotate(unsigned int val) {
    unsigned int debug = val >> (28) & 0xf;
    val = val << 4;
    val = val | debug;
    return (val);
}
