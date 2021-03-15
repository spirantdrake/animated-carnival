#pragma once

/*	Christopher Lyons
	Data Structures Section 05
	Assignment 5	*/

#include <cstdlib>
#include "node1.h"

using namespace std;
namespace main_savitch_5
{
	typedef double value_type;
	class set
	{
	private:
		size_t many_nodes;
		node* head_ptr;

	public:
		set()
		{
			head_ptr = NULL;
			many_nodes = 0;
		}
		set(const set& source)
		{
			head_ptr = NULL;
			many_nodes = 0;
			node* cursor = source.head_ptr;
			for (size_t i = 0; i < source.many_nodes; ++i)
			{
				insertion(cursor->data());
				cursor = cursor->link();
			}
			many_nodes = source.many_nodes;
		}
		~set()
		{

			list_clear(head_ptr);
			many_nodes = 0;
		}
		set set_union(const set& set1, const set& set2);
		set set_intersection(const set& set1, const set& set2);
		set set_complement(const set& set1, const set& set2);
		void insertion(const value_type& value);
		void deletion(const value_type& value);
		bool is_in_set(const value_type& value) const;
		void print() const;
		size_t size() const
		{
			return many_nodes;
		}
		void operator =(const set& source);
	};

}