#include "matrix_class.h"

Matrix :: Matrix(){
    srand(time(NULL));
    this -> rows_n = (rand() % 9) + 1;
    this -> columns_m = (rand() % 9) + 1;
    set();
}

Matrix :: Matrix(int rows_n, int columns_m){
    this -> rows_n = rows_n;
    this -> columns_m = columns_m;
    set();
}

void Matrix :: set(){
    srand(time(NULL));
    mtrx = new int*[rows_n];
    for(int i = 0; i < rows_n; i++){
        mtrx[i] = new int[columns_m];
    }
    for(int i = 0; i < rows_n; i++){
        for(int j = 0; j < columns_m; j++){
            mtrx[i][j] = rand() % 99;
        }
    }
}

int Matrix :: get_rows() const{
    return rows_n;
}

int Matrix :: get_columns() const{
    return columns_m;
}


void Matrix :: print() const{
    for(int i = 0; i < columns_m; i++)
        std :: cout << "______";
    std :: cout << std :: endl;
    for(int i = 0; i < rows_n; i++){
        for(int j = 0; j < columns_m; j++){
            std :: cout.width(6);
            std :: cout << mtrx[i][j];
        }
        std :: cout << std :: endl;
    }
    for(int i = 0; i < columns_m; i++)
        std :: cout << "______";
    std :: cout << std :: endl;
    std :: cout << ">>Rows: " << get_rows() << std :: endl;
    std :: cout << ">>Columns: " << get_columns() << std :: endl;
}

Index Matrix :: operator [] (int rows) const{
    if(rows > rows_n || rows < 0)
        throw std :: out_of_range("BadIndex[!][]");
    return Index(*this, rows);
}

int& Index :: operator [] (int cols) const{
    if(cols > a.columns_m || cols < 0)
        throw std :: out_of_range("BadIndex[][!]");
    return a.mtrx[rows][cols];
}

bool Matrix :: operator == (const Matrix &a) const{
    if(columns_m != a.columns_m || rows_n != a.rows_n)
        return false;
    for(int i = 0; i < a.rows_n; i++)
        for(int j = 0; j < a.columns_m; j++)
            if(mtrx[i][j] != a.mtrx[i][j])
                return false;
    return true;
}

void Matrix :: operator *= (int x){
    for(int i = 0; i < rows_n; i++){
        for(int j = 0; j < columns_m; j++){
            mtrx[i][j] *= x;
        }
    }
}

void Matrix :: operator = (const Matrix &a)
{
    for(int i = 0; i < rows_n; i++)
        delete[] mtrx[i];
    delete[] mtrx;

    rows_n = a.rows_n;
    columns_m = a.columns_m;
    
    mtrx = new int*[rows_n];

    for(int i = 0; i < rows_n; i++)
        mtrx[i] = new int[columns_m];

    for(int i = 0; i < rows_n; i++)
        for(int j = 0; j < columns_m; j++)
            mtrx[i][j] = a.mtrx[i][j];
}

Matrix :: ~Matrix(){
    for(int i = 0; i < rows_n; i++)
        delete[] mtrx[i];
    delete[] mtrx;
}