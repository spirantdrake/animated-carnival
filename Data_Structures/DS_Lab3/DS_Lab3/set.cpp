#include "set.h"
#include <iostream>

using namespace std;

set::set(size_type r)
{
	data = new value_type[r];
	used = 0;
	capacity = r;
}
set::set(const set& s)
{
	this->capacity = s.capacity;
	this->used = s.used;
	this->data = s.data;
}
bool set::erase(const value_type& target)
{
	int count = 0;
	for (int i = 0; i < used; i++)
	{
		if (data[i] == target)
		{
			for (int j = i; j < (used - 1); j++)
			{
				data[j] = data[j + 1];
			}
			count++;
			return true;
		}
	}
	return false;
}
bool set::insert(const value_type& entry)
{
	if (used >= capacity)
	{
		size_type newSize = capacity * 1.5;
		reserve(newSize);
		capacity = newSize;
	}
	if (!contains(entry))
	{
		data[used] = entry;
		used++;
		return true;
	}
	return false;
}
void set::operator = (const set& s)
{
	// Check for self assignment
	if (this != &s)
	{
		this->used = s.used;
		this->data = s.data;
	}
}

bool set::contains(const value_type& target) const
{
	for (int i = 0; i < used; i++)
		if (data[i] == target)
			return true;
	return false;
}
void set::operator+=(const set& addend)
{
	for (int i = 0; i < addend.used; i++)
	{
		if (!contains(addend.data[i]))
		{
			if (used >= capacity)
			{
				size_type newSize = capacity * 1.5;
				reserve(newSize);
				capacity = newSize;
			}
			data[used] = addend.data[i];
			used++;
		}
	}
}
set::size_type set::size() const
{
	return used;
}
std::ostream& operator<<(std::ostream& output, const set& s)
{
	for (int i = 0; i < s.used - 1; i++)
		output << s.data[i] << ",";
	output << s.data[s.used - 1];
	return output;
}
void set::reserve(size_type new_capacity)
{
	if (capacity <= new_capacity)
	{
		value_type* temp = new value_type[new_capacity];
		for (int i = 0; i < used; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}
}
set::~set()
{

}
