#include<iostream>

using namespace std;

void SelectionSort(int A[], int n)
{
	for (int i = 0; i <= n - 2; i++)
	{
		int iMin = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (A[j] < A[iMin])
				iMin = j;
		}
		int temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;
	}
}
void main()
{
	int A[6] = { 5,7,2,9,27,24 };
	SelectionSort(A, 6);
	for (int i = 0; i <= 5; i++)
	{
		cout << A[i] << endl;
	}
}