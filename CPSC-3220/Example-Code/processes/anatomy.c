

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void whereis(char *name, void *p);

void foo(int y) {
	whereis("y",&y);
}

int global;
extern char **environ;

int main(int argc, char **argv)
{
	int x;
	int *z = malloc(sizeof(int));
	foo(7);
	whereis("environ",environ);
	whereis("x",&x);
	whereis("z",z);
	whereis("whereis",whereis);
	whereis("main",main);
	whereis("printf",printf);
}

void whereis(char *name, void *p)
{
	printf("%s = %p (main + %lx)\n",name, p,
		((uintptr_t)p - (uintptr_t)main));
}
