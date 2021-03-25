#include <iostream>
#include "queue.h"
#include <vector>

Queue::Queue()
{
	size = 0;
}

void Queue::enqueue(int i)
{
	v.push_back(i);
	size++;//must increase size or risk error
}

void Queue::dequeue()
{
	if(size > 0)
	{
		v.erase(v.begin());
		size--;
	}
	else
	{
		std::cout << "size is invalid" << "\n";
	}
}

void Queue::front()
{
	if(size > 0)
	{
		int x = v[0];
		std::cout << x << "\n";
	}
	else
	{
		std::cout << "queue is empty" << "\n";//error message
	}
}

bool Queue::isEmpty()
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

void Queue::toString()
{
	for(int i=0; i<size; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}


