
CC=g++
CFLAGS=-Wall -g -std=c++14 -lOpenImageIO
LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lOpenImageIO


BINS= main


all: $(BINS)


main : main.cpp matrix.cpp Warp.cpp Display.cpp
	$(CC) $(CFLAGS) -o main main.cpp matrix.cpp Warp.cpp Display.cpp ${LDFLAGS}

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
	$(RM) -r *.o
