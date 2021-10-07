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

int simpleFunction(char* x){
    printf("Thread did this call [%s]\n",x);
    return 0;
}


int main() {
    char *stack = (char *) malloc(sizeof(char) * STACK_SIZE);
    getcontext(&thread_context);
    thread_context.uc_stack.ss_sp = stack;
    thread_context.uc_stack.ss_size = STACK_SIZE;

    makecontext(&thread_context,
                function, 1);

    swapcontext(&main_context, &thread_context);


    printf("Hello, World!\n");
    threadInit();
    int threadID = threadCreate((thFuncPtr) simpleFunction, (void *) "Working");
    int threadID1 = threadCreate((thFuncPtr) simpleFunction, (void *) "Working");
    int threadID2 = threadCreate((thFuncPtr) simpleFunction, (void *) "Working");
    printf("Post thread creation ID %d \n",threadID);
    return 0;
}
