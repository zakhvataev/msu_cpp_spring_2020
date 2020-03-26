#include <string>
#include "matrix_class.h"

std :: string b_to_s(bool b){
    if(b)
        return "true";
    else
        return "false";

}
void test(){
    Matrix A(3,2);
    Matrix B(4,5);
    std :: cout << "MATRIX A:" << std :: endl;
    A.print();
    std :: cout << "MATRIX B:" << std :: endl;
    B.print();
    std :: cout << "____________" << std :: endl;
    std :: cout << "A == B: " << b_to_s(A == B) << std :: endl;
    std :: cout << "____________" << std :: endl;
    std :: cout << "A *= 2: " << std :: endl;
    A *= 2;
    A.print();
    std :: cout << "____________" << std :: endl;
    std :: cout << "Get: A[1][0] = " << A[1][0] << std :: endl;
    std :: cout << "____________" << std :: endl;
    std :: cout << "Put A[1][1] = 10000: " << std :: endl;
    A[1][1] = 10000;
    A.print();
    B = A;
    std :: cout << "Put (B = A) => (A == B): " <<  b_to_s(A == B) << std :: endl;
}
