#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;

    void readPoint() {
        std::cin >> x >> y;
    }

    void printPoint() {
        std::cout << "(" << x << ", " << y << ")" << '\n';
    }

    double distanceFromO() {
        return sqrt(x * x + y * y);
    }

    double distanceTo(Point b) {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }

    int getQuadrant() {
        if (x == 0 || y == 0) return 0;

        if (x > 0 && y > 0)
            return 1;
        else if (x > 0 && y < 0)
            return 4;
        else if (x < 0 && y > 0)
            return 2;
        else if (x < 0 && y < 0)
            return 3;
        else
            return -1;
    }

};

int main()
{
    Point p;
    p.readPoint();

    Point p2;
    p2.readPoint();

    double dist0 = p.distanceFromO();
    std::cout << dist0 << '\n';

    double dist = p.distanceTo(p2);
    std::cout << dist << '\n';

    int quadrant = p.getQuadrant();
    std::cout << quadrant << '\n';
}

