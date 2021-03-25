#include <iostream>
#include <vector>
#include "queue.h"

int main()
{
	using std::cout;
	Queue q;
	cout << "Enqueue the following items to the queue: 3,6,9,12,15" << "\n";
	q.enqueue(3);
	q.enqueue(6);
	q.enqueue(9);
	q.enqueue(12);
	q.enqueue(15);
	q.toString();

	std::cout << "Dequeue an item from the queue" << "\n";
	q.dequeue();
	q.toString();

	std::cout << "Dequeue two more items" << "\n";
	q.dequeue();
	q.dequeue();
	q.toString();

	std::cout << "The front is: " << "\n";
	q.front();

	std::cout << "Is the queue empty?" << "\n";
	std::cout << q.isEmpty() << "\n";

	std::cout << "Is the queue empty after dequeuing two more items?" << "\n";
	q.dequeue();
	q.dequeue();
	std::cout << q.isEmpty() << "\n";

	return 0;
}
