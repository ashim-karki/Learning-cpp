#include<iostream>
#include<queue>

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

BstNode* FindMin(BstNode* root) //moving as left as possible
{
	while (root->leftChild != NULL)
	{
		root = root->leftChild;
	}
	return root;
}

BstNode* Delete(BstNode* root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->data)
		root->leftChild = Delete(root->leftChild, data);
	else if (data > root->data)
		root->rightChild = Delete(root->rightChild, data);
	else //if data to be deleted is found
	{
		//Case 1: No Child
		if (root->leftChild == NULL && root->rightChild == NULL)
		{
			delete root; //delete deallocates the memory from head. free is used in C.
			root = NULL;
		}
		//Case 2: One Child
		else if (root->leftChild == NULL)
		{
			BstNode* temp = root;
			root = root->rightChild;
			delete temp;
		}
		else if (root->rightChild == NULL)
		{
			BstNode* temp = root;
			root = root->leftChild;
			delete temp;
		}
		//Case 3: 2 children
		else
		{
			BstNode* temp = FindMin(root->rightChild);
			root->data = temp->data;
			root->rightChild = Delete(root->rightChild, temp->data); //recursion
		}
	}
	return root;
}

void LevelOrder(BstNode* root)
{
	if (root == NULL)
		return;
	queue<BstNode*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		BstNode* current = Q.front();
		cout << current->data << " ";
		if (current->leftChild != NULL)
			Q.push(current->leftChild);
		if (current->rightChild != NULL)
			Q.push(current->rightChild);
		Q.pop();
	}
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
	cout << "Initial:" << endl;
	LevelOrder(root);
	cout << "\n";
	Delete(root, 14);
	cout << "After Deletion" << endl;
	LevelOrder(root);
}