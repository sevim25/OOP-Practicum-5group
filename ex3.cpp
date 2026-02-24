#include <iostream>
#include <cmath>

struct Triangle {
    double a, b, c;

    bool isTriangle() {
        return a > 0 && b > 0 && c > 0 &&
            a + b > c && a + c > b && b + c > a;
    }

    double getArea() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

namespace TriangleSort {

    void readTriangle(Triangle* allTriangles, int N) {
        for (int j  = 0; j < N; j++)
        {
            std::cin >> allTriangles[j].a
                >> allTriangles[j].b
                >> allTriangles[j].c;
        }
    }
    
    void swap(Triangle& a, Triangle& b) {
        Triangle temp = a;
        a = b;
        b = temp;
    }

    void bubbleSort(Triangle* allTriangles, int N) {
        if (!allTriangles) return;
        
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N -1 - i; j++)
            {

                if (allTriangles[j].getArea() > allTriangles[j + 1].getArea()) {
                    swap(allTriangles[j], allTriangles[j+1]);
                }
            }
        }
    }

    void printTriangles(Triangle* allTriangles, int N) {
        std::cout << '\n';
        for (size_t j = 0; j < N; j++)
        {
            if (allTriangles[j].isTriangle()) {
                std::cout << allTriangles[j].a << " " << allTriangles[j].b << " " << allTriangles[j].c << '\n';          
            }
           
        }
    }
}

int main()
{
    int N;
    std::cin >> N;
    Triangle* allTriangles = new Triangle[N];

    using namespace TriangleSort;
    readTriangle(allTriangles, N);
    bubbleSort(allTriangles, N);
    printTriangles(allTriangles, N);

    delete[] allTriangles;
}
