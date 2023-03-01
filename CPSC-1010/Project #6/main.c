#include <stdio.h>

int main(int argc, char *argv[]) {
    int a;
    int b;
    int c;

    if (argc != 4) {
        printf("Usage: a.out side_a side_b side_c\n");
        return 1;
    }

    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);
    sscanf(argv[3], "%d", &c);

    //printf("%d",argc);

    //---TODO change output to match requirements
    if (a < 1 || a > 200) {
        printf("Value of a is not in the range of permitted values.\n");
        return 1;
    } else if (b < 1 || b > 200) {
        printf("Value of b is not in the range of permitted values.\n");
        return 1;
    } else if (c < 1 || c > 200) {
        printf("Value of c is not in the range of permitted values.\n");
        return 1;
    } else if (a >= c + b) {
        printf("Not a triangle\n");
        return 1;
    } else if (b >= a + c) {
        printf("Not a triangle\n");
        return 1;
    } else if (c >= a + b) {
        printf("Not a triangle\n");
        return 1;
    } else if (a == b && a == c) {
        printf("Equilateral\n");
        return 0;
    } else if (a == b || a == c || b == c) {
        printf("Isosceles\n");
        return 0;
    } else {
        printf("Scalene\n");
    }

    return 0;
}