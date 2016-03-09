#include "BinarySearchTree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(NULL);

	BinarySearchTree j;
	for (int i = 1; i < 100; ++i)
	{
		int val = rand()%(i*i);
		std::cout << "Inserting: " << val << std::endl;
		j.Insert(val);
	}

	std::cout << "Print the tree" << std::endl;
	j.Print();
	std::cout << std::endl;
	return 0;
}