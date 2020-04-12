#include <iostream>
#include<vector>
#include<sstream>

template <class T>

std::string to_str(T&& x) {
    std::stringstream s;
    s << x;
    return s.str();
}

template<class... argsT>
std::string format(const std::string& str, argsT&&... args) {
    std::stringstream out;
    if (str.find("{}") != std::string::npos) {
        throw std::runtime_error("");
    }
    std::vector<std::string> param = {to_str(std::forward<argsT>(args))... };
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '{') {
            ++i;
            int r = 0;
            while(str[i] != '}') {
                if (i > str.size() - 1  || !isdigit(str[i])) {
                    throw std::runtime_error("");
                }
                r *= 10;
                r += str[i] - '0';
                ++i;
            }
            ++i;
            if (r >= param.size()) {
                throw std::runtime_error("");
            }
            out << param[r];
        }
        if (str[i] == '}') {
            throw std::runtime_error("");
        } else if (str[i] != '\0'){
            out << str[i];
        }
    }
    return out.str();
}