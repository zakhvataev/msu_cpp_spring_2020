CC=g++
CFLAGS = -c

all: main.o format.o
	$(CC) main.o format.o -o start
test: 
	./start
main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
format.o: format.h
	$(CC) $(CFLAGS) format.h
clean:
	rm -rf *.o start