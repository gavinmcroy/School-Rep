#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fpTest(char *, char *);

void fpTest2(char *, char *);

void fpTest3(char *, char *);

void printStr(char *, char *, void(*fp)(char *, char *));

int main() {
    /*Initialize these with your first and last names*/
    char *first = (char *) malloc(sizeof(char) * 10);
    char *last = (char *) malloc(sizeof(char) * 10);
    strcpy(first, "Gavin");
    strcpy(last, "McRoy");

    /*Create a function pointer called fp and point it to fpTest*/
    void (*fp)(char *, char *) = fpTest;

    /*Call printStr using first, last, and the function pointer you created
     *above*/
    printStr(first, last, fp);

    /*Now point your function pointer to fptest2 */
    fp = fpTest2;

    /*Call printStr using first, last, and the function pointer*/
    printStr(first, last, fp);

    /*Point your function pointer to fptest3*/
    fp = fpTest3;

    /*Call printStr using two strings literals that you want to concatenate and the
     *function pointer. (not first and last)*/
    printStr("Hello", "Hi", fp);
    free(first);
    free(last);
    return 0;

}

void fpTest(char *first, char *last) {
    printf("First: %s\nLast: %s\n", first, last);
}

void fpTest2(char *first, char *last) {
    printf("%s, %s\n", last, first);
}

void fpTest3(char *first, char *second) {
    printf("%s%s\n", first, second);
}

void printStr(char *a, char *b, void(*fp)(char *, char *)) {
    fp(a, b);
}


