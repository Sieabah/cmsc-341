/*****************************************
** File:    InClass.cpp
** Project: CMSC 341 In Class Assignment, Fall 2014
** Author:  Christopher Sidell
** Date:    9/9/2014
** Section: 01
** E-mail:  csidell1@umbc.edu
**
	MyList driver 
**
**
***********************************************/

#include "MyList.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//For randomized values
	srand (time(NULL));
	MyList<int> d;
	cout << "Created list d" << endl;

	//Add items
	cout << "Add two random numbers" << endl;
	d.AddItem(rand()%10);
	d.AddItem(rand()%10);

	//Print lists
	cout << "List d: ";
	d.PrintList();

	//Remove item
	cout << endl;
	cout << "Remove last element." << endl;
	d.RemoveItem();

	//Print list
	cout << "List d: ";
	d.PrintList();

	cout << endl;
	return 0;
}