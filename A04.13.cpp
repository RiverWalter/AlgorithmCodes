//Algorithm 4.13 (P107-8)(A04.13.cpp)
//���������㷨
#include "headers.h"
void quickSort(int A[], int low, int high)
{
	if (low < high) {
		int k = pivotDivision(A,low,high);
		quickSort(A,low,k-1);
		quickSort(A,k+1,high);
	}
}
void quickSortTest(int n)
{
	int *a = new int[n];
	printf("���Կ��������㷨��\n");
	randRangeArr(n, 0, 500, a);
	printf("����ǰ����:\n");
	printArr(a, n);
	quickSort(a, 0, n-1);
	printf("���������:\n");
	printArr(a, n);
	delete a;
}
