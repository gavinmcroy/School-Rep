CC=gcc
CFLAGS=-Wall -c

BINS=mythreads.o libmythreads.a

all: $(BINS)

mythreads.o: mythreads.c mythreads.h
	$(CC) $(CFLAGS) mythreads.c

libmythreads.a: mythreads.o
	ar -cvr libmythreads.a mythreads.o

clean:
	rm $(BINS)