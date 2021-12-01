#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
	char data;
	Node* left;
	Node* right;
};

void LevelOrder(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		Node* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
		Q.pop(); 
	}
}

Node* GetNewNode(char data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, char data)
{
	if (root == NULL)
		root = GetNewNode(data);
	else if (data <= root->data)
		root->left = Insert(root->left, data); //recursion
	else
		root->right = Insert(root->right, data); //recursion
	return root;
}

void main()
{
	Node* root = NULL;
	root = Insert(root, 'F');
	root = Insert(root, 'D');
	root = Insert(root, 'J');
	root = Insert(root, 'B');
	root = Insert(root, 'E');
	root = Insert(root, 'G');
	root = Insert(root, 'K');
	root = Insert(root, 'I');
	root = Insert(root, 'H');
	root = Insert(root, 'C');
	root = Insert(root, 'A');
	LevelOrder(root);
}