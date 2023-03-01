#include <stdio.h>
#include<stdbool.h>

int main() {
    /**  Lab04.c
 *  Author: Gavin McRoy
 *  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
 *  Lab #: 4
 *  submitted on: 9/17/2019
 *  Purpose: Takes a set of values and determines if the values entered correspond to a magic square
 *  Academic Honesty Declaration: *  The following code represents my own
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  * I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
*/
    int magicNumber = 15;
    bool isMagic = true;
    int num[9];

    //---Calculate Array Size
    int length = sizeof(num) / sizeof(int);

    for (int i = 0; i < length; i++) {
        printf("Enter number #%d\n", i + 1);
        scanf("%d", &num[i]);
    }


    printf("You entered: \n");
    printf("%d %d %d\n", num[0], num[1], num[2]);
    printf("%d %d %d\n", num[3], num[4], num[5]);
    printf("%d %d %d\n", num[6], num[7], num[8]);
    printf("\nAnalyzing...\n");

    //---Rows
    if (num[0] + num[1] + num[2] != magicNumber) {
        printf("Row #1 [%d,%d,%d,] does not work!\n", num[0], num[1], num[2]);
        isMagic = false;
    }
    if (num[3] + num[4] + num[5] != magicNumber) {
        printf("Row #2 [%d,%d,%d,] does not work!\n", num[3], num[4], num[5]);
        isMagic = false;
    }
    if (num[6] + num[7] + num[8] != magicNumber) {
        printf("Row #3 [%d,%d,%d,] does not work!\n", num[6], num[7], num[8]);
        isMagic = false;
    }
    //---Columns
    if (num[0] + num[3] + num[6] != magicNumber) {
        printf("Column #1 [%d,%d,%d,] does not work!\n", num[0], num[3], num[6]);
        isMagic = false;
    }
    if (num[1] + num[4] + num[7] != magicNumber) {
        printf("Column #2 [%d,%d,%d,] does not work!\n", num[1], num[4], num[7]);
        isMagic = false;
    }
    if (num[2] + num[5] + num[8] != magicNumber) {
        printf("Column #3 [%d,%d,%d,] does not work!\n", num[2], num[5], num[8]);
        isMagic = false;
    }
    //---Diagonal
    if (num[0] + num[4] + num[8] != magicNumber) {
        printf("Diagonal Left to Right [%d,%d,%d,] does not work!\n", num[0], num[3], num[8]);
        isMagic = false;
    }
    if (num[2] + num[4] + num[5] != magicNumber) {
        printf("Diagonal Right to Left [%d,%d,%d,] does not work!\n", num[2], num[4], num[5]);
        isMagic = false;
    }

    //---IF magic print else not magic
    (isMagic) ? printf("This is a magic Square! ") : printf("This is not a magic square!");

}