// DS_Lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "priority_queue.h"

using namespace std;

int main(int argc, char** argv)
{
	priority_queue<int> t;

	cout << "Created priority queue" << endl;
	cout << "queue is has size: " << t.size() << endl;
	cout << "queue is empty: " << t.empty() << endl;

	t.push(5);
	cout << "the first element if it exists is " << t.top() << endl;

	cout << "queue is now size: " << t.size() << endl;
	cout << "queue is empty: " << t.empty() << endl;

	t.push(6);
	t.push(12);
	t.push(3);
	t.push(9);

	cout << "4 elements have been pushed onto the queue, size is now: " << t.size() << endl;

	cout << "12 should now be the largest element: " << t.top() << endl;
	t.pop();
	cout << "12 was removed and 9 should now be the largest element: " << t.top() << endl;

	return 0;
}