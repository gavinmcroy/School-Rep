#include "functions.h"


/* Parameters: input - the file to be checked
 * Return:        Nothing
 * Description: This function makes sure that the file desired to be read was successfully opened,
 * if not it notifies the user and terminates the program
 */
void checkFile(FILE *input) {
    if (input == NULL) {
        printf("File did not open!!\n");
        exit(1);
    }
}


/* Parameters: args - the total number of arguments passed on the command line
 * Return:        Nothing
 * Description: This function checks to see if there was a sufficient number of arguments entered on the command line
 * if not the program notifies the user and terminates.
 */
void checkArguments(int args) {
    if (args < 2) {
        printf("Not enough command line arguments!!\n");
        exit(1);
    }
}


/* Parameters: input - contains the file to be checked
 * Return:        Nothing
 * Description: This function takes in a file and reads each character to make sure that for each
 * opening brace there is another closing brace. It then prints out how many opening braces had a corresponding
 * closing brace. If there is a closing brace before a opening brace it notifies the user with a message.
 */
void checkBraces(FILE *input) {
    int totalOpeningBraces = 0;
    int totalClosingBraces = 0;
    char myChar;
    /* while true, read characters one by one until end of file */
    while (1) {
        myChar = (char) fgetc(input);
        if (myChar == EOF) {
            break;
        } else if (myChar == '}') {
            if (totalOpeningBraces == 0) {
                printf("Found a '}' closing bracket before an '{' opening bracket!\n");
            } else {
                totalClosingBraces++;
            }
        } else if (myChar == '{') {
            totalOpeningBraces++;
        }
    }
    if (totalOpeningBraces - totalClosingBraces < 0) {
        printf("There were %d unmatched opening brackets.\n", 0);
    } else {
        printf("There were %d unmatched opening brackets.\n", totalOpeningBraces - totalClosingBraces);
    }

}
