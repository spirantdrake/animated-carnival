// DS_Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*  Christopher Lyons
	Data Structures Section 05
	Assignment 4	*/

#include <iostream>
#include <cassert>
#include "node1.h"
#include "list.h"

typedef node::value_type  value_type;
typedef node* list;
using namespace std;

list tail(list listA)
{
	if (list_is_empty(listA))
	{
		return listA;
	}
	list pntr = listA;
	pntr = pntr->link();
	listA = pntr;
	return listA;
}

list append(const list listA1, const list listA2)
{
	if (list_is_empty(listA1))
	{
		return listA2;
	}
	else
	{
		return cons(head(listA1), append(tail(listA1), listA2));
	}
}

bool list_is_empty(list listA)
{
	return (listA == NULL);
}

value_type head(list listA)
{
	assert(!list_is_empty(listA));
	return listA->data();
}

list cons(value_type value, const list listA)
{
	list node_new = new node;
	node_new->set_data(value);
	node_new->set_link(listA);
	return node_new;
}

list append(const list listA, value_type value)
{
	if (list_is_empty(listA))
	{
		return cons(value, NULL);
	}
	else
	{
		return cons(head(listA), append(tail(listA), value));
	}
}

list remove_all_of(const list listA, value_type value)
{
	if (list_is_empty(listA))
	{
		return listA;
	}
	else if (head(listA) == value)
	{
		return remove_all_of(tail(listA), value);
	}
	else
	{
		return cons(head(listA), remove_all_of(tail(listA), value));
	}
}

list remove_last(const list listA)
{
	assert(!list_is_empty(listA));
	if (list_is_empty(tail(listA)))
	{
		return tail(listA);
	}
	else
	{
		return cons(head(listA), remove_last(tail(listA)));
	}
}

bool equals(const list list1, const list list2)
{
	if (list_is_empty(list1))
	{
		return list_is_empty(list2);
	}
	else if (list_is_empty(list2))
	{
		return false;
	}
	else if (head(list1) != head(list2))
	{
		return false;
	}
	else
	{
		return equals(tail(list1), tail(list2));
	}
}

value_type last(const list listA)
{
	assert(!list_is_empty(listA));
	if (list_is_empty(tail(listA)))
	{
		return head(listA);
	}
	else
	{
		return last(tail(listA));
	}
}
