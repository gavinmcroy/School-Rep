#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N       10000

int main (void) {
    int i, n = 0;
    char *pp[N];

    long onegb = 1UL << 29UL;

    for (n = 0; n < N; n++) {
        pp[n] = malloc(onegb);
        if (pp[n] == NULL)
            break;
    }
    printf("malloced %d GB\n", n);

    for (i = 0; i < n; i++) {
        memset (pp[i], 0, onegb);
        printf("using...%d GB\n", i+1);
    }

    return 0;
}