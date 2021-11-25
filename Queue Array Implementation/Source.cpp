#include<iostream>

using namespace std;

int front = -1;
int rear = -1;
int A[10];

bool isEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

void Enqueue(int x)
{
	if (rear == 9)
	{
		cout << "Queue is Full";
		return;
	}
	else if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear = rear + 1;
	}
	A[rear] = x;
}

void Dequeue()
{
	if (isEmpty())
		return;
	else if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = front + 1;
}

void printArray()
{
	for (int i = front; i <= rear; i++)
		cout << A[i] << endl;
	cout << "\n";
}

void main()
{
	char choice, choice2;
	int x;
	do
	{
		cout << "a to add :: d to remove" << endl;
		cin >> choice;
		switch (choice)
		{
		case'a':
			cout << "Enter the value: ";
			cin >> x;
			Enqueue(x);
			cout << "\n";
			printArray();
			break;
		case'd':
			Dequeue();
			cout << "\n";
			printArray();
			break;
		default:
			cout << "Enter correct choice" << endl;
			break;
		}
		cout << "Again? y/n" << endl;
		cin >> choice2;
	} while (choice2 == 'y');
}