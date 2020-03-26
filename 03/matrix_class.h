#include <iostream>

class Index;

class Matrix{
    friend class Index;
    int rows_n, columns_m;
    int **mtrx;
public:
    Matrix(void);
    Matrix(int rows_n, int columns_m);
    void set();
    int get_rows();
    int get_columns();
    void print();
    void operator = (const Matrix &a);
    void operator *= (int x);
    bool operator == (const Matrix &a);
    Index operator [] (int rows) const;
    ~Matrix();
};

class Index
{
    const Matrix &a;
    int rows;
public:
    Index(const Matrix& m, int row) : a(m), rows(row) {};
    int& operator [] (int cols) const;
};
