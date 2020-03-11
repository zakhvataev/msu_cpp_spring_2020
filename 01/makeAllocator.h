#include <iostream>

class makeAllocator{
	char * ptr_begin;
	char * ptr_curr;
	char * ptr_end;
public:
	makeAllocator(size_t maxSize);
	char * alloc(size_t size);
	void reset();
	void information();
	~makeAllocator();
};
