#include <stdio.h>
#include<stdbool.h>
#include<string.h>

bool isVowel(char input);

int countUC(char string[]);

int countLC(char string[]);

int countOthers(char string[]);


int main() {
    char userInput[64];
    int totalVowels = 0;
    printf("Enter a sentence: ");
    fgets(userInput, 64, stdin);

    for (int i = 0; i < strlen(userInput); i++) {
        bool vowel = isVowel(userInput[i]);
        if (vowel) {
            totalVowels++;
        }
        if (userInput[i] == '\\' || userInput[i] == '\n') {
            userInput[i] = '\0';
        }
    }
    //userInput[strlen(userInput)-1] = '\0';

    printf("\n");
    printf("There are %lu total characters.\n", strlen(userInput));
    printf("There are %d vowels.\n", totalVowels);
    printf("There are %d UPPERCASE letters.\n", countUC(userInput));
    printf("There are %d lowercase letters.\n", countLC(userInput));
    printf("There are %d other characters.\n", countOthers(userInput));

    return 0;
}

bool isVowel(char input) {
    if (input == 'A' || input == 'a') {
        return true;
    } else if (input == 'E' || input == 'e') {
        return true;
    } else if (input == 'I' || input == 'i') {
        return true;
    } else if (input == 'O' || input == 'o') {
        return true;
    } else if (input == 'U' || input == 'u') {
        return true;
    } else {
        return false;
    }
}

int countUC(char string[]) {
    int totalUC = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            totalUC++;
        }
    }
    return totalUC;
}

int countLC(char string[]) {
    int totalLC = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 97 && string[i] <= 122) {
            totalLC++;
        }
    }
    return totalLC;
}

int countOthers(char string[]) {
    int totalOthers = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (!(string[i] >= 97 && string[i] <= 122) && !(string[i] >= 65 && string[i] <= 90)) {
            totalOthers++;
        }
    }
    return totalOthers;
}