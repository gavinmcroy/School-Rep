#include <stdio.h>
#include <ctype.h>

const int MAX_DIMENSION = 25;

void printLine(int length);

void printTriangle(int baseLength);

void printRectangle(int width, int height);

int main() {

    char option;
    int lineLength = 0;
    int triangleBase = 0;
    int rectangleWidth = 0;
    int rectangleHeight = 0;

    printf("Which shape (L-line, T-triangle, R-rectangle): ");
    scanf("%c", &option);
    option = toupper(option);
    printf("\n");

    switch (option) {
        case 'L':
            printf("Enter an integer length between 1 and 25: ");
            scanf("%d", &lineLength);
            (lineLength > 25 || lineLength < 1) ? printf("Length not in range.\n") : printLine(lineLength);
            break;
        case 'T':
            printf("Enter an integer base length between 3 and 25: ");
            scanf("%d", &triangleBase);
            (triangleBase > 25 || triangleBase < 3) ? printf("Length not in range.\n") : printTriangle(triangleBase);
            break;
        case 'R':
            printf("Enter an integer width and height between 2 and 25: ");
            scanf("%d %d", &rectangleWidth, &rectangleHeight);
            if (rectangleWidth > 25 || rectangleWidth < 2) {
                printf("Width not in range.\n");
            } else if (rectangleHeight > 25 || rectangleHeight < 2) {
                printf("Height not in range.\n");
            } else {
                printRectangle(rectangleWidth, rectangleHeight);
            }
            break;
        default:
            printf("Boom");
    }

    return 0;
}

void printLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("*");
    }
}

void printTriangle(int baseLength) {
    for (int i = 1; i <= baseLength; i++) {
        for (int j = 0; j < i; j++) {
            printLine(1);
        }
        printf("\n");
    }
}

void printRectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printLine(1);
        }
        printf("\n");
    }
}