#include<iostream>

using namespace std;

void InsertionSort(int A[], int n)
{
	int value = 0, hole = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		value = A[i];
		hole = i;
		while (hole > 0 && A[hole - 1] > value)
		{
			A[hole] = A[hole - 1];
			hole = hole - 1;
		}
		A[hole] = value;
	}
}

void main()
{
	int A[6] = { 2,7,4,1,5,3 };
	InsertionSort(A, 6);
	for (int i = 0; i <= 5; i++)
		cout << A[i] << endl;
}