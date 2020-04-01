#include <iostream>
#include <exception>

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char Separator = ' ';
    std::ostream &out_;

public:
    explicit Serializer(std::ostream& out) : out_(out){}

    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT... args)
    {
        return process(args...);
    }
    
private:
    template <class T, class... ArgsT>
    Error process(T p, ArgsT... args) {
        put_stream(p);
        return process(args...);
    }

    template <class T>
    Error process(T last) {
        put_stream(last);
        return Error::NoError;
    }

    void put_stream(bool b) {
        if(b)
            out_ << "true" << Separator;
        else
            out_ << "false" << Separator;
    }

    void put_stream(uint64_t value) {
        out_ << value << Separator;
    }
};

class Deserializer {
    
    std::istream &in_;

public:
    explicit Deserializer(std::istream& in) : in_(in) {}

    template <class T>
    Error load(T& object) {
        return object.deserialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT&... args) {
        return process(args...);
    }

private:
    template<class T, class... ArgsT>
    Error process(T& p, ArgsT&... args) {
        if (get_stream(p) == Error::CorruptedArchive) {
            return Error::CorruptedArchive;
        }
        return process(args...);
    }

    template<class T>
    Error process(T& last) {
        return get_stream(last);
    }

    Error get_stream(bool& a) {
        std::string s;
        in_ >> s;
        if (s == "true") {
            a = true;
        }
        else if (s == "false") {
            a = false;
        }
        else {
            return Error::CorruptedArchive;
        }
        return Error::NoError;
    }

    Error get_stream(uint64_t& value) {
        std::string s;
        in_ >> s;

        if (!isdigit(s[0])) {
            return Error::CorruptedArchive;
        }

        try {
            value = std::stoull(s);
        } 
        
        catch(std::exception &e) {
            return Error::CorruptedArchive;
        }

        return Error::NoError;
    }
};