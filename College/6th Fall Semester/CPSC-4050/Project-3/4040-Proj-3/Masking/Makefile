
CC=g++
CFLAGS=-Wall -g -std=c++14 -lOpenImageIO

BINS= main


all: $(BINS)


main : main.cpp Masking.cpp
	$(CC) $(CFLAGS) -o main main.cpp Masking.cpp

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
	$(RM) -r *.o
