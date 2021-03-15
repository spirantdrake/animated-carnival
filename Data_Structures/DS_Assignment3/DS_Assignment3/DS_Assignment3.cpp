// DS_Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* Christopher Lyons
   Data Structures Section 05
   Assignment 3 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "sequence1.h"

using namespace std;
using namespace main_kretlow_3;

sequence::sequence()
{
    used = 0;
    current_index = 0;
}

void sequence::start()
{
    current_index = 0;
}

void sequence::advance()
{
    if (is_item())
    {
        current_index++;
    }
}

bool sequence::is_item() const
{
    if (current_index < used)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);
    if (used == 0)
    {
        data[0] = entry;
        used++;
        current_index = 0;
    }
    else
    {
        for (size_type i = used; i > current_index; i--)
        {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }
}

void sequence::attach(const value_type& entry)
{
    assert(size() < CAPACITY);
    if (used == 0)
    {
        data[current_index] = entry;
        used++;
    }
    else
    {
        for (size_type i = used; i > current_index; i--)
        {
            data[i + 1] = data[i];
        }
        data[current_index + 1] = entry;
        current_index++;
        used++;
    }
}

sequence::size_type sequence::size() const
{
    return used;
}

void sequence::remove_current()
{
    assert(is_item());
    for (size_type i = current_index; i < (used - 1); i++)
    {
        data[i] = data[i + 1];
    }
    used--;
}

sequence::value_type sequence::current() const
{
    assert(is_item());
    return data[current_index];
}