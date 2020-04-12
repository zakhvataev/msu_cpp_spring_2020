#include <iostream>
#include <sstream>
#include <cassert>
#include "format.h"


void test1() {
    assert(format("{0} + {0} = {1}", "one", 2) == "one + one = 2");
}

void test2() {
    assert(format("{0} msg", "1111") == "1111 msg");
}

void test3() {
    assert(format("msg {0} {1} {0}", "1", false) == "msg 1 0 1");
}

void test4() {
    bool error = false;
    try {
        auto t = format("{", 1);
    }
    catch(const std::runtime_error& err) {
        error = true;
        assert(error);
    }
}

void test5() {
    bool error = false;
    try {
        auto t = format("{} {0}", 1);
    }
    catch(const std::runtime_error& err) {
        error = true;
        assert(error);
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}