#include <stdio.h>

int main() {
    int firstNum = 0;
    int secondNum = 0;
    int squareSum = 0;
    int additionSum = 0;
    int tmp = 0;
    int alphabetStart = 65;
    int alphabetEnd = 90;

    printf("Enter two integers.\n");
    printf("First number must be less than\n"
           "the second number you enter\n"
           "Enter 2 integers numbers: \n");
    scanf("%d %d", &firstNum, &secondNum);
    tmp = firstNum;

    while (firstNum != secondNum) {
        if (firstNum % 2 != 0) {
            squareSum += firstNum * firstNum;
        }
        firstNum++;
    }

    firstNum = tmp;

    printf("Sum of the squares of odd integers between %d and %d = %d\n", firstNum,
           secondNum, squareSum);
    printf("Odd integers between %d and %d are: \n",firstNum,secondNum);

    while (firstNum <= secondNum) {
        if (firstNum % 2 != 0) {
            printf("%d ", firstNum);
        }
        if (firstNum % 2 == 0) {
            additionSum += firstNum;
        }
        firstNum++;
    }
    firstNum = tmp;
    printf("\nSum of even integers between %d and %d = %d\n", firstNum, secondNum, additionSum);

    printf("Number%-4sSquare of Number\n"," ");
    while (secondNum >= firstNum) {
        printf("%d %-19s %7d\n", secondNum, " ", secondNum * secondNum);
        secondNum--;
    }
    printf("\nUpper case letters are: ");
    while (alphabetStart <= alphabetEnd) {
        printf("%c ", alphabetStart);
        alphabetStart++;
    }
    printf("\n");

    firstNum = tmp;
    return 0;
}