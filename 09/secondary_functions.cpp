const std::string COPY = "copy";
const size_t MAXSIZE = 1024 * 1024;

void copy(const std::string& name1, const std::string& name2){
    auto *buf = new uint64_t [MAXSIZE];
    std::ifstream in(name1, std::ios::binary);
    std::ofstream out(name2, std::ios::binary);

    while (!in.eof()) {
        in.read((char*) buf, 1024 * 1024);
        if (in.gcount()) {
            out.write((char*) buf, in.gcount());
        }
    }
    out.close();
    in.close();
    delete[] buf;
}

void merge_sorted_files(std::vector<std::string>& f_names){
    copy(f_names[0], "file_out");
    std::ifstream in(COPY, std::ios::binary);
    std::ofstream out("file_out", std::ios::binary);
    uint64_t c1, c2;
    
    for (size_t i = 1; i < f_names.size(); ++i) {
        copy("file_out", COPY);
        std::ifstream tmp(f_names[i], std::ios::binary);

        in.read((char*) &c1, sizeof(c1));
        tmp.read((char*) &c2, sizeof(c2));

        while (!tmp.eof()) {
            if(!in.gcount()) {
                while (!tmp.eof()) {
                    out.write((char*) &c2, sizeof(c2));
                    tmp.read((char*) &c2, sizeof(c2));
                }
            } else if (c2 <=  c1) {
                out.write((char*) &c2, sizeof(c2));
                tmp.read((char*) &c2, sizeof(c2));
            } else {
                out.write((char*) &c1, sizeof(c1));
                in.read((char*) &c1, sizeof(c1));
            }
        }

        if (in.gcount()) {
            out.write((char*) &c1, sizeof(c1));
            auto *buf = new uint64_t[MAXSIZE];

            while (!in.eof()) {
                in.read((char*) buf, MAXSIZE);
                out.write((char*) buf, in.gcount());
            }
            delete[] buf;
        }
    }
}

void clean_files(std::vector<std::string>& names) {
    for (auto &name: names) {
        if (remove(name.c_str())) {
            throw std::runtime_error("Can't remove file");
        }
    }
    
    if (remove(COPY.c_str())) {
        throw std::runtime_error("Can't remove file");
    }
}