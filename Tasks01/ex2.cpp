#include <iostream>

struct ComplexNumber {
    double real;
    double imaginary;

    void printNum() {
        if (imaginary > 0) {
            std::cout << "z = " << real << " + " << imaginary << "i" << '\n';
        }
        else
            std::cout << "z = " << real << " - " << -imaginary << "i" << '\n';

    }
};

namespace ComplexMath {

    ComplexNumber add(ComplexNumber z1, ComplexNumber z2) {
        return { z1.real + z2.real, z1.imaginary + z2.imaginary };
    }

    ComplexNumber multiply(ComplexNumber z1, ComplexNumber z2) {
        double realRes = z1.real * z2.real - z1.imaginary * z2.imaginary;
        double imRes = z1.real * z2.imaginary + z1.imaginary * z2.real;

        ComplexNumber result = { realRes, imRes };

        return result;
    }

    ComplexNumber divide(ComplexNumber z1, ComplexNumber z2) {
        double divisor = z2.real * z2.real + z2.imaginary * z2.imaginary;

        double realRes = (z1.real * z2.real + z1.imaginary * z2.imaginary) / divisor;
        double imRes = (z1.imaginary * z2.real - z1.real * z2.imaginary) / divisor;

        ComplexNumber result = { realRes, imRes };

        return result;
    }
}

int main()
{

    ComplexNumber z1;
    ComplexNumber z2;

    std::cin >> z1.real >> z1.imaginary;
    std::cin >> z2.real >> z2.imaginary;

    using namespace ComplexMath;
    ComplexNumber sum = add(z1, z2);
    ComplexNumber product = multiply(z1, z2);
    ComplexNumber quotient = divide(z1, z2);

    sum.printNum();
    product.printNum();
    quotient.printNum();

}

