#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};
	BinarySearchTree();
	virtual ~BinarySearchTree();
	bool Insert(int item);
	void Print();
private:
	Node* root;
	bool InsertRecursive(Node* &root, Node* &item);
	void Print(Node* root);
};

#endif