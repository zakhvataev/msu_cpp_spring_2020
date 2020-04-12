#include <iostream>
#include <cassert>
#include "BigInt.h"


void test1() {
    BigInt a = 9001;
    BigInt b = 999;
    assert(a + b == 10000);
    assert(a - b == 8002);
}

void test2() {
    BigInt a = 123;
    BigInt b = 321;
    assert(a > b == false);
    assert(a < b == true);
    assert(a == b == false);
    assert(a != b == true);
    assert(a >= b == false);
    assert(a <= b == true);
}

int main() {
    test1();
    test2();
    return 0;
}