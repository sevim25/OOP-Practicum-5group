#include "GeometricVector.h"
#include <iostream>

int main()
{
    GeometricVector v1;
    std::cout << "v1" << v1 << '\n';

    int data[] = { 1,2,3,4 };
    GeometricVector v2(data, 4);
    std::cout << "v2" << v2 << '\n';

    GeometricVector v3(3);
    std::cout << "v3" << v3 << '\n';

    GeometricVector v4(v2);
    std::cout << "v4" << v4 << '\n';

    GeometricVector v5 = v2 + v3;
    std::cout << "v5" << v5 << '\n';

    std::cout << '\n';

    std::cout << "The cos between v2 and v5 is:  " << getCos(v2, v5) << '\n';
    std::cout << "The scalar product of v2 and v5 is:  " << v2 % v5 << '\n';

    GeometricVector vectorProduct = v2 ^ v5;
    std::cout << "The vector product of v2 and v5 is:  " << vectorProduct << '\n';

    std::cout << '\n';


    std::cout <<"The element at index 3 of v2 is " << v2[3] << '\n';;
    std::cout << "The length of v2 is " << v2.getLen() << '\n';
    v2 += v3;
    std::cout << "v2" << v2 << '\n';
}

