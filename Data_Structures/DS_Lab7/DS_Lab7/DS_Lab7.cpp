// DS_Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Christopher Lyons
  Data Structures Lab Section 05*/

#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;
using namespace main_savitch_6B;

int main()
{
	bag <int> yes;

	yes.insert(4);
	yes.insert(2);
	yes.insert(12);
	yes.insert(56);
	yes.insert(6);
	yes.insert(0);

	cout << "first value range test" << endl;
	yes.print_value_range(4, 56);
	cout << "second value range test" << endl;
	yes.print_value_range(2, 78);
	cout << "third value range test" << endl;
	yes.print_value_range(2, 1);
	cout << "fourth value range test" << endl;
	yes.print_value_range(8, 5);

	cout << "List to have repetitions removed is 3,3,3,2,2,1,1" << endl;
	bag <int> yes2;
	yes2.insert(1);
	yes2.insert(1);
	yes2.insert(2);
	yes2.insert(2);
	yes2.insert(3);
	yes2.insert(3);
	yes2.insert(3);

	yes2.remove_repetitions();
	cout << "count of digit 3 after repetitions removed: ";
	cout << yes2.count(3) << " " << endl;
	cout << "count of digit 2 after repetitions removed: ";
	cout << yes2.count(2) << " " << endl;
	cout << "count of digit 1 after repetitions removed: ";
	cout << yes2.count(1) << " " << endl;


	return EXIT_SUCCESS;
}

