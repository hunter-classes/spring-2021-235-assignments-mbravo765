#include <iostream>
#include "Node.h"
#include "BSTree.h"


int main()
{
	using std::cout;
	Node *n = new Node(10);//level 0
	cout << "  " << n->getData() << "\n";
	Node *n2 = new Node(20);//level 1
	n->setLeft(n2);
	n2 = new Node(50);//level 1
	n->setRight(n2);

	cout << n->getLeft()->getData() << "     ";
	cout << n->getRight()->getData() << "\n";

	Node *n3 = new Node(30);//level 2
	n2->setLeft(n3);
	n3 = new Node(60);//level 2
	n2->setRight(n3);

	cout << n2->getLeft()->getData() << "   ";
	cout << n2->getRight()->getData() << "   ";
	n3 = new Node(70);
	n2->setRight(n3);
	cout << n2->getRight()->getData() << "\n";

	Node *n4 = new Node(40);//level 3
	n3->setLeft(n4);
	cout << n3->getLeft()->getData() << "\n";

	cout << "BSTree " << "\n";

	BSTree *t = new BSTree();
	t->setup();
	cout << t->get_debug_string() << "\n";

	int v = 13;
	try
	{
		int x = t->search(v);
		cout << x << "\n";
	}
	catch(int e)
	{
		cout << v << " not found\n";
	}
	cout << "insert 22" << "\n";
	t->insert(22);
	cout << t->get_debug_string() << "\n";
	cout << "insert 3" << "\n";
	t->insert(3);
	cout << t->get_debug_string() << "\n";


	cout << "Recursive search, search for 22" << "\n";
	cout << t->find_search(22) << "\n";

	cout << "Recursive insert, insert 37" << "\n";
	t->insert_r(37);
	cout << t->get_debug_string() << "\n";

	cout << "Delete 37" << "\n";
	t->delete_recur(37);
	cout << t->get_debug_string() << "\n";

	cout << "Delete 22" << "\n";
	t->delete_recur(22);
	cout << t->get_debug_string() << "\n";

	cout << "insert 12" << "\n";
	t->insert_r(12);
	cout << t->get_debug_string() << "\n";

	cout << "insert 15" << "\n";
	t->insert_r(15);
	cout << t->get_debug_string() << "\n";

	cout << "Delete 12" << "\n";
	t->delete_recur(12);
	cout << t->get_debug_string() << "\n";

	cout << "delete 30" << "\n";
	t->delete_recur(30);
	cout << t->get_debug_string() << "\n";

	cout << t->treesum() << "\n";
	cout << t->nc() << "\n";
	cout << t->ls() << "\n";
	cout << t->ns(1) << "\n";
	cout << t->h() << "\n";
return 0;
}

