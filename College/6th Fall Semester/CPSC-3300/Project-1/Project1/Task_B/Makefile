all: dgmake

dgmake: dgemm.c
	gcc dgemm.c -O3 -Wall -Wextra -o dgmake -Xclang -fopenmp

clean:
	rm -f dgmake

