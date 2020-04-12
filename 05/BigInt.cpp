#include <iostream>
#include "BigInt.h"


BigInt::BigInt() : num(nullptr), size(0), sign(true) {}

BigInt::BigInt(int value) {
    if (!value) {
        size = 1;
        sign = true;
        num  = new char[1];
        num[0] = 0;
    } else {
        size = 0;
        sign = true;
        int tmp = value;
        while (tmp) {
            ++size;
            tmp /= 10;
        }
        num = new char[size];
        for (int i = 0; i < size; ++i) {
            num[i] = value % 10;
            value /= 10;
        }
    }
}

BigInt::BigInt(const BigInt& copy) : num(new char[copy.size]), size(copy.size) {
    sign = copy.sign;
    std::copy(copy.num, copy.num + size, num);
}

BigInt& BigInt::operator=(const BigInt& copy) {
    if (this == &copy) {
        return *this;
    }
    char * ptr = new char[copy.size];
    delete [] num;
    num = ptr;
    sign = copy.sign;
    size = copy.size;
    std::copy(copy.num, copy.num + size, num);
    return *this;
}

BigInt BigInt::plus(const BigInt& a_r) const {
    if (size >= a_r.size) {
        BigInt res;
        bool fl = false;
        for (int i = 0; i < size; ++i) {
            int r = i < a_r.size ? a_r.num[i] : 0;
            fl = (num[i] + r + fl) > 9;
        }
        res.size = size + fl;
        res.sign = true;
        res.num = new char[res.size];
        fl = false;
        for (int i = 0; i < res.size; ++i) {
            int a = i < a_r.size ? a_r.num[i] : 0;
            int b = i < size ? num[i] : 0;
            res.num[i] = (a + b + fl) % 10;
            fl = (a + b + fl) > 9;
        }
        return res;
    }
    return a_r.plus(*this);
}

BigInt BigInt::minus(const BigInt& a_r) const{
    BigInt res;
    res.size = 0;
    res.sign = true;
    bool add = false;
    for (int i = 0; i < size; ++i) {
        int a = i < size ? a_r.num[i] : 0;
        int digit = num[i] - add - a;
        add = digit < 0;
        if (digit) {
            res.size = i + 1;
        }
    }
    if (!res.size) {
        return BigInt(0);
    }
    res.num = new char[res.size];
    add = false;
    for (int i = 0; i < res.size; ++i) {
        int b = i < a_r.size ? a_r.num[i] : 0;
        int digit = num[i] - add - b;
        add = digit < 0;
        res.num[i] =  add ? 10 + digit : digit;
    }
    return res;
}

bool BigInt::abs_(const BigInt& a_r) const {
if (size < a_r.size) {
    return true;
} else if (size > a_r.size)
    return false;
for (int i = size - 1; i >= 0; --i) {
    if (num[i] < a_r.num[i]) {
        return true;
    } else if (num[i] > a_r.num[i]) {
        return false;
    }
}
return false;
}

BigInt BigInt::operator+(const BigInt& a_r) {
    BigInt a_l(*this);
    if (a_l.sign == a_r.sign) {
        return a_l.sign ? a_l.plus(a_r) : -a_l.plus(a_r);
    } else if (a_l.sign) {

        return !a_l.abs_(a_r) ? a_l.minus(a_r) : -a_r.minus(a_l);
    }
    return !a_l.abs_(a_r) ? -a_l.minus(a_r) : a_r.minus(a_l);
}
BigInt BigInt::operator-() const {
    BigInt res(*this);
    if (res.size == 1 && res.num[0] == 0) {
        return res;
    }
    res.sign = !sign;
    return res;
}
BigInt BigInt::operator-(const BigInt& a_r) {
    return BigInt(*this) + (-a_r);
}
std::ostream& operator<<(std::ostream &out, const BigInt &value) {
    if (!value.sign) {
        out << '-';
    }
    for (int i = value.size - 1; i >= 0; --i) {
        out << static_cast<char>(value.num[i] + '0');
    }
    return out;
}

bool operator==(const BigInt& a_r, const BigInt& a_l) {
    if (a_l.sign == a_r.sign && a_l.size == a_r.size) {
        for (int i = 0; i < a_r.size; ++i) {
            if (a_r.num[i] != a_l.num[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const BigInt& a_r, const BigInt& a_l) {
    return !(a_r==a_l);
}

bool operator>(const BigInt& a_r, const BigInt& a_l) {
    if (a_r.sign > a_l.sign) {
        return true;
    } else if (a_r.sign < a_l.sign) {
        return false;
    }
    if (a_r.sign) {
        return a_l.abs_(a_r);
    }
    return !a_l.abs_(a_r);
}

bool operator<(const BigInt& a_r, const BigInt& a_l) {
    return a_l > a_r;
}

bool operator<=(const BigInt& a_r, const BigInt& a_l) {
    return a_r == a_l || a_r < a_l;
}
bool operator>=(const BigInt& a_r, const BigInt& a_l) {
    return a_r == a_l || a_r > a_l;
}

BigInt::~BigInt() {
    delete [] num;
}