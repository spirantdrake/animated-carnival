//
//
//  test -= and - on bag
/*
    This program will print informative messages if something goes wrong
    in either creating and filling bags or in getting the difference
    between bags.

    If all goes well, only the final message prints.

*/

#include "check_lists.h"
#include "bag3.h"
#include <iostream>

using namespace std;
using namespace main_savitch_5;

void list_print(node* head_ptr) 
{
	cout << "{";
	node* i = head_ptr;
	for (i = head_ptr; i->link() != NULL; i = i->link())
	{
		cout << i->data() << ", ";
	}
	cout << i->data();
	cout << "}" << endl;
}


int main() {
    int size = 5;
    // how many of each value to put in each bag
    // one 0 will be put in b1
    // two 1's will be put in b1
    // five 0's will be in b2 ...
    int num1[] = { 1, 2, 3, 4, 5 };
    int num2[] = { 5, 4, 3, 2, 1 };
    bag b1;
    bag b2;
    // insert data into bags
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < num1[i]; j++) {
            b1.insert(i);
        }
        for (int j = 0; j < num2[i]; j++) {
            b2.insert(i);
        }
    }
    for (int i = 0; i < size; i++) {
        if (num1[i] != b1.count(i)) {
            cout << "value  " << i << " has bad count in b1: "
                << b1.count(i) << " rather than " << num1[i] << endl;
        }
        if (num2[i] != b2.count(i)) {
            cout << "value  " << i << " has bad count in b2: "
                << b2.count(i) << " rather than " << num2[i] << endl;
        }
    }
    bag b3 = b1 - b2;
    for (int i = 0; i < size; i++) {
        int d = num1[i] - num2[i];
        d = (d >= 0) ? d : 0;
        if (b3.count(i) != d) {
            cout << "value  " << i << " has bad count in b3: "
                << b3.count(i) << " rather than " << d << endl;
        }
    }

    b1 -= b1;
    for (int i = 0; i < size; i++) {
        if (0 != b1.count(i)) {
            cout << "value  " << i << " has bad count in b1: "
                << b1.count(i) << " rather than " << 0 << endl;
        }
    }


    cout << "no news is good news!" << endl;

	//Int main part two addition
	node* head = NULL;
	list_head_insert(head, 12.9);
	list_insert(head, 23.5);
	list_insert(head, 45.6);
	list_insert(head, 67.7);
	list_insert(head, 89.8);
	list_print(head);
	check_list1(head);

	node* head2 = NULL;
	node* tail2 = NULL;

	list_head_insert(head2, 23.5);
	tail2 = head2;
	list_insert(tail2, 45.6);
	tail2 = tail2->link();
	list_insert(tail2, 67.7);
	tail2 = tail2->link();
	list_insert(tail2, -123.5);
	tail2 = tail2->link();
	list_insert(tail2, 89.8);
	tail2 = tail2->link();
	list_insert(tail2, 12.9);
	tail2 = tail2->link();
	list_print(head2);
	check_list2(head2);

	node* head3 = NULL;
	node* tail3 = NULL;

	list_copy(head, head3, tail3);
	list_print(head3);
	check_list1(head3);
	cout << "At tail: " << tail3->data() << endl;

	list_head_remove(head2);
	list_print(head2);
	check_list2B(head2);

	list_remove(list_locate(head2, 2));
	list_print(head2);
	check_list2C(head2);

}
