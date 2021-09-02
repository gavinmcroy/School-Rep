//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();

void *(*original_malloc)(size_t size) = NULL;

void (*original_free)(void *ptr) = NULL;

void lib_init() {
    printf("Initializing Library\n");
    original_malloc = dlsym(RTLD_NEXT, "malloc");
    original_free = dlsym(RTLD_NEXT, "free");
}

void lib_destroy() {
    printf("Unloading Library\n");
}

void free(void *ptr) {
    printf("De-allocation detected");
    original_free(ptr);
}

void *malloc(size_t size) {
    printf("Allocation detected");
    return original_malloc(size);
}

