#include <stdio.h>

int sumRecursive(int num);

int sumIterative(int num);

int main() {
    int num = 0;
    printf("Enter an integer between 1 and 1000:");
    scanf("%d", &num);
    if (num <= 0 || num > 1000) {
        printf("Invalid input\n");
        return 0;
    }
    printf("Recursive sum = %d\n", sumRecursive(num));
    printf("Iterative sum = %d\n", sumIterative(num));
}

int sumRecursive(int num) {
    if (num > 1) {
        return num + sumRecursive(num - 1);
    } else {
        return 1;
    }

    //---TODO finish 
}

int sumIterative(int num) {
    int tmp = 0;
    for (int i = 0; i < num; i++) {
        tmp += num - i;
    }
    return tmp;
}