#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <ucontext.h>
#include <stdlib.h>

ucontext_t main_context, test_context;

void *experimentation(void *x) {
    printf("So this is weird\n");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", i);
    }
    swapcontext(&test_context, &main_context);
    return NULL;
}


int main() {
    char *stack = (char *) malloc(sizeof(char) * 64000);
    getcontext(&test_context);
    test_context.uc_stack.ss_sp = stack;
    test_context.uc_stack.ss_size = 64000;
    test_context.uc_stack.ss_flags = 0;
    makecontext(&test_context,
                (void (*)()) experimentation, 1, NULL);
    printf("Switching context \n");
    swapcontext(&main_context, &test_context);
    printf("Back inside main\n");
    return 0;
}
