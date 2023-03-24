
CC=clang
CFLAGS=-Wall -g

BINS=memory_shim.so leakcount sctracer


all: $(BINS)

memory_shim.so: memory_shim.c
	$(CC) $(CFLAGS) -shared -fPIC memory_shim.c -o memory_shim.so -ldl

leakcount : leakcount.c
	$(CC) $(CFLAGS) -o leakcount leakcount.c
sctracer : sctracer.c
	$(CC) $(CFLAGS) -o sctracer sctracer.c

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
