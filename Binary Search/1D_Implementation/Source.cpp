#include<iostream>

using namespace std;

int BinarySearch(int A[], int n, int x)
{
	int start = 0;
	int end = n - 1;
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x == A[mid])
			return mid;
		else if (x < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

void main()
{
	int A[] = { 2,4,5,7,10,13,15,19 };
	int x;
	cout << "Enter number to be searched for:" << endl;
	cin >> x;
	int y = BinarySearch(A, 8, x);
	if (y == -1)
		cout << "Not found";
	else
		cout << "The number is in index " << y+1;
}