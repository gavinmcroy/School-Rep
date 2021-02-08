#include <stdio.h>

/***********************
 * Gavin McRoy
 * gmcroy
 * Lab 3 and Section 2
 **********************/


struct NODE {
    int a;
    struct NODE *b;
    struct NODE *c;
};

struct NODE nodes[5] = {
        {20, nodes + 3, NULL},
        {59, nodes + 2, nodes + 4},
        {8, NULL,       nodes + 1},
        {44, nodes + 4, nodes},
        {32, nodes + 1, nodes + 3}
};

struct NODE *np = nodes + 2;
struct NODE **npp = &nodes[1].b;


int main() {
    printf("%p\n", nodes);
    printf("ILLEGAL\n");
    printf("%d\n", nodes[3].a);
    printf("%p\n", nodes[3].c);
    printf("%d\n", nodes[3].c->a);
    printf("ILLEGAL\n");
    printf("%d\n", (*nodes).a);
    printf("%d\n", nodes->a);
    printf("%p\n", nodes[3].b->b);
    printf("%p\n", &nodes);
    printf("%p\n", &nodes[3].a);
    printf("%p\n", &nodes[3].c);
    printf("%p\n", &nodes[3].c->a);
    printf("%p\n", &nodes->a);
    printf("%p\n", np);
    printf("%d\n", np->a);
    printf("%p\n", npp);
    printf("ILLEGAL\n");
    printf("%p\n", *npp);
    printf("ILLEGAL\n");
    printf("%d\n", (*npp)->a);
    printf("%p\n", &np);
}
