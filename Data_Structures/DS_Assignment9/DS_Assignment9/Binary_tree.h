#pragma once

#include <cstdlib>
#include "binary_tree_node.h"
#include <stack>
#include <queue>

using namespace std;

class binary_tree
{

public:
	binary_tree()
	{
		root_pointer = new binary_tree_node();
		queue<char> q;
		char array[] =
		{
'&', 'T', 'M', 'O', '-', '0', '$', '$', '9', '$', '$', '.', '$', '8', '$', '$', 'G', 'Q', '$', '$', 'Z', '$', '7', '$', '$',
'N', 'K', 'Y', '$', '$', 'C', '$', '$', 'D', 'X', '$', '$', 'B', '$', '6', '$', '$', 'E', 'A', 'W', 'J', '1', '$', '$', '$', 'P', '$', '$',
'R', '$', 'L', '$', '$', 'I', 'U', '-', '2', '$', '$', '$', 'F', '$', '$', 'S', 'V', '3', '$', '$', '$', 'H', '4', '$', '$', '5', '*'
		};
		int i = 0;
		while (array[i] != '*')
		{
			q.push(array[i]);
			++i;
		}
		build_tree(root_pointer, q);
	}

	void build_tree(binary_tree_node*& root, queue<char>& q);
	void print_preorder(binary_tree_node*& root);
	void print()
	{
		print_preorder(root_pointer);
	}
	void findMessage(char array[]);
	void findCode(char array[]);
	bool path(binary_tree_node* root, stack<binary_tree_node*>& morse, char target);
	void find_path(binary_tree_node* root, char target);

private:
	binary_tree_node* root_pointer;
};
