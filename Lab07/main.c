#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void binaryConverter(const char test[]);

int main() {

    char gav[256];
    bool reset;
    bool isBinary;
    //int eof;

    printf("Starting the CPSC 1011 Decimal to Binary Converter!\n\n");

    do {
        reset = true;
        isBinary = true;
        printf("Please enter a positive whole number (or EOF to quit): ");

        scanf("%s", gav);

        int check = atoi(gav);
        if (check <= 0) {
            printf("\n\tSorry, that was not a positive whole number.\n\n");
            continue;
        }
        //---Checks if the number is either a character or a decimal. Reset is used to prevent cycling and repeating error text
        for (int i = 0; i < strlen(gav); i++) {
            if (isalpha(gav[i]) && reset) {\
                printf("\n");
                printf("\tSorry, that was not a positive whole number.\n\n");
                reset = false;
                isBinary = false;
            } else if (gav[i - 1] == '.') {
                if (gav[i] != '0') {
                    printf("\n");
                    printf("\tSorry, that was not a positive whole number.\n\n");
                    isBinary = false;
                }
            }
        }
        if (isBinary) {
            printf("\n");
            binaryConverter(gav);
            printf("\n");
        }
        //---Checks if cmd + d was pressed
    } while ((!feof(stdin)));

    //FIXME---Final statement does not print. slight problem


    printf("Thank you for using the CPSC 1011 Decimal to Binary Generator. Goodbye!");

    return 0;

}

void binaryConverter(const char test[]) {
    int check = 0;
    int tmp;
    char binaryArray[256];
    int i = 0;

    check = atoi(test);

    //---Converts to binary digits
    printf("\t%d (base-10) is equivalent to ", check);
    while (check > 0) {
        tmp = check % 2;
        binaryArray[i] = (char) tmp;
        check /= 2;
        i++;
    }

    //---prints the reverse of the array using i - 1 as the size of the array
    for (int j = i - 1; j >= 0; j--) {

        printf("%d", binaryArray[j]);
    }
    printf(" (base-2)!");
    printf("\n");

}