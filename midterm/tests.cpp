#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "mergesort.h"

TEST_CASE("msort")
{
	//even case
	Node *n1 = new Node();
	Node *c = n1;
	Node *n2 = new Node("11");
	Node *n3 = new Node("-4");
	Node *n4 = new Node("66");
	Node *n5 = new Node("7");
	Node *n6 = new Node("15");
	Node *n7 = new Node("21");
	Node *n8 = new Node("19");

	c->setData("9");
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
	c->setNext(n7);
	c = c->getNext();
	c->setNext(n8);
	c = c->getNext();

	n1 = msort(n1);
	CHECK(toString(n1) == "-4-->7-->9-->11-->15-->19-->21-->66--> nullptr");

	//odd case
	Node *o = new Node();
	Node *odd = o;
	Node *o2 = new Node("57");
	Node *o3 = new Node("2");
	Node *o4 = new Node("-18");
	Node *o5 = new Node("37");
	odd->setData("16");
	odd->setNext(o2);
	odd = odd->getNext();
	odd->setNext(o3);
	odd = odd->getNext();
	odd->setNext(o4);
	odd = odd->getNext();
	odd->setNext(o5);
	odd = odd->getNext();

	o = msort(o);
	CHECK(toString(o) == "-18-->2-->16-->37-->57--> nullptr");

	Node *empty = new Node();
	CHECK(toString(empty) == "--> nullptr");

	//same
	Node *same = new Node();
	Node *s = same;
	Node *s2 = new Node("3");
	Node *s3 = new Node("3");
	s->setData("3");
	s->setNext(s2);
	s = s->getNext();
	s->setNext(s3);
	s= s->getNext();

	same = msort(same);
	CHECK(toString(same) == "3-->3-->3--> nullptr");

}


