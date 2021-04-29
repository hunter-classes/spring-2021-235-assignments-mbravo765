#pragma once
#include <stdio.h>

class BSTree
{
	private:
		Node *root;
	public:
		BSTree();
		std::string get_debug_string_helper(Node *bst);
		std::string get_debug_string();
		int search(int value);
		int search_r(Node *bst, int value);
		int find_search(int value);
		void insert(int d);
		void insert_helper(Node *bst, Node *back, int value);
		void insert_r(int value);
		void delete_n(Node *start, Node *back, int value);
		void delete_recur(int value);
		int tsh(Node *root);
		int treesum();
		int nodecount(Node *bst);
		int nc();
		int leavesum(Node *bst);
		int ls();
		int nodesum(int l, int s, Node *bst);
		int ns(int l);
		int height(Node *bst);
		int h();
		void setup();

};



