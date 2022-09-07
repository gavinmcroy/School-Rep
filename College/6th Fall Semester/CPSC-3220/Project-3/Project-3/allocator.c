//
// Created by Gavin Taylor Mcroy on 10/27/21.
//
#include "allocator.h"

Page segregatedList[LIST_SIZE];

void lib_init() {
    printf("Library opened \n");
    int start = 2;
    for (int i = 0; i < LIST_SIZE; i++) {
        segregatedList[i].size = start;
        start = start << 1;
    }
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("%d\n", segregatedList[i].size);
    }
}

void lib_destroy() {
    printf("Library closed \n");
}

void free(void *ptr) {

}

void *malloc(size_t size) {
    // used for initializing the memory to zero . ( optional )
    int fd = open("/dev/zero", O_RDWR);

    if(fd == -1){
        exit(ERROR_PD);
    }

    // ask the OS to map a page of virtual memory initialized to zero ( optional )
    // initializing your memory may make debugging easier .
    void *page = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if(page == MAP_FAILED){
        exit(25);
    }

    char *pointer = (char *) page;
    for (int i = 0; i < PAGESIZE - 1; i++) {
        pointer[i] = 'a';
    }

    //unmap the page , when you ’re done .
    munmap(page, PAGESIZE);
    return NULL;
}