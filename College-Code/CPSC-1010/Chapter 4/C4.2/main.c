#include <stdio.h>

int main() {
    int firstNum = 0;
    int secondNum = 0;
    int squareSum = 0;
    int additionSum = 0;
    int alphabetStart = 97;
    int alphabetEnd = 122;

    printf("Enter two integers.\n");
    printf("First number must be less than\n"
           "the second number you enter\n"
           "Enter 2 integers numbers: \n");
    scanf("%d %d", &firstNum, &secondNum);

    for (int i = firstNum; i < secondNum; i++) {
        if (i % 2 != 0) {
            squareSum += i * i;
        }
    }

    printf("Sum of the squares of odd integers between %d and %d = %d\n", firstNum,
           secondNum, squareSum);
    printf("Odd integers between %d and %d are: \n", firstNum, secondNum);

    for (int i = secondNum; i >= firstNum; i--) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
        if (i % 2 == 0) {
            additionSum += i;
        }
    }

    printf("\nSum of even integers between %d and %d = %d\n", firstNum, secondNum, additionSum);

    printf("Number%-4sSquare of Number\n", " ");

    for (int i = firstNum; i <= secondNum; i++) {
        printf("%d %-19s %7d\n", i, " ", i * i);
    }

    printf("\nUpper case letters are: ");

    for (int i = alphabetEnd; i >= alphabetStart; i--) {
        printf("%c ", i);
    }

    printf("\n");
    return 0;
}