CC=g++
CFLAGS = -c

all: main.o 
	$(CC) main.o -o serializer
test: 
	./serializer
main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o matrix_op