#define _XOPEN_SOURCE 600

#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"

ucontext_t main_context, thread_context;

void function() {
    int i;
    printf("This is a function that works loop it up\n");
    for (i = 0; i < 10; i++) {

    }
    printf("END %d\n", i);
    swapcontext(&thread_context, &main_context);
}

void simpleFunction(){
    printf("Thread did this call\n");
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
    threadInit();
    int threadID = threadCreate((thFuncPtr) simpleFunction, NULL);
    printf("Post thread creation %d\n",threadID);
    return 0;
}
