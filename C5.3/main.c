#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main() {
    int randomSeed = 0;
    int fiveIntegers[5];
    int randomArray[5];
    int numMatches[5];
    int totalMatched = 0;
    bool matched = false;
    bool gameWon = false;

    printf("Enter an integer random seed: ");
    scanf("%d", &randomSeed);
    srand(randomSeed);
    printf("To play the Pick-5 game, enter five integers bewteen 1 and 9 (inclusive):\n");
    scanf("%d %d %d %d %d", &fiveIntegers[0], &fiveIntegers[1], &fiveIntegers[2], &fiveIntegers[3],
          &fiveIntegers[4]);

    for (int i = 0; i < 5; i++) {
        randomArray[i] = (rand() % 9) + 1;

    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (randomArray[i] == randomArray[j]) {
                randomArray[j] = (rand() % 9) + 1;
                //printf("Duplicate on index : %d and %d\n",i,j);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (randomArray[i] == fiveIntegers[i]) {
            numMatches[totalMatched] = i;
            matched = true;
            totalMatched++;
        }
    }

    if (!matched) {
        printf("You didn't match any numbers!\n");
    } else if (totalMatched < 4) {
        printf("You only matched %d numbers. \n", totalMatched);
    } else {
        printf("Congratulations!!! You WIN!!!\n");
        gameWon = true;
    }

    if (matched && !gameWon) {
        printf("Your numbers matched the Pick-5 numbers at position(s): ");
        for (int i = 0; i < totalMatched; i++) {
            (i < totalMatched - 1) ? printf("%d, ", numMatches[i]) : printf("%d ", numMatches[i]);
        }
        printf("\n");
    }

    printf("The winning numbers are: ");
    for (int i = 0; i < 5; i++) {
        if (i < 4) {
            printf("%d, ", randomArray[i]);
        } else {
            printf("%d\n", randomArray[i]);
        }
    }
    return 0;
}
