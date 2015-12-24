//Algorithm 4.11 (P98)(A04.11.cpp)
//�ϲ�����ĵݹ�ʵ��
#include "headers.h"
void mergeSortR(int A[],int low,int high)
{
	if (low<high) {
		int mid = (low + high)/2;
		mergeSortR(A,low,mid);
		mergeSortR(A,mid+1,high);
		merge(A,low,mid,high);
	}
}
void mergeSortRTest(int n)
{
	int *a = new int[n];
	printf("���Ժϲ������㷨(�ݹ�ʵ��)��\n");
	randRangeArr(n, 0, 500, a);
	printf("����ǰ����:\n");
	printArr(a, n);
	mergeSortR(a, 0, n-1);
	printf("���������:\n");
	printArr(a, n);
	delete a;
}
