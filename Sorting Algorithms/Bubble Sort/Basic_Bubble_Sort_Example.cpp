#include<iostream>

using namespace std;

void BubbleSort(int A[], int n)
{
	int temp = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j <= n - i - 1; j++)//sorted element gets bubbled to last position so no need to sort it out in next pass
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void main()
{
	int A[6] = { 2,7,4,1,5,3 };
	BubbleSort(A, 6);
	for (int i = 0; i <= 5; i++)
		cout << A[i] << endl;
}
