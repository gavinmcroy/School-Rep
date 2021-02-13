#include <iostream>

void printNum(int) {/*assume this function is implemented here*/};

void numSq(int) {/*assume this function is implemented here*/};

int adder(int, int) {/*assume this function is implemented here*/};

int main(int argc, char *argv[]) {
    /*Declare a function pointer called FP and point it to numSq*/
    void (*FP)(int) = numSq;

    /*There are two ways to call a function pointer.  Show the two ways to call FP declared above passing in the value of 10.  */
    (*FP)(10);
    FP(10);

    /*The author of the video discusses two ways to point a function pointer to a function.*/
    /*Write the code to show the two ways to point FP to printNum (this should be 2 lines of code.)*/
    FP = printNum;
    FP = &printNum;
    /*Now that FP is pointing to a function, again there are two ways to call the function
     * Pointer/Below write the code to call the function pointer FP passing in the value of 20 using the two methods.*/
    FP(20);
    (*FP)(20);

    /*Declare a function pointer called FP2.*/
    int (*FP2)(int, int);
    /*Now point FP2 to adder;*/
    FP2 = adder;
    /*Now create a variable called sum and point it to FP2 passing in two integers. */
    int sum = FP2(3, 3);
    printf("Sum = %d\n", sum);
    return 0;
}
