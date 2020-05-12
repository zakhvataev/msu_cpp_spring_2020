#include <iostream>
#include <thread>
#include <cassert>
#include "thread_pool.h"

struct A {};
void foo(const A &) {}


void test() {

    ThreadPool pool(8);
    int s = 1;

    auto task1 = pool.exec(foo, A());
    task1.get();
        
    auto task2 = pool.exec([s]() { return s; });
    assert(task2.get() == 1);

    auto task3 = pool.exec([s]() { return s + 10; });
    assert(task3.get() == 11);

    auto task4 = pool.exec([s]() { return s + 100; });
    assert(task4.get() == 101);
}



int main() {

    test();

    return 0;
}