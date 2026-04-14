
#include "Map.hpp"
#include "../Pair_task/Pair.hpp"
#include <iostream>


using std::cout;

int main()
{
	Map<std::string, int> map;
	cout << "Product - quantity\n";
	map.add("apples", 10);
	map.add("Carrots", 4);
	map.add("Oranges", 8);

	cout << map;

	cout << "size and capacity: " << map.size() << " " << map.capacity() << '\n';;

	map.remove("Carrots");
	cout <<"After removing carrots:\n" << map;

	if (map.contains("strawberries")) {
		cout << "yes" << '\n';
	}
	else {
		cout << "there are no strawberries" << '\n';
	}

	map["peaches"] = 12;
	cout << "Number of peaches: " << map["peaches"];
	cout << '\n';
}
