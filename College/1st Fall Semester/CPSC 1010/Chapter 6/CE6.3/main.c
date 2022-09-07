#include <stdio.h>
#include <ctype.h>

const int MAX_DIMENSION = 25;

void printLine(int length, char drawWith);

void printTriangle(int baseLength, char drawWith);

void printRectangle(int width, int height, char drawWith);

void printPyramid(int height, char drawWith);

void printInvertedTriangle(int length, char drawWith);

int main() {

    char option;
    char printChar;
    int lineLength = 0;
    int triangleBase = 0;
    int rectangleWidth = 0;
    int rectangleHeight = 0;
    int pyramidHeight = 0;

    printf("Which shape (L-line, T-triangle, R-rectangle, P-pyramid, I-Inverted triangle): ");
    scanf("%c", &option);
    option = toupper(option);

    printf("Which character: ");
    scanf(" %c", &printChar);
    printf("\n");

    switch (option) {
        case 'L':
            printf("Enter an integer length between 1 and 25: ");
            scanf("%d", &lineLength);
            (lineLength > 25 || lineLength < 1) ? printf("Length not in range.\n") : printLine(lineLength, printChar);
            break;
        case 'T':
            printf("Enter an integer base length between 3 and 25: ");
            scanf("%d", &triangleBase);
            (triangleBase > 25 || triangleBase < 3) ?
            printf("Length not in range.\n") : printTriangle(triangleBase, printChar);
            break;
        case 'R':
            printf("Enter an integer width and height between 2 and 25: ");
            scanf("%d %d", &rectangleWidth, &rectangleHeight);
            if (rectangleWidth > 25 || rectangleWidth < 2) {
                printf("Width not in range.\n");
            } else if (rectangleHeight > 25 || rectangleHeight < 2) {
                printf("Height not in range.\n");
            } else {
                printRectangle(rectangleWidth, rectangleHeight, printChar);
            }
            break;
        case 'P':
            printf("Enter an integer height between 2 and 25: ");
            scanf("%d", &pyramidHeight);
            if (pyramidHeight < 2 || pyramidHeight > 25) {
                printf("Height not in range.\n");
            } else {
                printPyramid(pyramidHeight, printChar);
            }
            break;
        case 'I':
            printf("Enter an integer height between 2 and 25: ");
            scanf("%d", &triangleBase);
            if (triangleBase > 25 || triangleBase < 2) {
                printf("Length not in range.");
            } else {
                printInvertedTriangle(triangleBase, printChar);
            }
            break;
        default:
            printf("Unknown shape.\n");
    }

    return 0;
}

void printLine(int length, char drawWith) {
    for (int i = 0; i < length; i++) {
        printf("%c", drawWith);
    }
}

void printTriangle(int baseLength, char drawWith) {
    for (int i = 1; i <= baseLength; i++) {
        for (int j = 0; j < i; j++) {
            printLine(1, drawWith);
        }
        printf("\n");
    }
}

void printRectangle(int width, int height, char drawWith) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printLine(1, drawWith);
        }
        printf("\n");
    }
}

void printPyramid(int height, char drawWith) {
    for (int i = 0; i < height; i++) {
        printLine(i, drawWith);
        printf("\n");
    }
    for (int i = height; i > 0; i--) {
        printLine(i, drawWith);
        printf("\n");
    }
}

void printInvertedTriangle(int length, char drawWith) {
    for (int i = length; i >= 0; i--) {
        printLine(i, drawWith);
        printf("\n");
    }
}