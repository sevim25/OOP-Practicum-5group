
#include <iostream>
#include "Stack.hpp"

using std::cout;

int main()
{

	Stack<int> s;
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);

	cout << s;

	cout << "The top element is: " << s.top() <<'\n';

	s.pop();
	cout << s;

	if (s.empty()) {
		cout << "empty";
	}
	else {
		cout << "The stack is not empty";
	}
}

