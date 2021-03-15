#pragma once

#include <cstdlib>

using namespace std;

class binary_tree_node
{
public:
	binary_tree_node(const char init_code = '&', binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
	{
		code = init_code;
		left_field = init_left;
		right_field = init_right;
	}

	char data()
	{
		return code;
	}

	binary_tree_node*& left()
	{
		return left_field;
	}

	binary_tree_node*& right()
	{
		return right_field;
	}

	void set_data(const char& new_code)
	{
		code = new_code;
	}

	void set_left(binary_tree_node* new_left)
	{
		left_field = new_left;
	}

	void set_right(binary_tree_node* new_right)
	{
		right_field = new_right;
	}

	bool is_leaf() const
	{
		return ((left_field == NULL) && (right_field == NULL));
	}

private:
	binary_tree_node* left_field;
	binary_tree_node* right_field;
	char code;
};
