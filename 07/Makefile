all: vector

vector: main.o
	g++ main.o -o start
	
main.o: main.cpp
	g++ -c main.cpp
	
test: vector
	./vector

run: vector
	./vector

clean:
	rm -rf *.o vector