#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <algorithm>

#include "bin_sort.cpp"
#include "rand_bin.cpp"

int main(){
    std::ofstream out("file_in", std::ios::binary);
    
    if (!out) {
        std::cerr << "Can't open file: file_in" << std::endl;
        return 1;
    }

    create_bin_file(out);
    out.close();
    
    try {
        file_sort(out);
    }

    catch(const std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
    return 0;
}