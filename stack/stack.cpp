#include <iostream>
#include "stack.h"

Stack::Stack()
{
	size = 0;
}

void Stack::push(int i)
{
//push is used to push or insert an element at the top of the stack container.
		v.push_back(i);
		size++;
}

void Stack::pop()
{
//removes an item from the stack

	if(size > 0)
	{
		v.pop_back();
		size--;
	}

	else
	{
		std::cout << "Stack underflow" << "\n";
	}
}

void Stack::top()
{
//returns the top element of the stack
	if(size > 0)
	{
		int x = v[size-1];
		std::cout << x << "\n";
	}
	else
	{
		std::cout << "stack is empty" << "\n";
	}
}

bool Stack::isEmpty()
{
	if(size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Stack::toString()
{
	for(int i=0; i<size; i++)
	{
		std::cout << v.at(i) << " ";
	}
	std::cout << "\n";
}

