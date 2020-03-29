#include <iostream>

class Matrix{
    size_t rows_n, columns_m;
    int **mtrx;

    class Row{
        size_t len;
        int* arr;
    public:
        Row(int*, size_t);
        int& operator[](const size_t) ;
        const int& operator[](const size_t) const;
        ~Row();
    };
public:
    Matrix(void);
    Matrix(size_t, size_t);

    void set(void);

    size_t get_rows(void)const;
    size_t get_columns(void)const;

    void print(void) const;

    void operator = (const Matrix &);
    Matrix& operator *= (int);

    bool operator == (const Matrix &) const;
    bool operator != (const Matrix &) const;

    Row operator [] (const size_t);
    const Row operator[](const size_t) const;
    
    ~Matrix();
};
