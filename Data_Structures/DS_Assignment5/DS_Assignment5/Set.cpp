/*	Christopher Lyons
	Data Structures Section 05
	Assignment 5	*/

#include "node1.h"
#include "set.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace main_savitch_5;

typedef double value_type;


set set::set_union(const set& s1, const set& s2)
{
	set s3;
	s3 = s1;
	node* cursor = s2.head_ptr;
	for (size_t i = 0; i < s2.many_nodes; ++i)
	{
		s3.insertion(cursor->data());
		cursor = cursor->link();
	}
	s3.many_nodes = list_length(s3.head_ptr);
	return s3;
}
set set::set_intersection(const set& s1, const set& s2)
{
	set s3;
	node* cursor = s1.head_ptr;
	for (size_t i = 0; i < s1.many_nodes; ++i)
	{
		if (list_search(s2.head_ptr, cursor->data()) != NULL)
		{
			s3.insertion(cursor->data());
		}
		cursor = cursor->link();
	}
	s3.many_nodes = list_length(s3.head_ptr);
	return s3;
}
set set::set_complement(const set& s1, const set& s2)
{
	set s3;
	node* cursor = s1.head_ptr;
	for (size_t i = 0; i < s1.many_nodes; ++i)
	{
		if (list_search(s2.head_ptr, cursor->data()) == NULL)
		{
			s3.insertion(cursor->data());
		}
		cursor = cursor->link();
	}
	s3.many_nodes = list_length(s3.head_ptr);
	return s3;
}
void set::print() const
{
	node* cursor = head_ptr;
	cout << "{";
	for (size_t i = 0; i < size() - 1; ++i)
	{
		cout << cursor->data() << ", ";
		cursor = cursor->link();
	}
	cout << cursor->data() << "}" << endl;
}
void set::deletion(const value_type& value)
{
	assert(size() != 0);
	node* precursor = head_ptr;
	node* cursor = precursor;
	if (cursor->data() == value)
	{
		list_head_remove(head_ptr);
		many_nodes--;
	}
	else
	{
		cursor = cursor->link();
		while (cursor != NULL)
		{
			if (cursor->data() == value)
			{
				list_remove(precursor);
				many_nodes--;
				return;
			}
			else
			{
				precursor = cursor;
				cursor = cursor->link();
			}
		}
	}
}
void set::insertion(const value_type& value)
{
	if (is_in_set(value))
	{
		return;
	}
	else
	{
		list_head_insert(head_ptr, value);
		many_nodes++;
	}
}
bool set::is_in_set(const value_type& value) const
{
	node* in_set = list_search(head_ptr, value);
	if (in_set == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void set::operator =(const set& source)
{
	if (this == &source)
	{
		return;
	}
	list_clear(head_ptr);
	many_nodes = 0;
	node* cursor = source.head_ptr;
	for (size_t i = 0; i < source.many_nodes; ++i)
	{
		insertion(cursor->data());
		cursor = cursor->link();
	}
	many_nodes = source.many_nodes;
}
