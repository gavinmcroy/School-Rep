#include <stdio.h>

int main(void) {
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
    
    const int data[5] = {1, 2, 3, 4, 5};

    int i = 0;
    int sum = 0;

    for (i = 0; i < 5 ; i++) {  //---Adjusted for loop from infinite loop to loop only through array elements
        sum += data[i];
    }

    printf("sum = %d\n", sum);
    return 0;
}
