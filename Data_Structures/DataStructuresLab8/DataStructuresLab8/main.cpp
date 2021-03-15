#include <iostream>
#include <cstdlib>
#include "stack_pair.h"

using namespace std;


void test1()
{
	stack_pair<int> t;
	t.push_a(1);
	t.push_a(2);
	t.push_a(3);
	t.push_a(4);
	t.push_a(5);

	t.push_b(10);
	t.push_b(11);
	t.push_b(12);
	t.push_b(13);
	t.push_b(14);

	int value = 0;
	
	int i = 5;
	while (!t.is_empty_a())
	{
		if (t.pop_a() == i)
		{
			value++;
			i--;
		}
		else
			i--;
	}

	i = 14;
	while (!t.is_empty_b())
	{
		if (t.pop_b() == i)
		{
			value++;
			i--;
		}
		else
			i--;
	}

	if (value == 10)
		cout << value << " out of 10 points, test 1 passed." << endl;
	else
		cout << value << " out of 10 points, test 1 failed." << endl;
}

void test2()
{
	stack_pair<int> t;
	t.push_a(1);
	t.push_a(2);
	t.push_a(3);
	t.push_a(4);
	t.push_a(5);
	t.push_a(6);
	t.push_a(7);
	t.push_a(8);
	t.push_a(9);
	t.push_a(10);

	t.push_b(11);
	t.push_b(12);
	t.push_b(13);
	t.push_b(14);
	t.push_b(15);	
	t.push_b(16);
	t.push_b(17);
	t.push_b(18);
	t.push_b(19);
	t.push_b(20);

	if (t.is_full_a() == false)
	{
		cout << "Stack a is not full" << endl;
		return;
	}

	if (t.is_full_b() == false)
	{
		cout << "Stack b is not full" << endl;
		return;
	}

	int value = 0;

	int i = 10;
	while (!t.is_empty_a())
	{
		if (t.pop_a() == i)
		{
			value++;
			i--;
		}
		else
			i--;
	}

	i = 20;
	while (!t.is_empty_b())
	{
		if (t.pop_b() == i)
		{
			value++;
			i--;
		}
		else
			i--;
	}

	if (value == 20)
		cout << value << " out of 20 points, test 2 passed." << endl;
	else
		cout << value << " out of 20 points, test 2 failed." << endl;
}

void test3()
{
	stack_pair<int> t;
	t.push_a(1);
	t.push_a(2);
	t.push_a(3);
	t.push_a(4);
	t.push_a(5);
	t.push_a(6);
	t.push_a(7);
	t.push_a(8);
	t.push_a(9);
	t.push_a(10);

	t.push_b(11);
	t.push_b(12);
	t.push_b(13);
	t.push_b(14);
	t.push_b(15);
	t.push_b(16);
	t.push_b(17);
	t.push_b(18);
	t.push_b(19);
	t.push_b(20);

	if (t.is_full_a() == false)
	{
		cout << "Stack a is not full" << endl;
		return;
	}

	if (t.is_full_b() == false)
	{
		cout << "Stack b is not full" << endl;
		return;
	}

	t.push_a(50);
}

void test4()
{
	stack_pair<int> t;
	t.pop_a();
}

int main()
{
	test1();
	test2();
	test3();
	//test4();

}