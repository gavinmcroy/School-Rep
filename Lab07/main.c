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

    printf("Starting the CPSC 1011 Decimal to Binary Converter!\n");

    while (true) {
        reset = true;
        isBinary = true;
        printf("Please enter a positive whole number (or EOF to quit): \n");
        scanf("%s", gav);
        if (strcmp(gav, "EXIT") == 0) {
            break;
        }
        for (int i = 0; i < strlen(gav); i++) {
            if (isalpha(gav[i]) && reset) {
                printf("Sorry, that was not a positive whole number!\n");
                reset = false;
                isBinary = false;
            } else if (gav[i - 1] == '.') {
                if (gav[i] != '0') {
                    printf("Sorry, that was not a positive whole number.\n");
                    isBinary = false;
                }
            }
        }
        if (isBinary) {
            printf("Is binary has fired\n");
            binaryConverter(gav);
        }
    }
    return 0;
}

void binaryConverter(const char test[]) {
    printf("Binary function has fired\n");
    //FIXME For some reason this function doesnt run anything!
    int check = 0;
    int tmp;
    char binaryArray[256];
    int i = 0;

    check = atoi(test);

    printf("CHECK: %d\n", check);

    while (check > 0) {
        tmp = check % 2;
        binaryArray[i] = (char) tmp;
        check /= 2;
        i++;
    }
    //---prints the reverse of the array using i - 1 as the size of the array and checks if end is reached
    binaryArray[i + 1] = '\0';
    for (int j = i - 1; j >= 0; j--) {
        if (binaryArray[i] == '\0') {
            break;
        }
        printf("%d ", binaryArray[j]);
    }

}