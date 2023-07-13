

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>

int *px = NULL;

void handlesig(int signal) {
    printf("Ha ha, I won't die.\n");
    px = malloc(sizeof(int));
}

int main() {
    signal(SIGINT, handlesig);
    signal(SIGTERM, handlesig);
    signal(SIGSEGV, handlesig);

    
    *px = 45;

    while (true) {
        printf("Wasting your CPU cycles - %d\n", getpid());
        sleep(1);
    }

}