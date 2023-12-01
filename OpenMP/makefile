CC = g++
CFLAGS = -Wall
LIBS = `pkg-config --cflags --libs opencv4` -fopenmp

all: grisOpenMP

grisOpenMP: grisOpenMP.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f grisOpenMP