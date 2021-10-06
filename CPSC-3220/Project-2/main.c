#define _XOPEN_SOURCE 600

#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"

ucontext_t main_context, thread_context;

void function() {
    int i;
    printf("This is a function that works loop it up\n");
    for (i = 0; i < 1000000000; i++) {

    }
    printf("END %d\n", i);
    swapcontext(&thread_context, &main_context);
}


int main() {
    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
    getcontext(&thread_context);
    thread_context.uc_stack.ss_sp = stack;
    thread_context.uc_stack.ss_size = STACK_SIZE;

    makecontext(&thread_context,
                (void (*)(void)) function, 1);
    swapcontext(&main_context, &thread_context);

    printf("Hello, World!\n");
    threadYield();
    return 0;
}
