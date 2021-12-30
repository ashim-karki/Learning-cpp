#include<iostream>

using namespace std;

int BinarySearch(int A[], int start, int end, int x)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (x == A[mid])
		return mid;
	else if (x < A[mid])
		return BinarySearch(A, start, mid-1, x);
	else
		return BinarySearch(A, mid + 1, end, x);
}

void main()
{
	int A[] = { 2,4,5,7,10,13,15,19 };
	int x;
	cout << "Enter number to be searched for:" << endl;
	cin >> x;
	int y = BinarySearch(A, 0, 7, x);
	if (y == -1)
		cout << "Not found";
	else
		cout << "The number is in index " << y + 1;
}