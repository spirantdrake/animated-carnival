#pragma once

#include <cstdlib>
#include <cassert>

template <class T>

class stack_pair
{

public:
	typedef std::size_t size_type;
	static const size_type CAPACITY = 20;

	stack_pair();

	T pop_a();
	T pop_b();

	void push_a(T item);
	void push_b(T item);

	size_type size_a();
	size_type size_b();

	bool is_empty_a() const;
	bool is_empty_b() const;

	bool is_full_a() const;
	bool is_full_b() const;

private:
	T dataArray[CAPACITY];

	size_type top_a;
	size_type top_b;
};

#include "stack_pair.template"