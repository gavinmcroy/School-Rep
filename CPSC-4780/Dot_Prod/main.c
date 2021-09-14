#include <stdio.h>

float CPU_big_dot(float *A, float *B, int N);

int main() {
    printf("Hello, World!\n");
    float A[] = {1,2,3};
    float B[] = {1,5,7};
    printf("%f",CPU_big_dot(A,B,3));
    return 0;
}

float CPU_big_dot(float *A, float *B, int N){
    float summation = 0;
    for(int i = 0; i < N; i++){
        summation += A[i] * B[i];
    }
     return summation;
}