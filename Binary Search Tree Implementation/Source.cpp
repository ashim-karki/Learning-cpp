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

bool Search(BstNode* root, int data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->leftChild, data);
	else
		return Search(root->rightChild, data);
}

void main()
{
	int num;
	BstNode* root = NULL; // to store the address of root node
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	cout << "Enter a number to be searched:\n";
	cin >> num;
	if (Search(root, num) == true)
		cout << "Found\n";
	else
		cout << "Not Found\n";
}


