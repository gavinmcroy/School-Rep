#include <stdio.h>

int main() {
/*
 * Write a program that:

prompts the user to enter two integers
read the integers from the user
prints the sum, product, difference, quotient and remainder of the two integers.


For Example:

Enter two integers: 100 21
The sum is 121
The product is 2100
The difference is 79
The quotient is 4
The remainder is 16

 */
    int integer1 = 0;
    int integer2 = 0;

    printf("Enter two integers: ");
    scanf("%d %d",&integer1,&integer2);
    printf("The sum is %d\n",integer1+integer2);
    printf("The product is %d\n",integer1*integer2);
    printf("The difference is %d\n",integer1-integer2);
    printf("The quotient is %d\n",integer1/integer2);
    printf("The remainder is %d\n",integer1%integer2);
    return 0;


}