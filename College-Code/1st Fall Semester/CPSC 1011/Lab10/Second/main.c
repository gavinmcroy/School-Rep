/* There are multiple bugs in this program.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Academic Honesty Declaration: * The following code represents my own
 *  work and I have neither received nor given assistance that violates
 *  the collaboration policy posted with this assignment. I have not copied
 *  or modified code from any other source other than the lab
 *  assignment, course textbook, or course lecture slides. Any unauthorized
 *  collaboration or use of materials not permitted will be subjected to
 *  academic integrity policies of Clemson University and CPSC 1010/1011.
 *  I acknowledge that this lab assignment is based upon an assignment
 *  created by Clemson University and that any publishing or
 *  posting of this code is prohibited unless I
 *  receive written permission from Clemson University.
 */


void Find11();

void PointersAreFun();

int main(void) {
    
    Find11();
    PointersAreFun();
    return 0;
}

void Find11(void) {
    int i = 0, count = 0, search = 1, found = 0;
    int number = 5;
    int table[10];

    table[0] = number;
    printf("table[%i]: %i\n", count, table[count]);

    count = 1;
    while (count < 10) {
        table[count] = number++ * 2;
        printf("table[%i]: %i\n", count, table[count]);
        count++;
    }

    while (search == 1) { //---Changed assignment in loop to a condition expression
        if (table[i++] == 11) {
            search = 0;
            found = i - 1;
        }
        if (count == i) {
            search = 0;
        }
    }

    if (found)
        printf("The number 11 is in the table at location: %d\n", found);
    else
        printf("The number 11 is not in the table.\n");
}

void PointersAreFun() {
    puts("\nDemo on Pointers!\n");

    int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int anotherArray[10] = {10, 11, 12};
    int *ptrArray = NULL;
    int *ptrAnotherArray = NULL;

    ptrArray = myArray;
    ptrAnotherArray = anotherArray; //---Changed pointer from null to pointing towards an actual address

    printf("The first value of the array is %d\n", *ptrArray);
    printf("The first value of the second array is %d\n", *ptrAnotherArray);


}
