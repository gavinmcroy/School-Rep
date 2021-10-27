//
// Created by Gavin Taylor Mcroy on 10/27/21.
//
#include "allocator.h"

void lib_init(){
    printf("Library opened \n");
}

void lib_destroy(){
    printf("Library closed \n");
}

void free(void *ptr) {

}

void *malloc(size_t size) {
    // used for initializing the memory to zero . ( optional )
    int fd = open("/dev / zero", O_RDWR);

    // ask the OS to map a page of virtual memory initialized to zero ( optional )
    // initializing your memory may make debugging easier .
    void *page = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    //unmap the page , when you ’re done .
    munmap(page, PAGESIZE);
    return NULL;
}