#include <iostream>
#include <cassert>
#include "vector.h"
#include <sstream>

void test1() {
    Vector<int> v(5);
    std::stringstream s;
    for (auto &x :v) {
        s << x;
    }
    assert(s.str() == "00000");
}

void test2() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    std::stringstream s;
    for(auto &x: v) {
        s << x;
    }
    assert(s.str() == "54321");
    v.clear();
    assert(v.size() == 0);
}

void test3() {
    Vector<int> v(5);
    v.resize(20);
    assert(v.size() == 20);
}

void test4() {
    Vector<int> v(5);
    std::stringstream s;
    for (auto it = v.begin(); it != v.end(); ++it) {
        s << *it;
    }
    assert(s.str() == "00000");
}

void test5(){
    Vector<int> v(3);
    v.reserve(10000);
    assert(v.capacity() == 10000);
    v.clear();
    assert(v.capacity() == 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
}