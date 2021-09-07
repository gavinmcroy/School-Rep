//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();

void *(*original_malloc)(size_t size) = NULL;

void (*original_free)(void *ptr) = NULL;


int (*original_rand)(void) = NULL;

bool val = true;

void lib_init() {
    printf("Loading library\n");
    original_malloc = dlsym(RTLD_NEXT, "malloc");
    original_free = dlsym(RTLD_NEXT, "free");
    original_rand = dlsym(RTLD_NEXT, "rand");
}

void lib_destroy() {
    printf("Unloading Library\n");
}

void free(void *ptr) {
    if(original_free==NULL){
        val = false;
    }
    original_free(ptr);
}

//void *malloc(size_t size) {
//    //return (original_malloc(size));
//}

int rand(void) {
    return 0;
}

