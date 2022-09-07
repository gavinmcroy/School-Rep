#include <stdio.h>

int main() {
    int array[8];
    const int length = sizeof(array) / sizeof(int);
    printf("Enter 8 integer values between 0 and 20...\n");
    for (int i = 0; i < length; i++) {
        printf("Value %d: \n", i + 1);
        scanf("%d", &array[i]);
    }
    printf("%7s%11s\t%s\n", "Index", "Value", "Histogram");
    for (int i = 0; i < length; i++) {
        printf("%7d%11d\t", i, array[i]);
        for (int j = 0; j < array[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}