#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* link;
};

Node* head;

void insertBeginning(int n)
{
	Node* temp = new Node();
	temp->data = n;
	temp->link = head;
	head = temp;
}

void insertEnd(int n)
{
	Node* temp1 = new Node();
	temp1->data = n;
	temp1->link = NULL;
	Node* temp2 = head;
	while (temp2->link != NULL)
	{
		temp2 = temp2->link; //temp2 points to the last data
	}
	temp2->link = temp1;
}

void Print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << "Data = " << temp->data << endl;
		temp = temp->link; 
	}
}

void addNode(int posAdd, int addData)
{
	Node* temp1 = new Node();
	temp1->data = addData;
	Node* temp2 = head;
	if (posAdd == 1)
	{
		insertBeginning(addData);
		return;
	}
	for (int i = 0; i < posAdd - 2; i++) //-1 to remove the head as head is already dealt with above, and another -1 to point to (n-1)th node
	{
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}

void deleteNode(int posDel)
{
	Node* temp1, * temp2;
	temp2 = head;
	if (posDel == 1)
	{
		head = temp2->link;
		free(temp2);
		return;
	}
	for (int i = 0; i < posDel - 2; i++)
	{
		temp2 = temp2->link;
	}
	temp1 = temp2->link;
	temp2->link = temp1->link;
	free(temp1);
}

int searchNode(int dataSearch)
{
	int posSearch = 1;
	Node* temp = head;
	while (temp != NULL)
	{
		if (dataSearch == temp->data)
			return posSearch;
		temp = temp->link;
		posSearch += 1;
	}
	return 0;
}

int countNodes()
{
	int i=0;
	Node* temp = head;
	while (temp != NULL)
	{
		i += 1;
		temp = temp->link;
	}
	return i;
}

void Reverse()
{
	Node* current, * prev, * next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

int main()
{
	head = NULL;
	head = new Node();
	int numberOfNodes, n;
	cout << "Enter the number of nodes " << endl;
	cin >> numberOfNodes;

	char choice1, choice2, choice3;
	cout << "Where to enter data? b at beginning :: e at end" << endl;
	cin >> choice1;
		switch (choice1)
		{
		case 'b':
			for (int i = 0; i < numberOfNodes; i++)
			{
				cout << "Enter data for node " << i + 1 << endl;
				cin >> n;
				if (i == 0)
				{
					head->data = n;
				}
				else
					insertBeginning(n);
			}
			break;
		case 'e':
			for (int i = 0; i < numberOfNodes; i++)
			{
				cout << "Enter data for node " << i + 1 << endl;
				cin >> n;
				if (i == 0)
				{
					head->data = n;
				}
				else
					insertEnd(n);
			}
			break;
		default:
			break;
		}
	Print();
	
	Here:
	cout << "press e to edit data or press any key to exit\n";
	cin >> choice2;
	if (choice2 == 'e')
	{
		cout << "a to add data :: d to delete data :: s to search data :: c to count number of nodes :: r to reverse the data" << endl;
		cin >> choice3;
		switch (choice3)
		{
		case'a':
			int posAdd, addData;
			cout << "Enter the position to enter the data" << endl;
			cin >> posAdd;
			if (posAdd <= countNodes() + 1)
			{
				cout << "Enter the data" << endl;
				cin >> addData;
				addNode(posAdd, addData);
				cout << "The new list is: " << endl;
				Print();
			}
			else
				cout << "Enter a valid position. There are " << countNodes() << " data only" << endl;
			goto Here;

		case'd':
			int posDel;
			cout << "Enter the position to delete the data:" << endl;
			cin >> posDel;
			if (posDel <= countNodes())
			{
				deleteNode(posDel);
				Print();
			}
			else
				cout << "Enter a valid position. There are " << countNodes() << " data only" << endl;
			goto Here;

		case's':
			int dataSearch, posSearch;
			cout << "Enter the data to be searched in the list:" << endl;
			cin >> dataSearch;
			posSearch = searchNode(dataSearch);
			if (posSearch != 0)
				cout << "The data is in " << posSearch << " position" << endl;
			else
				cout << "Data not present in the list" << endl;
			goto Here;

		case'c':
			cout << "Total number of nodes = " << countNodes() << endl;
			goto Here;

		case'r':
			Reverse();
			cout << "The link in reverse order is:\n";
			Print();
			goto Here;

		default:
			cout << "Enter a valid input" << endl;
			goto Here;
		}
	}
	else
		return 0;
}