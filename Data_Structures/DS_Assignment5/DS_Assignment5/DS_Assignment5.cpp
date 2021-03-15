// DS_Assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*	Christopher Lyons
	Data Structures Section 05
	Assignment 5	*/

#include <cstdlib>
#include <iostream>
#include "set.h"

using namespace std;
using namespace main_savitch_5;

int main()
{
	set s1;
	cout << "Testing multiple same insertions result in size 1: ";
	s1.insertion(8);
	s1.insertion(8);
	s1.insertion(8);
	s1.insertion(8);
	s1.print();
	cout << "\nSIZE FUNCTION TEST:";
	if (s1.size() == 1)
	{
		cout << "Successful..." << endl;
	}
	else
	{
		cout << "\nSize Function Test: FAIL\nActual Size: " << s1.size();
	}
	cout << endl;
	cout << "DELETION FUNCTION TEST:" << endl;
	cout << endl;
	s1.insertion(1);
	s1.insertion(2);
	s1.insertion(3);
	s1.insertion(4);
	cout << "Values inserted: ";
	s1.print();
	cout << "Checking Size: ";
	if (s1.size() == 5)
	{
		cout << "Successful..." << endl;
	}
	else
	{
		cout << "FAIL\nRequired Size:5\nActual Size: " << s1.size() << endl;
	}
	cout << "Deleting Numbers..." << endl;
	s1.deletion(2);
	s1.deletion(3);
	cout << "Altered Set:";
	s1.print();
	cout << "Testing the size() function:" << endl;
	if (s1.size() == 3)
	{
		cout << "Successful..." << endl;
	}
	else
	{
		cout << "FAIL\nRequired Size:3\nActual Size: " << s1.size() << endl;
	}
	cout << "POPULATING SETS..." << endl;
	s1.insertion(7);
	s1.insertion(4);
	s1.insertion(6);
	set s2;
	s2.insertion(3);
	s2.insertion(6);
	s2.insertion(9);
	cout << endl;
	cout << "SETS:" << endl;
	cout << "Set 1: ";
	s1.print();
	cout << "Set 2: ";
	s2.print();
	cout << endl;
	cout << "UNION FUNCTION TEST:" << endl;
	cout << endl;
	set s3 = s1.set_union(s1, s2);
	cout << "Set 3:";
	s3.print();
	cout << "Set 3 Size: " << s3.size() << endl;
	cout << endl;
	cout << "INTERSECTION FUNCTION TEST:" << endl;
	cout << endl;
	set s4 = s1.set_intersection(s1, s2);
	cout << "Set 4: ";
	s4.print();
	cout << "Set 4 Size: " << s4.size() << endl;
	cout << endl;
	cout << "COMPLEMENT FUNCTION TEST:" << endl;
	cout << endl;
	set s5 = s1.set_complement(s1, s2);
	s5.print();
	cout << "Set 5 Size: " << s5.size() << endl;
	cout << "EQUALS FUNCTION TEST" << endl;
	cout << "CREATING EMPTY SET..." << endl;
	set empty;
	cout << "CLONING FIRST SET TO EMPTY SET..." << endl;
	empty = s1;
	cout << "Empty Set: ";
	empty.print();
	cout << "Set 1: ";
	s1.print();
	cout << endl;
	cout << "COPY CONSTRUCTOR TEST:" << endl;
	cout << endl;
	cout << "CLONING FIRST SET TO SET 6..." << endl;
	set s6(s1);
	cout << "Set 6: ";
	s6.print();
	cout << "Set 1: ";
	s1.print();
	cout << endl;
	cout << "ASSIGNMENT FUNCTION TEST:" << endl;
	cout << endl;
	cout << "Set 2: ";
	s2.print();
	s2 = s1;
	cout << "Set 2(1): ";
	s2.print();
	cout << "Set 1: ";
	s1.print();
	cout << endl;

	cout << "MISC FUNCTION TEST:" << endl;
	cout << endl;
	if (s1.is_in_set(4) && !s1.is_in_set(16))
	{
		cout << "FUNCTION 'is_in_set' PASSED" << endl;
	}
	else
	{
		cout << "FUNCTION 'is_in_set' FAILED" << endl;
	}
	if (s2.size() != 5)
	{
		cout << "FUNCTION 'size' FAILED" << endl;
	}
	else
	{
		cout << "FUNCTION 'size' PASSED" << endl;
	}

}
