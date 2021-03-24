#pragma once
#include <vector>

class Stack
{
	private:
	std::vector<int> v;
	int size;

	public:
	Stack();
	void push(int i);
	void pop();
	void top();
	bool isEmpty();
	void toString();

};

