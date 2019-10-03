#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

    const int CHAR_SIZE = 99;
    const int PHONE_SIZE = 7;
    char letters[100];
    char phoneNumber[9];
    int j = 0;

    for (int i = 0; i < PHONE_SIZE; i++) {
        phoneNumber[i] = '+';
    }
    for (int i = 0; i < CHAR_SIZE; i++) {
        letters[i] = '-';
    }
    //while(true)
    printf("Enter a telephone number using letters (EXIT to quit): \n");
    fgets(letters, CHAR_SIZE, stdin);

    for (int i = 0; i < CHAR_SIZE; i++) {
        for (int i = 0; i < CHAR_SIZE; i++) {
            letters[i] = (char) toupper(letters[i]);
        }
        if (strcmp(letters, "EXIT\n") == 0) {
            printf("ending");
            return 1;
        }
    }
    for (int i = 0; i < CHAR_SIZE; i++) {
        if (strlen(phoneNumber) == j) {
            printf("Size Limit Reached: ");
            break;
        }
        //FIXME printf("I = %d ON LETTER: %c\n", i, letters[i]);

        switch (letters[i]) {
            case 'A':
            case 'B':
            case 'C':
                phoneNumber[j] = '2';
                j++;
                break;
            case 'D':
            case 'E':
            case 'F':
                phoneNumber[j] = '3';
                j++;
                break;
            case 'G':
            case 'H':
            case 'I':
                phoneNumber[j] = '4';
                j++;
                break;
            case 'J':
            case 'K':
            case 'L':
                phoneNumber[j] = '5';
                j++;
                break;
            case 'M':
            case 'N':
            case 'O':
                phoneNumber[j] = '6';
                j++;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                phoneNumber[j] = '7';
                j++;
                break;
            case 'T':
            case 'U':
            case 'V':
                phoneNumber[j] = '8';
                j++;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                phoneNumber[j] = '9';
                j++;
                break;
            default:
               // printf("DEFAULT TRIGGER: %d\n", i);
                break;
        }
//        if (i == 0) { FIXME
//            printf("SIZE: %lu\n", strlen(phoneNumber));
//        }

    }
    for(int i = 0; i<strlen(phoneNumber);i++){
        printf("%c",phoneNumber[i]);
    }
    return 0;
}
/*
 * Left off trying to debug why once white space is encountered the program will
 * completely stop checking for cases where there is a letter. Default is not triggered
 * And properly increments this just makes absolutely no sense
 */