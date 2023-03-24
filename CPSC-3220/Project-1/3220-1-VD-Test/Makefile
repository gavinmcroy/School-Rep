
CC=clang
CFLAGS=-Wall -g

BINS= leakcount shim.dylib mallocTest 


all: $(BINS)

leakcount: leakcount.c
	$(CC) $(CFLAGS) -o leakcount leakcount.c

shim.dylib: shim.c
	$(CC) $(CFLAGS) -shared -fPIC shim.c -o shim.dylib -ldl

mallocTest: mallocTest.c
	$(CC) $(CFLAGS) -o mallocTest mallocTest.c

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
