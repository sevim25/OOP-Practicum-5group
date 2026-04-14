
#include <iostream>
#include "Vector.hpp"

using std::cout;

int main()
{
	Vector<int> v1;

	v1.push_back(6);
	v1.push_back(8);
	v1.push_back(10);
	cout << "capacity and size - v1: " << v1.getCapacity() << " " << v1.getSize() << '\n';
	cout << "v1(" << v1 << ")" << '\n';

	cout << '\n';

	v1.push_back(11);
	cout << "after push_back(11) v1(" << v1 << ")" << '\n';

	v1.insert(2, 22);
	cout << "after inser(2, 22)  v1(" << v1 << ")" << '\n';

	v1.erase(1);
	cout << "after erase(1)      v1(" << v1 << ")" << '\n';

	cout << '\n';

	Vector<int> v2;
	cout<< "capacity and size - v2: " << v2.getCapacity() << " " << v2.getSize() << '\n';
	v2.push_back(1);
	v2.push_back(2);
	cout << "v2(" << v2 << ")" << '\n';

	v2.shrink_to_fit();
	cout << "capacity and size after shrink_to_fit() - v2: " << v2.getCapacity() << " " << v2.getSize() << '\n';

	cout << '\n';

	v1.clear();
	cout << v1;
}

