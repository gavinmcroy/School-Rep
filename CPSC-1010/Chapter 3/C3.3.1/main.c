#include <stdio.h>
#include<stdbool.h>

bool primeFunc(int num);

int main() {
    int num = 0;
    int prime = 2;
    int divisor = 1;
    bool isPrime = false;
    bool hasDetected = false;
    int array[4];
    int i = 0;

    printf("Enter an integer between 1 and 1000 (inclusive): \n");
    scanf("%d", &num);

    if (num > 1000 || num < 0) {
        printf("You must enter a number between 1 and 1000 (inclusive).\n");
        return -1;
    }
    while (true) {
        if (num/2-1 < prime) {
            if (hasDetected != true) {
                isPrime = true;
                break;
            } else {
                isPrime = false;
                break;
            }
        }
        if (num % prime == 0) {
            divisor = prime;
            bool test = primeFunc(prime);
            int myVal = num / divisor;
            bool anotherTest = primeFunc(myVal);

            if (test && anotherTest) {
                printf("%d is divisible by %d, %d.\n", num, divisor, myVal);
//                printf("%d%s %d, %d.\n", num, myStringPrime, divisor, myVal);
            } else if (test) {
                //printf("%d is divisible by %d, \n", num, divisor);
                array[i] = divisor;
                i++;
            }
            hasDetected = true;
        }
        prime++;
    }
    if (i >= 3) {
        printf("%d is divisible by %d, %d, %d.\n", num, array[0], array[1], array[2]);
    }

    (isPrime) ? printf("%d is prime.\n", num) : printf("%d is not prime.\n", num);
    return 0;
}

bool primeFunc(int num) {
    int prime = 2;
    bool hasDetected = false;
    bool isPrime = false;
    //int divisor = 0;

    while (true) {
        if (num / 2 < prime) {
            if (hasDetected != true) {
                isPrime = true;
                break;
            } else {
                isPrime = false;
                break;
            }
        }
        if (num % prime == 0) {
            //divisor = prime;
            hasDetected = true;
        }
        prime++;
    }
    return isPrime;

}