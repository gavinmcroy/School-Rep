#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n = 0;

    while (1) {
        if (malloc(1<<29) == NULL) {
                printf("malloc failure after %d GB\n", n);
                return 0;
        }
        printf ("got %d GB\n", ++n);
    }
}