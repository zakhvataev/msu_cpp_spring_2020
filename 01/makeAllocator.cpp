#include "makeAllocator.h"

makeAllocator :: makeAllocator(size_t maxSize){
	ptr_begin = (char *)malloc(maxSize);
	if(!ptr_begin)
		throw std::bad_alloc();
	ptr_curr = ptr_begin;
	ptr_end = ptr_begin + maxSize;
}

char* makeAllocator :: alloc(size_t size){
	char * tmp;
	tmp = ptr_curr;
	ptr_curr += size;
	if(ptr_curr > ptr_end){
		ptr_curr -= size;
		return nullptr;
	}
	return tmp;
}

void makeAllocator :: reset(){
	ptr_curr = ptr_begin;
}

void makeAllocator :: information(){
	std::cout << "Size Of memory:  " << (size_t)(ptr_end - ptr_begin) << std::endl;
	//std::cout << "Start pointer:  " << (size_t)ptr_begin << std::endl;
	std::cout << "Current pointer adress:  " << (size_t)(ptr_curr) << std::endl;
	std::cout << "The rest of the memory:  " << (size_t)(ptr_end - ptr_curr) << std::endl;
	std::cout << "Current pointer:  " << (size_t)(ptr_curr - ptr_begin) << std::endl;
	std::cout << std::endl;
}

makeAllocator :: ~makeAllocator(){
	free(ptr_begin);
}
