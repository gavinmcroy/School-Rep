
CC=clang
CFLAGS=-Wall -g


BINS=address brk_example mmap_example memterm1 memterm2 memterm3 pagesize
all: $(BINS)


%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BINS) *.o a.out