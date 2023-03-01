#include <stdio.h>
#include <sys/time.h>

long long start_timer() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

long long stop_timer(long long start_time,char *name) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long end_time = tv.tv_sec * 1000000 + tv.tv_usec;
    printf("%s: %.5f sec\n", name, ((float) (end_time - start_time)) /
                                   (1000 * 1000));
    long long difference = end_time - start_time;
    return difference;
}

float CPU_big_dot(float *A, float *B, int N);

int main() {
    printf("Hello, World!\n");
    float A[] = {1, 2, 3};
    float B[] = {1, 5, 7};
    long long starter = start_timer();

    stop_timer(starter,"Total dot product time");
    return 0;
}

float CPU_big_dot(float *A, float *B, int N) {
    float summation = 0;
    for (int i = 0; i < N; i++) {
        summation += A[i] * B[i];
    }
    return summation;
}