//
// Created by Gavin Taylor Mcroy on 10/27/21.
//
#include "allocator.h"

void *segregatedList[LIST_SIZE];

void lib_init() {
    int start = 2;
    /* Setup all of our pages */
    for (int i = 0; i < LIST_SIZE; i++) {
        int fd = open("/dev/zero", O_RDWR);

        if (fd == -1) {
            exit(FD_ERROR);
        }

        /* Memory request to OS and initialized to 0 */
        void *page = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

        if (page == MAP_FAILED) {
            exit(MAP_ERROR);
        }

        /* Set our list to point to a particular page */
        segregatedList[i] = page;

        /* Cast our page into a Page Object pointer so we can index into the memory. Initializing the header. */
        /* TODO how are we going to build our linked list inside of this structure. */
        Page *mem = (Page *) page;
        mem->size = start;
        mem->nextPage = NULL;
        mem->freeListHead = (page + 1);

        /* TODO LEFTOFF Build free list by counting memory left in page */
        int memoryLeft = PAGESIZE - sizeof(Page);
        char * nextFreeList = mem->freeListHead;
        while (memoryLeft >= 0) {
            nextFreeList =  nextFreeList+mem->size;
            char * temp = mem->freeListHead;

            memoryLeft-=2;
        }
        //}

        /* 2, 4, 8, 16... */
        start = start << 1;
    }
}

void lib_destroy() {
    printf("Library closed \n");
}

void free(void *ptr) {

}

void *malloc(size_t size) {
    setupMemoryChunk(size);
    /* TODO I'm returning the first free list pointer. This is temporary */
    return (char*)segregatedList[0]+sizeof(Page);
}

void setupMemoryChunk(size_t size) {
    /* TODO map properly into the segregated list. For now brute force */
    for (int i = 0; i < LIST_SIZE; i++) {
        /* We are searching for which memory chunk is appropriate (2-1024). Cast so we can index into memory */
        Page *page = (Page *) segregatedList[i];
        if (page == NULL) {
            exit(PAGE_NULL);
        }

        if (page->size < size) {
            continue;
        }
            /* We have found our desired memory location */
        else {
            /* This should move forward by the sizeof(Page), which would be the location of the first pointer
             * of the free list */
            // page++;
        }
    }
}

//munmap(page, PAGESIZE);