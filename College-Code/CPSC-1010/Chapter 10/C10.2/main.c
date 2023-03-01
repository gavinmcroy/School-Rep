#include <stdio.h>

void printStars(int num);

int main() {
    int num = 0;
    printf("Enter an integer between 1 and 1000: ");
    scanf("%d", &num);
    if (num < 1 || num > 1000) {
        printf("Invalid input");
        return 1;
    }
    printStars(num);
    return 0;
}

void printStars(int num) {
    for (int i = 0; i < num; ++i) {
        printf("*");
    }
    printf("\n");

    if (num > 1) {
        printStars(num - 1);
    }

    for (int i = 0; i < num; ++i) {
        printf("*");
    }

    printf("\n");
}