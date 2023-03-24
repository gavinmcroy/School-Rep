//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    size_t size;
    void *data;
} Node;

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();

void *(*original_malloc)(size_t size) = NULL;

void (*original_free)(void *ptr) = NULL;


int (*original_rand)(void) = NULL;

int arraySize = 1000;
int arrayIndex = 0;
Node node[1000];
int globalLeak = 0;


void lib_init() {
    for (int i = 0; i < arraySize; i++) {
        node[i].data = NULL;
    }
    original_malloc = dlsym(RTLD_NEXT, "malloc");
    original_free = dlsym(RTLD_NEXT, "free");
    original_rand = dlsym(RTLD_NEXT, "rand");
}

/* Every pointer that has not been set to NULL is leaked, print size add to total */
void lib_destroy() {
    int totalLeaks = 0;
    for (int i = 0; i < arraySize; i++) {
        /* We found a pointer that was not cleared */
        if (node[i].data != NULL) {
            /* Prevents printf memory calls interrupting system counter by checking
             * if memory allocated contains a string passed to printf */
            if ((strstr(node[i].data, "LEAK:")) != NULL) {
                globalLeak -= node[i].size;
            } else {
                totalLeaks++;
                fprintf(stderr,"LEAK\t%zu\n", node[i].size);
            }
        }
    }
    fprintf(stderr,"TOTAL\t%d\t%d\n", totalLeaks, globalLeak);
}

void free(void *ptr) {
    for (int i = 0; i < arraySize; i++) {
        if (ptr == node[i].data) {
            node[i].data = NULL;
            globalLeak -= node[i].size;
            break;
        }
    }
    original_free(ptr);
}

void *malloc(size_t size) {
    void *ptr = (original_malloc(size));
    node[arrayIndex].data = ptr;
    node[arrayIndex].size = size;
    arrayIndex++;
    globalLeak += size;
    return ptr;
}

int rand(void) {
    return globalLeak;
}

