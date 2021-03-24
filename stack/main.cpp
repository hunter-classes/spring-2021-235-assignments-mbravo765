#include <iostream>
#include "stack.h"

int main()
{
	using std::cout;
	Stack one;
	std::cout << "Push the following numbers: 2,4,6,8,10" << "\n";
	one.push(2);
	one.push(4);
	one.push(6);
	one.push(8);
	one.push(10);
	one.toString();

	std::cout << "Pop an element back" << "\n";
	one.pop();
	one.toString();

	std::cout << "Pop back two more elements" << "\n";
	one.pop();
	one.pop();
	one.toString();

	std::cout << "The top element of the stack container is: " << "\n";
	one.top();

	std::cout << "Is the string empty?" << "\n";
	std::cout << one.isEmpty() << "\n";

	std::cout << "Is the string empty after popping back two more elements?" << "\n";
	one.pop();
	one.pop();
	std::cout << one.isEmpty() << "\n";

}

