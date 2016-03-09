#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	//Testing Suite
	int* n = new int;
	const int keep = *n = 5;
	Stack<int> test;

	cout << "Initialize Test: ";
	if(test.Size() != 0)
		cout << "FAILED";
	else
		cout << "PASSED";
	cout << " |" << test.Size() << endl;

	cout << "Push Test(val:" << *n << "|[" << n <<"]):";
	test.Push(n);
	n = NULL;

	cout << "PASSED" << endl;

	cout << "Null Pointer Test: ";
	if(n == NULL)
		cout << "PASSED" << endl;
	else
		cout << "FAILED | (" << *n << "[" << n << "])" << endl;


	cout << "Size Test(1): ";
	if(test.Size() != 1)
		cout << "FAILED";
	else
		cout << "PASSED";
	cout << " |" << test.Size() << endl;

	cout << "Pop Test("<<keep<<"): ";
	n = test.Pop();
	if(n)
	{
		if(*n == keep)
			cout << "PASSED";
		else
			cout << "FAILED-invalid value";
	}
	else
		cout << "FAILED-null";

	cout << endl;

	cout << "Size Test(0): ";
	if(test.Size() != 0)
		cout << "FAILED";
	else
		cout << "PASSED";
	cout << " |" << test.Size() << endl;

	return 0;
}