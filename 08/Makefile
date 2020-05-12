all: thread_pool

thread_pool: main.o
	g++ main.o -lpthread -o start

main.o:  main.cpp
	g++ -c main.cpp --std=c++14

test: thread_pool
	./start

run: thread_pool
	./start

clean:
	rm -rf *.o start