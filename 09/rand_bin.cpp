void create_bin_file(std::ofstream &out) {
    for (int i = 0; i < 1024 * 1023; ++i) {
        uint64_t rand_num = rand() % 113;
        out.write((char *) &rand_num, sizeof(rand_num));
    }
}