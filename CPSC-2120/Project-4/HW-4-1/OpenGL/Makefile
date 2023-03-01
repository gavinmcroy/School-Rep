#all: graphics.cpp graphics.h main.cpp
	#g++ main.cpp graphics.cpp -std=c++11 -lglut -lGL -lGLU -Ofast
#-I/usr/include/GL


#all: graphics.cpp graphics.h Blur.cpp Blur.h ImageObject.cpp ImageObject.h SeamCarving.cppSeamCarving.h main.cpp
	#g++ main.cpp graphics.cpp Blur.cpp ImageObject.cpp SeamCarving.cpp -std=c++17 -framework GLUT -framework OpenGL -Ofast

all: graphics.cpp graphics.h Blur.cpp Blur.h ImageObject.cpp ImageObject.h SeamCarving.cpp SeamCarving.h main.cpp
	g++ main.cpp graphics.cpp Blur.cpp ImageObject.cpp SeamCarving.cpp -std=c++17 -I/usr/include/GL -lglut -lGL -lGLU -Ofast

