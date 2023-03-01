#include <stdio.h>

int main() {

    /*
     Write a program that prompts the user to enter an integer value.

     The program should then output a message saying whether the number is positive, negative, or zero.
     For Example:

    Enter a number: 1

    The number you entered is 1.
    The number is positive.

    -------------------------------

    Enter a number: -1

    The number you entered is -1.
    The number is negative.

    -------------------------------

    Enter a number: 0

    The number you entered is 0.
    The number is zero.
     */
    int val = 0;
    printf("Enter a number: \n");
    scanf("%d", &val);
    printf("The number you entered is %d.\n", val);
    if (val >= 1) {
        printf("The number is positive. ");
    } else if (val <= -1) {
        printf("The number is negative. ");
    } else {
        printf("The number is zero. ");
    }
    return 0;
}