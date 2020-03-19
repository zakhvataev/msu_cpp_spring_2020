CC=g++
CFLAGS = -c

all:
	$(CC) start.o parser.o tester.o -o Tokenizer

test:
	./Tokenizer
start.o:
	$(CC) $(CFLAGS) start.cpp
parser.o:
	$(CC) $(CFLAGS) parser.cpp
tester.o:
	$(CC) $(CFLAGS) tester.cpp

clean:
	rm -rf *.o Tokenizer
