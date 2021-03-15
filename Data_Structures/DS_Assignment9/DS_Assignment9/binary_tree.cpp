#include "binary_tree.h"
#include "binary_tree_node.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void binary_tree::build_tree(binary_tree_node*& root, queue<char>& q)
{
	if (q.empty())
	{
		return;
	}
	else if (q.front() == '$')
	{
		q.pop();
		return;
	}
	else {
		if (root == NULL)
		{
			root = new binary_tree_node();
		}
		root->set_data(q.front());
		q.pop();
		build_tree(root->left(), q);
		build_tree(root->right(), q);
	}
}

void binary_tree::print_preorder(binary_tree_node*& root)
{
	if (root != NULL)
	{
		cout << root->data() << " ";
		print_preorder(root->left());
		print_preorder(root->right());
	}
}

void binary_tree::findMessage(char array[])
{
	binary_tree_node* cursor = root_pointer;
	binary_tree_node* precursor = cursor;
	for (int i = 0; i < 100; ++i)
	{
		if (cursor == NULL)
		{
			cout << precursor->data() << " ";
			cursor = root_pointer;
			precursor = cursor;
		}
		else if (array[i] == ' ' && array[i + 1] == ' ')
		{
			cout << cursor->data() << " ";
			cursor = root_pointer;
			precursor = cursor;
			++i;
		}
		else if (array[i] == ' ')
		{
			cout << cursor->data();
			cursor = root_pointer;
			precursor = cursor;
		}
		else if (array[i] == '/')
		{
			cout << cursor->data() << " ";
			break;
		}
		else if (array[i] == '-')
		{
			precursor = cursor;
			cursor = cursor->left();
		}
		else
		{
			precursor = cursor;
			cursor = cursor->right();
		}
	}
}

void binary_tree::findCode(char array[])
{
	binary_tree_node* cursor = root_pointer;
	for (int i = 0; i < 100; ++i)
	{
		if (array[i] == '/')
		{
			break;
		}
		else if (array[i] == ' ')
		{
			cout << " ";
		}
		else
		{
			char target = array[i];
			find_path(root_pointer, target);
			cout << " ";
		}
	}
}

bool binary_tree::path(binary_tree_node* root, stack<binary_tree_node*>& morse, char target)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->data() == target || path(root->left(), morse, target) || path(root->right(), morse, target))
	{
		morse.push(root);
		return true;
	}
	return false;
}

void binary_tree::find_path(binary_tree_node* root, char target)
{
	stack<binary_tree_node*> morse;
	binary_tree_node* cursor = root_pointer;
	path(root, morse, target);
	morse.pop();
	while (!morse.empty())
	{
		if (cursor->left() != NULL && morse.top()->data() == (cursor->left())->data())
		{
			cout << "-";
			cursor = cursor->left();
			morse.pop();
		}
		else
		{
			cout << ".";
			cursor = cursor->right();
			morse.pop();
		}
	}
}
