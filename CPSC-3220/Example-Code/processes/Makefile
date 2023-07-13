CC=clang
CFLAGS=-Wall -g


BINS=forktest hello rawhello exec1 exec2 exec3 exec4 anatomy zombies popen


all: $(BINS)

rawhello: rawsyscall.S
	$(CC) $(CFLAGS) -nostdlib -o rawhello rawsyscall.S

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BINS) 
	$(RM) -r *.dSYM
