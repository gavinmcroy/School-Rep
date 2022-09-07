#include <stdio.h>
#include <stdlib.h>

#ifndef LAB_2
#define LAB_2

/* Parameters: input - the file to be checked
 * Return:        Nothing
 * Description: This function makes sure that the file desired to be read was successfully opened,
 * if not it notifies the user and terminates the program
 */
void checkFile(FILE *);

/* Parameters: args - the total number of arguments passed on the command line
 * Return:        Nothing
 * Description: This function checks to see if there was a sufficient number of arguments entered on the command line
 * if not the program notifies the user and terminates.
 */
void checkArguments(int);

/* Parameters: input - contains the file to be checked
 * Return:        Nothing
 * Description: This function takes in a file and reads each character to make sure that for each
 * opening brace there is another closing brace. It then prints out how many opening braces had a corresponding
 * closing brace. If there is a closing brace before a opening brace it notifies the user with a message.
 */
void checkBraces(FILE *);

#endif
