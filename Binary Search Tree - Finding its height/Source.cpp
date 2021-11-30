#include<iostream>

using namespace std;

class BstNode
{
public:
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};

BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->leftChild = newNode->rightChild = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->leftChild = Insert(root->leftChild, data); //recursion
	}
	else
		root->rightChild = Insert(root->rightChild, data); //recursion
	return root;
}

int FindHeight(BstNode* root)
{
	int lheight, rheight;
	if (root == NULL)
		return 0;
	else
	{
		lheight = FindHeight(root->leftChild);
		rheight = FindHeight(root->rightChild);
	}
	return max(lheight, rheight) + 1;
}

void main()
{
	BstNode* root = NULL; // to store the address of root node
	root = Insert(root, 10);
	root = Insert(root, 8);
	root = Insert(root, 11);
	root = Insert(root, 14);
	root = Insert(root, 13);
	root = Insert(root, 16);
	root = Insert(root, 2);
	root = Insert(root, 1);
	root = Insert(root, 6);
	root = Insert(root, 4);
	root = Insert(root, 3);
	root = Insert(root, 5);
	cout << "The height of the tree is: " << FindHeight(root) << endl;
}