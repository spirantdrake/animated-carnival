// DS_Assignment9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*	Christopher Lyons
	Data Structures Section 05
	Assignment 9	*/

#include "binary_tree.h"
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	binary_tree input;
	int active = 1;
	while (active == 1)
	{
		cout << "SELECT OPTIONS FROM BELOW: " << endl;
		int choice;
		cout << "1. MORSE CODE TO LETTERS." << endl << "2. LETTERS TO MORSE CODE." << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "TYPE MORSE CODE STATEMENT WITH ONE SPACE BETWEEN LETTERS AND TWO SPACES BETWEEN WORDS: " << endl;
			char array[100];
			cin.ignore();
			cin.clear();
			cin.sync();
			cin.getline(array, 100);
			for (int i = 0; i < 100; ++i)
			{
				if (array[i] != ' ' && array[i] != '.' && array[i] != '-')
				{
					array[i] = '/';
				}
			}
			input.findMessage(array);
			cout << endl;
		}
		else
		{
			cout << "TYPE SENTENCE USING ALL CAPITALS WITH A PERIOD AT THE END (REQUIRED):" << endl;
			char array[100];
			cin.ignore();
			cin.clear();
			cin.sync();
			cin.getline(array, 100);
			for (int i = 0; i < 100; ++i)
			{
				if (array[i] == '.')
				{
					array[i] = '/';
				}
			}
			input.findCode(array);
			cout << endl;
		}
		cout << "RUN AGAIN?\n1: YES\n2: NO" << endl;
		cin >> active;
	}
}
