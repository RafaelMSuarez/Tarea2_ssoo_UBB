CC = g++
CFLAGS = -Wall
LIBS = `pkg-config --cflags --libs opencv4`

all: grisSecuencial

grisSecuencial: grisSecuencial.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f grisSecuencial