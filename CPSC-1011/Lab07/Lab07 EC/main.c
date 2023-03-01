#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    /*
*  decimalconverter.c
*  Author: Gavin McRoy
*  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
*  Lab #: 7
*  submitted on: 10/10/2019
*  Purpose: Converts binary digits into decimal numbers
*  Academic Honesty Declaration: * The following code represents my own
*  work and I have neither received nor given assistance that violates
*  the collaboration policy posted with this assignment. I have not copied
*  or modified code from any other source other than the lab
*  assignment, course textbook, or course lecture slides. Any unauthorized
*  collaboration or use of materials not permitted will be subjected to
*  academic integrity policies of Clemson University and CPSC 1010/1011.
*  I acknowledge that this lab assignment is based upon an assignment
*  created by Clemson University and that any publishing or
*  posting of this code is prohibited unless I
*  receive written permission from Clemson University.
*/

    char string[256];
    int integer[256];
    int increment = 0;
    int num = 0;

    do {
        printf("Enter binary digit with no spaces (feof to exit)");
        scanf("%s", string);

        //---Convert each char storing a binary digit into a integer and store into each element in the integer array
        for (int i = 0; i < strlen(string); i++) {
            char tmp = string[i];
            integer[i] = atoi(&tmp);
        }

        increment = strlen(string);
        int tmp = increment;

        //---converts binary into decimal number
        for (int i = 0; i < increment; i++) {
            if (integer[i] == 1) {
                num += (int) pow(2, tmp - 1);
            }
            tmp--;
        }

        printf("\nDecimal Number is: %d\n", num);

    } while (!feof(stdin));
    return 0;
}