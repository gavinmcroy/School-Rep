
all: notjustcats.c
	gcc notjustcats.c -o notjustcats

pkg: notjustcats.c README makefile
	tar cvzf project4.tgz README makefile notjustcats.c

clean:
	rm notjustcats