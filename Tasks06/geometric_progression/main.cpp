#include "GeometricProgression.h"
#include <iostream>

int main()
{
    GeometricProgression p1(1, 3);
    GeometricProgression p2(2, 2);

    GeometricProgression p3 = p1 + p2;
    GeometricProgression p4 = p1 * p2;

    std::cout << p3 <<'\n';
    std::cout << p4 << '\n';

    std::cout << "The element at index 3 is " << p1[3] << '\n';
    std::cout << "The sum of the geometric progression is " << p1(4);
}

