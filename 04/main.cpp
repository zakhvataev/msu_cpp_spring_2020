#include <iostream>
#include "serializer.h"
#include <sstream>
#include <cassert>


struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template<class Deserizlizer>
    Error deserialize(Deserizlizer& deserializer) {
        return deserializer(a, b, c);
    }
};



int main() {
    Data x { 1, true, 2 };

    std::stringstream stream;

    Serializer serializer(stream);
    serializer.save(x);

    Data y { 0, false, 0 };

    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);

    std::stringstream stream_("1 0 1");
    Deserializer des_(stream_);
    assert(des_.load(y) == Error::CorruptedArchive);

    std::stringstream stream__("false 0");
    Deserializer des__(stream__);
    assert(des__.load(y) == Error::CorruptedArchive);
}