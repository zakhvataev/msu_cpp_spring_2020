#include "matrix_class.h"

Matrix :: Row :: Row(int* arr1, size_t cols){
    arr = arr1;
    len = cols;
}

int& Matrix :: Row :: operator [] (size_t j){
    if(j > len){
        throw std :: out_of_range("BadIndex1");
    }
    return arr[j];
}

const int& Matrix:: Row :: operator [] (size_t j) const{
    if(j > len)
        throw std :: out_of_range("BadIndex2");
    return arr[j];
}

Matrix::Row::~Row(){}

Matrix :: Matrix(){
    rows_n = 2;
    columns_m = 2;
    set();
}

Matrix :: Matrix(size_t constr_rows_n, size_t constr_columns_m){
    rows_n = constr_rows_n;
    columns_m = constr_columns_m;
    set();
}

void Matrix :: set(){
    mtrx = new int*[rows_n];
    for(size_t i = 0; i < rows_n; i++){
        mtrx[i] = new int[columns_m];
    }
    for(size_t i = 0; i < rows_n; i++){
        for(size_t j = 0; j < columns_m; j++){
            mtrx[i][j] = 0;
        }
    }
}

size_t Matrix :: get_rows() const{
    return rows_n;
}

size_t Matrix :: get_columns() const{
    return columns_m;
}


void Matrix :: print() const{
    for(size_t i = 0; i < columns_m; i++)
        std :: cout << "______";
    std :: cout << std :: endl;
    for(size_t i = 0; i < rows_n; i++){
        for(size_t j = 0; j < columns_m; j++){
            std :: cout.width(6);
            std :: cout << mtrx[i][j];
        }
        std :: cout << std :: endl;
    }
    for(size_t i = 0; i < columns_m; i++)
        std :: cout << "______";
    std :: cout << std :: endl;
    std :: cout << ">>Rows: " << get_rows() << std :: endl;
    std :: cout << ">>Columns: " << get_columns() << std :: endl;
}

Matrix::Row Matrix::operator[](size_t i) {
    if (i > columns_m) {
        throw std::out_of_range("BadIndex[][!]");
    }
    return Matrix::Row(mtrx[i], columns_m);
}

const Matrix::Row Matrix::operator[](size_t i) const {
    if (i > columns_m) {
        throw std::out_of_range("BadIndex[][!]");
    }
    return Matrix::Row(mtrx[i], columns_m);
}

bool Matrix :: operator == (const Matrix &a) const{
    if(columns_m != a.columns_m || rows_n != a.rows_n)
        return false;
    for(size_t i = 0; i < a.rows_n; i++)
        for(size_t j = 0; j < a.columns_m; j++)
            if(mtrx[i][j] != a.mtrx[i][j])
                return false;
    return true;
}

bool Matrix :: operator != (const Matrix &a) const{
    return !(*this == a);
}

Matrix& Matrix :: operator *= (int x){
    for(size_t i = 0; i < rows_n; i++){
        for(size_t j = 0; j < columns_m; j++){
            mtrx[i][j] *= x;
        }
    }
    return *this;
}

void Matrix :: operator = (const Matrix &a)
{
    for(size_t i = 0; i < rows_n; i++)
        delete[] mtrx[i];
    delete[] mtrx;

    rows_n = a.rows_n;
    columns_m = a.columns_m;
    
    mtrx = new int*[rows_n];

    for(size_t i = 0; i < rows_n; i++)
        mtrx[i] = new int[columns_m];

    for(size_t i = 0; i < rows_n; i++)
        for(size_t j = 0; j < columns_m; j++)
            mtrx[i][j] = a.mtrx[i][j];
}

Matrix :: ~Matrix(){
    for(size_t i = 0; i < rows_n; i++)
        delete[] mtrx[i];
    delete[] mtrx;
}