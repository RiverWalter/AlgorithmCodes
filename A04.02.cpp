//Algorithm 4.2 (P83-4)(A04.02.cpp)
//��������(�ݹ�ʵ��)
#include "headers.h"
void insertionSortR(int A[],int n)
{
	if (n>1) {
		insertionSortR(A,n-1);
		int a = A[n-1];
		int k = n - 2;
		while ((k>=0)&&(A[k]>a)) {
			A[k+1] = A[k];
			k = k - 1;
		}
		A[k+1] = a;
	}
}
void insertionSortRTest(int n)
{
	int *a = new int[n];
	printf("���Բ��������㷨(�ݹ�ʵ��)��\n");
	randRangeArr(n, 0, 500, a);
	printf("����ǰ����:\n");
	printArr(a, n);
	insertionSortR(a, n);
	printf("���������:\n");
	printArr(a, n);
	delete a;
}
