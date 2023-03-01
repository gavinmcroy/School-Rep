#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

    /*
*  string_manipulator.c
*  Author: Gavin McRoy
*  Lecture, Lab Section: CPSC 1010-100, CPSC 1011-100-005
*  Lab #: 8
*  submitted on: 10/25/2019
*  Purpose: Simple string manipulation where the user can replace
*  characters in an array with any character they want
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

void replaceAll(char userArray[]);

int main() {
    char userArray[128];
    char userOption[128];


    printf("Enter a string (up to 25 characters) to be transformed: ");
    fgets(userArray, 32, stdin);

    while (true) {

        printf("Enter your command(quit, replace all): ");
        fgets(userOption, 32, stdin);
        fflush(stdin);

        userOption[strlen(userOption) - 1] = '\0';

        for (int i = 0; i < strlen(userOption); i++) {
            if (userOption[i] == '\n') {
                userOption[i] = '\0';
            }
        }


        for (int i = 0; i < strlen(userOption); i++) {
            userOption[i] = toupper(userOption[i]);
        }
        if (strcmp(userOption, "QUIT") == 0) {
            return 1;
        } else if (strcmp(userOption, "REPLACE ALL") == 0) {
            replaceAll(userArray);
        } else {
            printf("Sorry, that command is invalid. Please type one of the options.\n");

        }
    }

}

void replaceAll(char userArray[]) {
    bool isInString = false;
    char charToReplace = ' ';
    char newChar = ' ';
    printf("Enter the character to replace: ");
    scanf("%c", &charToReplace);
    for (int i = 0; i < strlen(userArray); i++) {
        if (userArray[i] == charToReplace) {
            isInString = true;
        }
    }
    if (!isInString) {
        char tmp = ' ';
        printf("Error, %c is not in the string.\n", charToReplace);
        fflush(stdin);
        return;
    }
    printf("Enter the new character: ");
    scanf(" %c", &newChar);
    for (int i = 0; i < strlen(userArray); i++) {
        if (userArray[i] == charToReplace) {
            userArray[i] = newChar;
        }
    }
    printf("Your new sentence is: %s\n", userArray);
    fflush(stdin);
}
