// DS_Assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*	Christopher Lyons
	Data Structures Section 05
	Assignment 7	*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string to_string(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}
void numbers(ostream& outs, const string& prefix, unsigned int levels)
{
	string s;
	if (levels == 0)
	{
		outs << prefix << endl;
	}
	else
	{
		for (char c = '1'; c <= '9'; c++)
		{
			s = prefix + c + '.';
			numbers(outs, s, levels - 1);
		}
	}
}
void pattern(ostream& outs, unsigned int n, unsigned int i)
{
	int k;
	if (n == 1)
	{
		for (k = 0; k < i; ++k)
		{
			outs << "  ";
		}
		for (k = 0; k < n; ++k)
		{
			outs << "* ";
		}
		outs << endl;
	}
	else
	{
		pattern(outs, (n / 2), i);

		for (k = 0; k < i; ++k)
		{
			outs << "  ";
		}
		for (k = 0; k < n; ++k)
		{
			outs << "* ";
		}
		outs << endl;
		pattern(outs, (n / 2), ((n / 2) + i));
	}
}

int main()
{
	int loop = 1;
	do
	{
		string prefix;
		cout << "ENTER PREFIX: ";
		cin >> prefix;

		size_t levels;
		cout << "ENTER AMOUNT OF LEVELS: ";
		cin >> levels;

		numbers(cout, prefix, levels);

		cout << "TRY AGAIN? (YES: 1 || NO: 0)" << endl;
		cin >> loop;
	} while (loop == 1);
	cout << endl;
	int maxStars;
	cout << "TESTING PATTERN FUNCTION..." << endl;
	cout << endl;
	cout << "ENTER MAXIMUM NUMBER OF STARS: ";
	cin >> maxStars;
	pattern(cout, maxStars, 0);
}
