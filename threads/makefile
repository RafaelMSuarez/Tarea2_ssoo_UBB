CC = g++
CFLAGS = -Wall
LIBS = `pkg-config --cflags --libs opencv4`

all: grisThreads

grisThreads: grisThreads.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f grisThreads