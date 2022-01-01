#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* link;
};

Node* createList(Node* head, int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = head;
	head = temp;
	return head;
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
	cout << endl;
}

void FindMiddle(Node* current, Node** first, Node** second)
{
	Node* slow = current;
	Node* fast = current->link;
	while (fast != NULL)
	{
		fast = fast->link;
		if (fast != NULL)
		{
			fast = fast->link;
			slow = slow->link;
		}
	}
	*first = current;
	*second = slow->link;
	slow->link = NULL;
}

Node* Merge(Node* first, Node* second)
{
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	Node* final = NULL;
	if (first->data <= second->data)
	{
		final = first;
		final->link = Merge(first->link, second);
	}
	else
	{
		final = second;
		final->link = Merge(first, second->link);
	}
	return final;
}

void MergeSort(Node** head)
{
	Node* current = *head;
	Node* first;
	Node* second;
	if (current == NULL || current->link == NULL)
		return;
	FindMiddle(current, &first, &second);
	MergeSort(&first);
	MergeSort(&second);
	*head = Merge(first, second);
}

void main()
{
	Node* head = NULL;
	int n;
	int x;
	cout << "Enter the number of data to be added:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter data:" << endl;
		cin >> x;
		head = createList(head, x);
	}
	cout << endl;
	printList(head);
	MergeSort(&head);
	printList(head);
}