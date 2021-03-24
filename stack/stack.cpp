#include <iostream>
#include "stack.h"
#include <vector>


Stack::Stack()
{
	size = 0;
}

void Stack::push(int i)
{
//push is used to push or insert an element at the top of the stack container.
		v.insert(v.begin(), i);
		size++;
}

bool Stack::isEmpty()
{
//returns truee if stack is empty, else false
	if(size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
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
	if(size < 0)
	{
		std::cout << "Stack is empty";
	}
	else
	{
		int x = v[0];
		std::cout << x << "\n";
	}
}

void Stack::toString()
{
	for(int i=0; i<size; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

