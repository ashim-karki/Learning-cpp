#include<iostream>

using namespace std;

void Merge(int A[], int left, int mid, int right)
{
	int size1 = mid - left + 1;
	int size2 = right - mid;
	int* leftA = new int[size1];
	int* rightA = new int[size2];
	for (int i = 0; i < size1; i++)
	{
		leftA[i] = A[left + i];
	}
	for (int i = 0; i < size2; i++)
	{
		rightA[i] = A[mid + 1 + i];
	}
	int i = 0, j = 0, k = left;
	while (i < size1 && j < size2)
	{
		if (leftA[i] <= rightA[j])
		{
			A[k] = leftA[i];
			i++;
		}
		else
		{
			A[k] = rightA[j];
			j++;
		}
		k++;
	}
	while (i < size1)
	{
		A[k] = leftA[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		A[k] = rightA[j];
		j++;
		k++;
	}
}

void MergeSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void main()
{
	int A[] = { 6,2,5,3,1,7,8,9,4 };
	int A_size = sizeof(A) / sizeof(A[0]);
	cout << "Unsorted Array:" << endl;
	for (int i = 0; i < A_size; i++)
		cout << A[i] << " ";
	MergeSort(A, 0, A_size - 1);
	cout << endl;
	cout << "Sorted Array:" << endl;
	for (int i = 0; i < A_size; i++)
	{
		cout << A[i] << " ";
	}
}
