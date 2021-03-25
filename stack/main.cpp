#include <iostream>
#include "stack.h"

int main()
{
	using std::cout;
	Stack re;
	std::cout << "Push the following numbers: 2,4,6,8,10" << "\n";
	re.push(2);
	re.push(4);
	re.push(6);
	re.push(8);
	re.push(10);
	re.toString();

	std::cout << "Pop an element back" << "\n";
	re.pop();
	re.toString();

	std::cout << "Pop back two more elements" << "\n";
	re.pop();
	re.pop();
	re.toString();

	std::cout << "The top element of the stack container is: " << "\n";
	re.top();//should be 8

	std::cout << "Is the string empty?" << "\n";
	std::cout << re.isEmpty() << "\n";

	std::cout << "Is the string empty after popping back two more elements?" << "\n";
	re.pop();
	re.pop();
	std::cout << re.isEmpty() << "\n";
return 0;
}

