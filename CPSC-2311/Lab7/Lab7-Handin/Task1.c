#include<stdio.h>

/************************** /
 * Gavin McRoy
 * CPSC2310 Lab7
 * UserName:  gmcroy
 * Lab Section:  002
/*************************/

int main() {
    /*Fill in a C expression that evaluates to 1 when the follow conditions are
     *true and to 0 when they are false.  Assume the value is of type int. 
     *Your code MUST follow the Rules described in the lab document. With the
     *additional restriction that you may not use equality (==) or inequality
     *(!=) test. */

    //Part A:  
    printf("1.\n");
    int a = 0;
    printf("prints 1 when any bit of a number equals 1 %d\n", !!a);
    a = 1;
    printf("prints 1 when any bit of a number equals 1 %d\n", !!a);

    //Part B:
    printf("\n2.\n");
    int b = -1;
    printf("prints 1 when any bit of a number equals 0 %d\n", !!(b & 0xF));
    b = 1;
    printf("prints 1 when any bit of a number equals 0 %d\n", !!(b & 0xF));

    //Part C:
    printf("\n3.\n");
    int c = 1;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", !!(c << 24) );
    c = 0;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n",!!(c << 24));

//    //Part D;
    printf("\n4.\n");
    int d = -1;
    //1000 1111 != 0
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !((d>>24) & 0xF) );
    d = 0;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !((d>>24) & 0xF) );

    return 0;
}
