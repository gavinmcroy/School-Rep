#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("gav.txt", "r");
    int num1 = 0;
    int num2 = 0;
    printf("Attempting file open\n");
    if (file == NULL) {
        printf("Attempt failed\n");
        return EXIT_FAILURE;
    }
    fscanf(file,"%d %d", &num1, &num2);
    printf("%d %d\n", num1, num2);
    fclose(file);
    return 0;
}