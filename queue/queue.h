#pragma once
#include <vector>

class Queue
{
	private:
	std::vector<int> v;
	int size;

	public:
	Queue();
	void enqueue(int i);
	void dequeue();
	bool isEmpty();
	void front();
	void toString();

};


