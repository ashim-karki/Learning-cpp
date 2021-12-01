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
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

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

void Preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(Node* root)
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}

int main()
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

	cout << "Level Order traversal: " << endl;
	LevelOrder(root);
	cout << "\n";
	cout << "\n";

	cout << "Preorder traversal: " << endl;
	Preorder(root);
	cout << "\n";
	cout << "\n";

	cout << "Inorder traversal: " << endl;
	Inorder(root);
	cout << "\n";
	cout << "\n";

	cout << "Postorder traversal: " << endl;
	Postorder(root);
	cout << "\n";
	cout << "\n";
	return 0;
}