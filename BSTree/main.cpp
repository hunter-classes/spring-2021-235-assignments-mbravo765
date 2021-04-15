#include <iostream>
#include "Node.h"

int main()
{
	using std::cout;
	Node *n = new Node(10);//level 0
	cout << n->getData() << "\n";
	Node *n2 = new Node(20);//level 1
	n->setLeft(n2);
	n2 = new Node(50);//level 1
	n->setRight(n2);

	cout << n->getLeft()->getData() << "\n";
	cout << n->getRight()->getData() << "\n";

	Node *n3 = new Node(30);//level 2
	n2->setLeft(n3);
	n3 = new Node(60);//level 2
	n2->setRight(n3);

	cout << n2->getLeft()->getData() << "\n";
	cout << n2->getRight()->getData() << "\n";
	n3 = new Node(70);
	n2->setRight(n3);
	cout << n2->getRight()->getData() << "\n";

	Node *n4 = new Node(40);//level 4
	n3->setLeft(n4);
	cout << n3->getLeft()->getData() << "\n";


	return 0;
}
