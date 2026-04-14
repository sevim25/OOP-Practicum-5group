#include "Pair.hpp"
#include <iostream>

int main()
{
	Pair<std::string, int> p1("apples", 4);
	Pair<std::string, int> p2("oranges", 9);
	Pair<std::string, int> p3("apples", 4);
	
	if (p1 == p2) {
		std::cout << "p1 and p2 are equal";
	}
	else {
		std::cout << "p1 and p2 are different\n";
	}

	if (p1 == p3) {
		std::cout << "p1 and p3 are equal";
	}
}

