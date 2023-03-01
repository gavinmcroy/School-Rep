#include <stdio.h>
#include<stdbool.h>

int main() {

    /*
     * Write a program that mimics a simple 4-function calculator.
     * The program should prompt for two integers and the operation to be performed.
     * It should then output the numbers, the operator, and the result.  All the results should also be integers. For division, if the denominator is zero, output an appropriate message.
     * For example:
     * Enter integer +|-|*|/ integer: 3 + 2
     * 3 + 2 = 5
     */
    int num1 = 0;
    int num2 = 0;
    int answer = 0;
    char choice = ' ';
    bool isZero = false;

    printf("Enter integer +|-|*|/ integer: ");
    scanf("%d %c %d", &num1, &choice, &num2);


    switch (choice) {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("%d %c %d = ERROR \n", num1, choice, num2);
                isZero = true;
            } else {
                answer = num1 / num2;
            }
            break;
        default:
            printf("Invalid Option");
    }
    (isZero) ? printf("Cannot divide by zero ") : printf("%d %c %d = %d\n", num1, choice, num2, answer);

    return 0;
}