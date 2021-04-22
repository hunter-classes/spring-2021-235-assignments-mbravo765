#include <iostream>
#include "Node.h"
#include "BSTree.h"


BSTree::BSTree()
{
	root = nullptr;
}


int BSTree::search(int value)
{
	Node *bst = root;
	while(bst != nullptr)
	{
		if(bst->getData() == value)
		{
			return value;
		}
		else if(bst->getData() > value)
		{
			bst = bst->getLeft();
		}
		else
		{
			bst = bst->getRight();
		}
	}
	//t got to nullptr so the value isn't in the tree
	throw -1;

	return 0;
}


void BSTree::insert(int d)
{
	Node *n = new Node(d);
	if(root == nullptr)
	{
		root = n;
		return;
	}

	Node *t = root;
	Node *t2;

	while(t != nullptr)
	{
		t2 = t;
		if(t->getData() < d)
		{
			t = t->getRight();
		}

		else
		{
			t = t->getLeft();
		}
	}

	if(d < t2->getData())
	{
		t2->setLeft(n);
	}

	else
	{
		t2->setRight(n);
	}
}

//recursive


void BSTree::insert_helper(Node *bst, int value)
{

	Node *t;
	if(root == nullptr)
	{
		if(t->getData() < value)
		{
			t->setRight(new Node(value));
		}

		else
		{
			t->setLeft(new Node(value));
		}
	}

	else
	{
		if(value < bst->getData())
		{
			bst = bst->getLeft();
			insert_helper(bst, value);
		}

		else
		{
			bst = bst->getRight();
			insert_helper(bst, value);
		}
	}

}


void BSTree::insert_r(int value)
{
	insert_helper(root, value);
}


int BSTree::search_r(Node *bst, int value)
{

	if(root == nullptr)
	{
		return value;
	}

	if(bst->getData() == value)
	{
		return value;
	}

	else
	{
		if(bst->getData() > value)
		{
			return search_r(bst->getLeft(), value);
		}

		if(bst->getData() < value)
		{
			return search_r(bst->getRight(), value);
		}
	}
	return 0;
}


int BSTree::find_search(int value)
{
	return search_r(root, value);
}


std::string BSTree::get_debug_string_helper(Node *bst)
{
	if(bst == nullptr)
	{
		return "";
	}
	else
	{
		return get_debug_string_helper(bst->getLeft()) + " " + std::to_string(bst->getData()) + " " + get_debug_string_helper(bst->getRight());
	}
}


std::string BSTree::get_debug_string()
{
	return get_debug_string_helper(root);
}

void BSTree::setup()
{
	Node *n = new Node(10);
	root = n;
	n = new Node(20);
	root->setLeft(n);
	n = new Node(30);
	root->setRight(n);
	n = new Node(40);
	root->getLeft()->setLeft(n);
}

