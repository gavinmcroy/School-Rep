#include <stdio.h>

int main() {
    int num = 0;
    printf("Welcome to FizzBuzz\n");
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &num);
    if (num < 1 || num > 100) {
        printf("Invalid input\n");
        return -1;
    }
    for (int i = 1; i <= num; i++) {
        if (i % 5 == 0 && i % 3 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }
    return 0;
}