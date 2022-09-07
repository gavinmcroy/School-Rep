//
// Created by Gavin Taylor Mcroy on 10/27/21.
//
#include "allocator.h"

void *segregatedList[LIST_SIZE];

void lib_init() {

    int chunkSize = 2;
    /* Setup all of our pages */
    for (int i = 0; i < LIST_SIZE; i++) {
        int fd = open("/dev/zero", O_RDWR);
        int remainingMemory = PAGESIZE;
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

        /* Cast our page into a Page Object pointer, so we can index into the memory. Initializing the header. */
        Page *mem = (Page *) page;
        mem->size = chunkSize;
        mem->nextPage = NULL;
        mem->freeListHead = (page + 1);
        remainingMemory -= sizeof(Page);

        /* TODO Building free list algorithm. X points to beginning of free list. */
        Node *node = mem->freeListHead;
        int iter = 0;
        while (remainingMemory > chunkSize) {
            iter++;
            node->next = (struct Node *) ((char *) node + sizeof(Node) + chunkSize);
            node = node->next;
            /* This should give me a "n" byte chunk of memory free to modify */
            remainingMemory -= (sizeof(Node) + chunkSize);
        }
        /* The point of this the loop will stop on the last available node, set so that this node does
         * not point to anything else */
        node->next = NULL;

        /* 2, 4, 8, 16... */
        chunkSize = chunkSize << 1;
    }
}

void lib_destroy() {
    printf("Library closed \n");
}

void free(void *ptr) {

}

void *malloc(size_t size) {
    Page *page = (Page *) segregatedList[0];
    Node *node = page->freeListHead;
    int iter = 0;
    while (node->next != NULL) {
        node = node->next;
        iter++;
    }
    return segregatedList[0] + 50;
}

void *setupMemoryChunk(size_t size) {
    /* TODO map properly into the segregated list. For now brute force */
    for (int i = 0; i < LIST_SIZE; i++) {
        /* We are searching for which memory chunk is appropriate (2-1024). Cast so we can index into memory */
        Page *page = (Page *) segregatedList[i];
        if (page == NULL) {
            exit(PAGE_NULL);
        }

        if (page->size <= size) {
            continue;
        }
            /* We have found our desired memory location */
        else {
            /* Position our pointer to the first free chunk of memory.
             * TODO Warning we are hard coding first chunk only to be allocated */
            /* Stored as follows [METADATA,HEAD_POINTER,DATA,POINTER,DATA] */
            void *pointer = (char *) segregatedList[i] + sizeof(Page) + sizeof(char *);
            return pointer;
        }
    }
}

//munmap(page, PAGESIZE);