/** Include file for nibble routines */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/*********************
 * Gavin McRoy
 * CPSC 2310 Lab 4
 * gmcroy
 * Lab Section - 002
 *********************/

unsigned int nget(unsigned int val, int position);

unsigned int nset(unsigned int val, unsigned int nVal, int position);

unsigned int nlrotate(unsigned int val);

#endif
