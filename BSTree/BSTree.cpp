#include <iostream>
#include "Node.h"
#include "BSTree.h"


BSTree::BSTree()
{
	root = nullptr;
}

void BSTree::insert(int d)
{

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

