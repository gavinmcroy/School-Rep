#include <stdio.h>

int main() {

    int alpha[50];
    int length = sizeof(alpha) / sizeof(int);

    for (int i = 0; i < length; i++) {
        alpha[i] = i;
    }
    printf("The first array element: alpha[0] = %d\n", alpha[0]);
    printf("The last array element: alpha[49] = %d\n", alpha[49]);
    alpha[24] = 62;
    printf("The 25th array element: alpha[24] = %d\n", alpha[24]);
    alpha[9] = 3 * alpha[49] + 10;
    printf("The 10th array element: alpha[9] = %d\n", alpha[9]);

    for (int i = 0; i < length; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%d ", alpha[i]);
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        if (i % 3 == 0 || i % 2 == 0) {
            printf("alpha[%d] = %d\n", i, alpha[i]);
        }
    }

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            alpha[i] = alpha[i] + 1;
        }
    }

    for (int i = 0; i < length; i++) {
        if (i % 5 == 0) {
            printf("\n ");
        }
        printf("%d ", alpha[i]);
    }
    return 0;
}