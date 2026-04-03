
#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix A(2);
    Matrix B(2);

    std::cout << "enter matrix A(2x2): ";
    std::cin >> A;

    std::cout << "enter matrix B(2x2): ";
    std::cin >> B;
    
    A += B;
    std::cout << A << '\n';

    Matrix C = A * B;
    std::cout << "C = A * B = \n";
    std::cout << C << '\n';

    Matrix D = A + B;
    std::cout << "D = A + B = \n";
    std::cout << D << '\n';

    C *= 5;
    std::cout << C << '\n';

    if (A < B) {
        std::cout << "A < B";
    }
}

