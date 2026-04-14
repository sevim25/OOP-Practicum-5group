#include "Queue.hpp"
#include <iostream>

using std::cout;

int main()
{
	Queue<int> q;
	q.push(2);
	q.push(5);
	q.push(3);
	q.push(9);

	cout << "Queue: ";
	for (size_t i = 0; i < q.size(); i++)
	{
		cout << q[i] << " ";
	}

	cout << '\n';

	q.pop();
	cout << "Queue after pop(): ";
	for (size_t i = 0; i < q.size(); i++)
	{
		cout << q[i] << " ";
	}

	cout << '\n';

	cout << "Front: " << q.front() <<'\n';
	cout << "Back: " << q.back() << '\n';

	cout << "size: " << q.size();
}

