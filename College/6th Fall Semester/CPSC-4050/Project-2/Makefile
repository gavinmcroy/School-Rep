
CC=g++
CFLAGS= -lOpenImageIO -lm -Wall -std=c++17

BINS=main scene camera imagePlane light plane ray sphere triangle


all: $(BINS)

main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp

camera: Camera.cpp
	$(CC) $(CFLAGS) -o camera Camera.cpp

imagePlane: imagePlane.cpp
	$(CC) $(CFLAGS) -o imagePlane ImagePlane.cpp

light: Light.cpp
	$(CC) $(CFLAGS) -o light Light.cpp

plane: Plane.cpp
	$(CC) $(CFLAGS) -o plane Plane.cpp

ray: Ray.cpp
	$(CC) $(CFLAGS) -o ray Ray.cpp

scene: Scene.cpp
	$(CC) $(CFLAGS) -o scene Scene.cpp

sphere: Sphere.cpp
	$(CC) $(CFLAGS) -o sphere Sphere.cpp

triangle: Triangle.cpp
	$(CC) $(CFLAGS) -o triangle Triangle.cpp

clean:
	rm $(BINS)
