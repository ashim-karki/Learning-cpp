#include<iostream>

using namespace std;

const int MAX = 4;

//Binary searching rows to find in which row the data lies.
int findRow(int A[][MAX], int i, int j, int x)
{
	int start = 0;
	int end = i;
	if (start > end)
		return -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (x >= A[mid][0] && x <= A[mid][j])
			return mid;
		else if (x < A[mid][0])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
	
//This is a linear recursion search.
	/*if (x >= A[currentRow][0] && x <= A[currentRow][j])
		return currentRow;
	else if (x < A[currentRow][0] && currentRow > 0)
		return findRow(A, currentRow - 1, j, x);
	else if (x > A[currentRow][0] && currentRow < j)
		return findRow(A, currentRow + 1, j, x);
	else
		return -1;*/
}

//After finding in which row the data lies we binary search the column to search the data.
int findColumn(int A[][MAX], int i, int j, int x)
{
	int Row = findRow(A, i, j, x);
	if (Row == -1)
		return -1;
	int start = 0;
	int end = j;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (x == A[Row][mid])
			return mid;
		else if (x > A[Row][mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

void main()
{
	int A[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int z;
	cout << "Enter the data to be searched:" << endl;
	cin >> z;
	int x;
	x = findRow(A, 3, 3, z);
	int y;
	y = findColumn(A, 3, 3, z);
	if (x == -1 || y == -1)
		cout << "Not found" << endl;
	else
		cout << "Found in Row: " << x << " and column: " << y << endl;
}