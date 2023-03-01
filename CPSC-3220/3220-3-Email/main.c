#include <stdio.h>
#include <stdbool.h>
#include "allocator.h"

//typedef struct Node {
//    char *next;
//} Node;

int main() {
    /* This is testing that the piece of meta data in the page is the pages size */
    //  int * pointer = (int *)malloc(sizeof(int));
    // printf("%d\n",*pointer);
    int fd = open("/dev/zero", O_RDWR);

    if (fd == -1) {
        exit(FD_ERROR);
    }

    /* Memory request to OS and initialized to 0 */
    void *page = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if (page == MAP_FAILED) {
        exit(MAP_ERROR);
    }

    /* Figure out how to build linked list out of pages */
    char *start = page;
    for (int i = 0; i < 8; i++) {
        if (i % 4 == 0) {
            start[i] = 'X';
        } else {
            start[i] = 'A';
        }
    }
    /* Moving past all the header information */
    char *x = (char *) page + 8;
   // printf("%c\n", *(x));

    /* This should give me a 2 byte chunk of memory free to modify */
    Node *node = (Node *) x;
    int offset = 2;
    node->next = (struct Node *) (((char *) (node)) + sizeof(char *) + offset);

    /* Note, location of x has changed */
    x += sizeof(char *) + offset;
    /* This is moved forward + 10. Keep track of this. 8 is taken for header information */
    unsigned int remaining = 4096 - 18;
    /* While memory is still available in the page */
    while (remaining > (sizeof(char *) + offset)) {
        Node *node1 = (Node *) x;
        node1->next = (struct Node *) ((char *) node + sizeof(char *) + offset);

        /* Our page pointer needs to move to the next chunk */
        x += sizeof(char *) + offset;
        remaining -= (sizeof(char *) + offset);
    }

    short * testing = (short*)malloc(sizeof(short));
    *testing = 5;
    //printf("%d\n",*testing);




/* Figuring out how pointers index */
//    char *data = {"Hello123456789"};
//    for (int i = 0; i < 4; i++) {
//        printf("%c", *data);
//        data = (int *) data + 1;
//    }



    //char * nextNode = ;


    return 0;
}
