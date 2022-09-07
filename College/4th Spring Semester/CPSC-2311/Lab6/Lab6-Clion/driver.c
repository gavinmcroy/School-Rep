#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/****************************** /
* Gavin McRoy                 *
* CPSC2310 Spring 2021        *
* UserName: gmcroy            *
* Instructor:Dr. Yvon Feaster *
/ *****************************/


int main() {
    printf("PRINT RETURN: \n");
    /*1 :  ==
    2 :  <
    3 :  > */
    printf("5 == 4 TRUE OR FALSE(1 or 0) %d\n", printReturn(5, 4, 1));
    printf("5 < 4 TRUE OR FALSE(1 or 0) %d\n", printReturn(5, 4, 2));
    printf("5 > 4 TRUE OR FALSE(1 or 0) %d\n", printReturn(5, 4, 3));


    printf("MAX \n");
    printf("5, 4         Max: %d\n", MAX(10, 2));
    printf("10.5, 11.9   Max: %.2lf\n", MAX(10.5, 11.9));
    printf("\'a\', \'b\'     Max: %c\n", MAX('a', 'b'));

    printf("MIN \n");
    printf("5, 4         Min: %d\n", MIN(10, 2));
    printf("10.5, 11.9   Min: %.2lf\n", MIN(10.5, 11.9));
    printf("\'a\', \'b\'     Min: %c\n", MIN('a', 'b'));

    printf("ABS \n");
    printf("-3 %4d\n", ABS(-3));
    printf("3 %5d\n", ABS(3));
    printf("0 %5d\n", ABS(0));

    printf("LARGEST \n");
    printf("1, 2, 3         LARGEST: %d\n", LARGEST(1, 2, 3));
    printf("\'a\', \'b\', \'c\'   LARGEST: %c\n", LARGEST('a', 'b', 'c'));
    printf("\'c\', \'b\', \'a\'   LARGEST: %c\n", LARGEST('c', 'b', 'a'));

    printf("SMALLEST \n");
    printf("1, 2, 3         SMALLEST: %d\n", SMALLEST(1, 2, 3));
    printf("\'a\', \'b\', \'c\'   SMALLEST: %c\n", SMALLEST('a', 'b', 'c'));
    printf("\'c\', \'b\', \'a\'   SMALLEST: %c\n", SMALLEST('c', 'b', 'a'));

    printf("\n");
    DEBUG_FPRINT();

    printf("ISEVEN_ODD \n");
    ISEVEN_ODD(4);
    ISEVEN_ODD(1);

    printf("MALLOC \n");
    int *x = NULL;
    x = MALLOC(5, int);
    printf("%p\n", x);

    int sum1 = 1;
    printf("Add_to_Sum: %d", ADD_TO_SUM(1, 15));
    return 0;

}
