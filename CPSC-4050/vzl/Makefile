

OFILES = base/VzlViewer.o \
         base/VzlThing.o \
	 things/MyThing.o \
	 things/Plane.o  \
	 things/Box.o





ROOTDIR = .
LIB = $(ROOTDIR)/lib/libvzl.a 
GLLDFLAGS     = -framework GLUT -framework OpenGL
CXX = g++-11 -Wall -g -O2 -fPIC $(DEFINES) -fopenmp -std=c++11
INCLUDES =  -I ./include/ -I /usr/local/include/ -I/usr/include/ 



.C.o: 
	$(CXX) -c $(INCLUDES) $< -o $@

base: $(OFILES)
	ar rv $(LIB) $?

clean:
	rm -rf *.o base/*.o base/*~ include/*~  core $(LIB) *~  ./vzl  things/*.o things/*~

vzl:	$(OFILES)
	make base
	$(CXX) things/vzl.C  $(INCLUDES) -ldl -L./lib -lvzl $(GLLDFLAGS)  -o vzl


