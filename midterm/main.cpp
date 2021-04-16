#include <iostream>
#include "mergesort.h"
#include "Node.h"

int main()
{
	using std::cout;
	Node *n1 = new Node();
	Node *c = n1;
	Node *n2 = new Node("11");
	Node *n3 = new Node("77");
	Node *n4 = new Node("-15");
	Node *n5 = new Node("5");
	Node *n6 = new Node("21");
	c->setData("13");
	c->setNext(n2);
	c = c->getNext();
	c->setNext(n3);
	c = c->getNext();
	c->setNext(n4);
	c = c->getNext();
	c->setNext(n5);
	c = c->getNext();
	c->setNext(n6);
	c = c->getNext();

	cout << toString(n1) << "\n";
	cout << "length: " << length(n1) << "\n";
	cout << "middle: " << middle(n1)->getData() << "\n";

	n1 = msort(n1);
	cout << toString(n1) << "\n";

	return 0;
}
