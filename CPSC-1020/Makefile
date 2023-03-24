CC	= gcc
INCLUDE	= -I.
CFLAGS	= -g -Wall
LDFLAGS	= -L. -L/usr/lib
LDLIBS	= -lc -lm

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

main: main.o dtob.o btod.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f *.o
	rm -f main
