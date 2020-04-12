CC=g++
CFLAGS = -c

all: main.o BigInt.o
	$(CC) main.o BigInt.o -o start
test: 
	./start
main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
BigInt.o: BigInt.cpp BigInt.h
	$(CC) $(CFLAGS) BigInt.cpp
clean:
	rm -rf *.o start