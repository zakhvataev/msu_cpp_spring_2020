CC = g++
CFLAGS = -c

all: main.o makeAllocator.o test_module.o
	$(CC) main.o makeAllocator.o test_module.o -o Allocator

test:
	./Allocator

main.o: main.cpp test_module.h
	$(CC) $(CFLAGS) main.cpp

makeAllocator.o: makeAllocator.cpp makeAllocator.h
	$(CC) $(CFLAGS) makeAllocator.cpp

test_module.o: test_module.cpp test_module.h
	$(CC) $(CFLAGS) test_module.cpp

clean:
	rm -rf *.o Allocator
