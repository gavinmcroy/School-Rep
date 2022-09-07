#include <stdio.h>
#include<stdbool.h>

int main() {
    bool first = true;
    int array[40];
    int length = sizeof(array) / sizeof(int);

    for (int i = 0; i < length; i++) {
        if (i % 10 == 0 && !first) {
            printf("\n");
        }
        if (i < 10) {
            first = false;
            array[i] = i * i;
            printf("%6d ", array[i]);
        }
        if (i >= 10 && i < 20) {
            array[i] = i * 3;
            printf("%6d ", array[i]);
        }
        if (i >= 20 && i < 30) {
            array[i] = array[i - 20] * array[i - 10];
            printf("%6d ", array[i]);
        }
        if (i >= 30 && i < 40) {
            array[i] = array[i - 10] * 10;
            printf("%6d ", array[i]);
        }
    }
    return 0;
}
