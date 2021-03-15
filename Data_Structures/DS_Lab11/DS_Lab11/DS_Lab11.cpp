// DS_Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "bst.h"
#include "node3.h"
#include <list>
#include <iterator>

using namespace std;

template <class T>
void toLinkedList(binary_tree_node <T>* root, list <T>& l) {
	if (root == NULL)
		return;

	if (root != NULL) {
		toLinkedList(root->left(), l);
		l.push_back(root->data());
		toLinkedList(root->right(), l);
	}
}

template <class T>
void showList(list <T> g)
{
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}


int main(int argc, char** argv)
{
	binary_search_tree<int> t;
	t.insert(1);
	t.insert(9);
	t.insert(43);
	t.insert(2);
	t.insert(13);

	list <int> l;
	cout << "Results of printing the linked list that was converted from the binary tree: ";
	toLinkedList(t.get_root(), l);
	showList(l);



}
