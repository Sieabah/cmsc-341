#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{

}

bool BinarySearchTree::Insert(int item)
{
	Node* tmp = new Node();
	tmp->data = item;
	tmp->left = tmp->right = NULL;

	return InsertRecursive(root, tmp);
}

bool BinarySearchTree::InsertRecursive(Node *&root, Node* &item)
{
	if ( root == NULL)
	{
		cout << "Insert("<<item->data<<") on root" << endl;
		root = item;
		return true;
	}
	else if (item->data < root->data)
	{
		cout << "Insert("<<item->data<<") left of "<<root->data<<" branch" << endl;
		return InsertRecursive(root->left, item);
	}
	else if (item->data > root->data)
	{
		cout << "Insert("<<item->data<<") right of "<<root->data<<" branch" << endl;
		return InsertRecursive(root->right, item);
	}
	else
	{
		cout << "No place to put this data." << endl;
		return false;
	}
}

void BinarySearchTree::Print()
{
	Print(root);
}

void BinarySearchTree::Print(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	Print(root->left);
	cout << root->data << " ";
	Print(root->right);
}