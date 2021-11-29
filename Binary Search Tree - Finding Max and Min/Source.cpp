#include<iostream>

using namespace std;

class BstNode
{
public:
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};

int FindMin(BstNode* root) //moving as left as possible
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->leftChild != NULL)
	{
		root = root->leftChild;
	}
	return root->data;
}

int FindMax(BstNode* root) //moving as right as possible
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->rightChild != NULL)
	{
		root = root->rightChild;
	}
	return root->data;
}

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

void main()
{
	BstNode* root = NULL; // to store the address of root node
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 16);
	root = Insert(root, 12);
	root = Insert(root, 45);
	root = Insert(root, 52);
	root = Insert(root, 8);
	root = Insert(root, 32);
	cout << "The max data is: " << FindMax(root) << endl;
	cout << "The min data is: " << FindMin(root) << endl;
}
