//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();

void *(*original_malloc)(size_t size);

void (*original_free)(void *ptr);

int (*original_rand)(void) = NULL;

void lib_init() {
    //printf("Initializing Library\n");
   // original_malloc = dlsym(RTLD_NEXT, "malloc");
    original_free = dlsym(RTLD_NEXT, "free");
    original_rand = dlsym(RTLD_NEXT, "rand");
}

int i = 0;


void lib_destroy() {
    //printf("Unloading Library\n");
}

void free(void *ptr) {
   // original_free(ptr);
    i++;
}

//void *malloc(size_t size) {
//    return (original_malloc(size));
//}

int rand(void) {
    return i;
}

