
all: notjustcats.c
	gcc notjustcats.c -o notjustcats

pkg: notjustcats.c notjustcats.h makefile
	tar cvzf project4.tgz makefile notjustcats.c notjustcats.h

clean:
	rm notjustcats