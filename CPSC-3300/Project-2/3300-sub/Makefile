
CC=g++
CFLAGS=-Wall -g -std=c++14

BINS=main


all: $(BINS)

main : main.cpp MipsInterpret.cpp
	$(CC) $(CFLAGS) -o main main.cpp MipsInterpret.cpp

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
