#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->link = temp;
	rear = temp;
}

void Dequeue()
{
	Node* temp = front;
	if (front == NULL)
		return;
	if (front == NULL && rear == NULL)
	{
		front = rear = NULL;
		return;
	}
	else
	{
		front = front->link;
		free(temp);
	}
}

void peek()
{
	if (front != NULL)
		cout << "Front data = " << front->data << endl;
	else
		cout << "Empty list" << endl;
}

void printQueue()
{
	Node* temp = front;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
	cout << '\n';
}

void main()
{
	char choice, choice2;
	int x;
	do
	{
		cout << "a to add :: d to remove :: p to peek front data" << endl;
		cin >> choice;
		switch (choice)
		{
		case'a':
			cout << "Enter the value: ";
			cin >> x;
			Enqueue(x);
			cout << "\n";
			printQueue();
			break;
		case'd':
			Dequeue();
			cout << "\n";
			printQueue();
			break;
		case'p':
			cout << "\n";
			peek();
			cout << "\n";
			break;
		default:
			cout << "Enter correct choice" << endl;
			break;
		}
		cout << "Again? y/n" << endl;
		cin >> choice2;
	} while (choice2 == 'y');
}