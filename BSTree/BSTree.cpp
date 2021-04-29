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


void BSTree::insert_helper(Node *bst, Node *back, int value)
{

	if(bst == nullptr)
	{
		if(back->getData() < value)
		{
			back->setRight(new Node(value));
		}

		else
		{
			back->setLeft(new Node(value));
		}
	}

	else
	{
		if(value < bst->getData())
		{
			insert_helper(bst->getLeft(), bst, value);
		}

		else
		{
			insert_helper(bst->getRight(), bst, value);
		}
	}

}


void BSTree::insert_r(int value)
{
	insert_helper(root, nullptr, value);
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

void BSTree::delete_recur(int value)
{
	return delete_n(root, nullptr, value);
}

void BSTree::delete_n(Node *start, Node *back, int value)
{
	//base case
	if(start == nullptr)
	{
		return;
	}
	//check whether the node to be deleted is in the left or right subtree
	if(start->getData() < value)
	{
		delete_n(start->getRight(), start, value);
	}//the node to be deleted is in the left subtree
	else if(start->getData() > value)
	{
		delete_n(start->getLeft(), start, value);
	}//the node to be deleted is in the right subtree

	else
	{

	//1st case scenario: node to be deleted is the leaf; simply remove from the tree
		if((start->getLeft() == nullptr) && (start->getRight() == nullptr))
		{
			if(back->getRight() == start)
			{
				back->setRight(nullptr);
			}
			else if(back->getLeft() == start)
			{
				back->setLeft(nullptr);
			}
			delete start;
		}
	//2nd case scenario: node to be deleted has only one child
		else if(start->getLeft() != nullptr)
		{
			if(back->getLeft() == start)
			{
				back->setLeft(start->getLeft());
			}
			else
			{
				back->setRight(start->getLeft());
			}
			delete start;
		}

		else if(start->getRight() != nullptr)
		{
			if(back->getLeft() == start)
			{
				back->setLeft(start->getRight());
			}
			else
			{
				back->setRight(start->getRight());
			}
			delete start;
		}

	//3rd case scenario: node to be deleted has two kids (most com
	else
	{

		Node *rsparent = root;
		Node *rs = root->getRight();
		while(rs != nullptr && rs->getLeft() != nullptr)
		{
			rsparent = rs;
			rs = rs->getLeft();
		}
		if(rsparent != root)
		{
			rsparent->setLeft(rs->getRight());
		}
		else
		{
			rsparent->setRight(rs->getRight());
		}
		root->setData(rs->getData());
		//delete rs;

	}
   }
}

int BSTree::tsh(Node *root)
{
	if(root == nullptr)
	{
		return 0;
	}

	else
	{
		return tsh(root->getLeft()) + root->getData() + tsh(root->getRight());
	}
}

int BSTree::treesum()
{
	return tsh(root);
}

int BSTree::nodecount(Node *bst)
{
	int count = 1;
	if(bst == nullptr)
	{
		return 0;
	}
	count += nodecount(bst->getLeft()) + nodecount(bst->getRight());
	return count;
}

int BSTree::nc()
{
	return nodecount(root);
}

int BSTree::leavesum(Node *bst)
{
	if(bst == nullptr)
	{
		return 0;
	}
	if(bst->getLeft() == nullptr && bst->getRight() == nullptr)
	{
		return 1;
	}
	return leavesum(bst->getLeft()) + leavesum(bst->getRight());
}

int BSTree::ls()
{
	return leavesum(root);
}

int BSTree::nodesum(int l, int s, Node *bst)
{
	if(bst == nullptr)
	{
		return 0;
	}
	if(s==l)
	{
		return bst->getData();
	}
	return nodesum(l, s+1, bst->getLeft()) + nodesum(l, s+1, bst->getRight());
}

int BSTree::ns(int l)
{
	return nodesum(l, 0, root);
}

int BSTree::height(Node *bst)
{
	if(bst == nullptr)
	{
		return 0;
	}

	else if(height(bst->getLeft()) > height(bst->getRight()))
	{
		return height(bst->getLeft()) + 1;
	}
	return height(bst->getRight()) + 1;
}

int BSTree::h()
{
	return height(root);
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

