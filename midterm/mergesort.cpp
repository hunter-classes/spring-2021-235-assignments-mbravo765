//merge sort
#include <iostream>
#include "Node.h"
#include "mergesort.h"
#include <string>

/*
Write a function Node *msort(Node *head) That performs a mergesort on the input list 
represented by the parameter head. 
You may use the length and middle routines defined above and can assume that they 
above work as specified regardless of what you wrote.
Assume the existence of a function Node *merge(Node *a, Node *b) that accepts 
two node pointers, each pointing to a sorted linked list and returns a node to a 
new sorted linked list that combines all the elements of a and b as per the 
mergesort algorithm.

Note: In addition to knowing the mergesort algorithm and using the above routines, 
you will have to split the list sent in as a parameter. 
For full credit, do this without creating additional nodes.
*/


int length(Node *l)
{
	int count = 0;
	while(l != nullptr)
	{
		count++;
		l = l->getNext();
	}
	return count;
}

Node *middle(Node *head)
{
	int mid = length(head)/2;
	Node *c = head;
	while(mid > 0)
	{
		c = c->getNext();
		mid--;
	}
	return c;
}

Node *merge(Node *a, Node *b)
{
	Node *merged = new Node();
	Node *c = merged;
	if(a == nullptr && b == nullptr)//if both nodes are empty
	{
		return nullptr;
	}

	while(a != nullptr && b != nullptr)//while they're not empty
	{
		merged->setNext(new Node());
		merged = merged->getNext();


	//the stoi function takes a string as an argument and returns its value.
		using std::stoi;
	//check if the current element in a is less than the current element in b
		if(stoi(a->getData()) < stoi(b->getData()))
		{
			merged->setData(a->getData());
			a = a->getNext();//move on to the next element
		}
		else
		{
			merged->setData(b->getData());
			b = b->getNext();
		}
	}
	while(a != nullptr)
	{
		merged->setNext(new Node());
		merged = merged->getNext();
		merged->setData(a->getData());
		a = a->getNext();
	}

	while(b != nullptr)
	{
		merged->setNext(new Node());
		merged = merged->getNext();
		merged->setData(b->getData());
		b = b->getNext();
	}

	Node *head = c->getNext();
	return head;
}


Node *msort(Node *head)
{

	//this is the base case, if lsit is empty or just 1
	if(length(head) < 2)
	{
		return head;
	}

	Node *front = head;
	Node *back = middle(head);
	Node *f = head;
	Node *b = back;

	while(f->getNext() != b)
	{
		f = f->getNext();
	}
	f->setNext(nullptr);

	front = msort(front);
	back = msort(back);

	return merge(front, back);

}


std::string toString(Node *head)//will be used for testing msort
{
	std::string s = "";
	while(head != nullptr)
	{
		s = s+head->getData() + "-->";
		head = head->getNext();
	}
	s = s +" nullptr";

	return s;
}

