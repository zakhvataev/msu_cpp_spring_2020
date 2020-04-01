CC=g++
CFLAGS = -c

all: main.o test.o matrix_class.o
	$(CC) main.o test.o matrix_class.o -o start
test: 
	./matrix_op
main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp
test.o: test.cpp test.h
	$(CC) $(CFLAGS) test.cpp
matrix_class.o: matrix_class.cpp matrix_class.h
	$(CC) $(CFLAGS) matrix_class.cpp
clean:
	rm -rf *.o matrix_op