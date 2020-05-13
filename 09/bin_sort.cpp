#include "secondary_functions.cpp"

void file_sort(std::ofstream& out) {
    std::ifstream in("file_in", std::ios::binary);
    
    if (!in) {
        throw std::runtime_error("Can't open file: file_in");
    }

    std::vector<std::string> names;
    auto *buf = new uint64_t [MAXSIZE];
    
    for (int i = 0; !in.eof(); ++i) {
        std::string name = "file_out" + std::to_string(i) + ".bin";
        names.push_back(name);

        in.read((char*) buf, MAXSIZE);
        size_t cnt = in.gcount();

        if(cnt){
            size_t read_ = cnt / (2 * sizeof(uint64_t));

            std::thread th1([buf, read_]() {
                std::sort(buf, buf + read_);
            });

            std::thread th2([buf, read_]() {
                std::sort(buf + read_, buf + 2 * read_);
            });

            th1.join();
            th2.join();

            out.open(name, std::ios::binary);
            if(!out.is_open()) {
                delete[] buf;
                throw std::runtime_error("Can't open file: " + name);
            }
            out.write((char*) buf, read_ * sizeof(uint64_t));
            out.close();
            ++i;

            name = "file_out" + std::to_string(i) + ".bin";
            names.push_back(name);
            out.open(name, std::ios::binary);
            if(!out.is_open()){
                delete[] buf;
                throw std::runtime_error("Can't open file: " + name);
            }
            out.write((char*) (buf + read_), cnt - read_ * sizeof(uint64_t));
            out.close();
        }
    }
    
    delete[] buf;
    merge_sorted_files(names);
    clean_files(names);
    in.close();
}