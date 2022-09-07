

OFILES = base/VzlViewer.o \
         base/VzlThing.o \
	 things/NgonThing.o \
	 things/Face.o  \
	 things/Ngon.o





ROOTDIR = .
LIB = $(ROOTDIR)/lib/libvzl.a 
GLLDFLAGS     = -framework GLUT -framework OpenGL -Xpreprocessor -fopenmp 
CXX = g++ -Wall -g -O2 -fPIC $(DEFINES) -std=c++17 
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


