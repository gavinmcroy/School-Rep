
CC=g++
CFLAGS=-Wall -g -std=c++14 -lOpenImageIO

BINS= main


all: $(BINS)


main : main.cpp Composite.cpp
	$(CC) $(CFLAGS) -o main main.cpp Composite.cpp

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
	$(RM) -r *.o
