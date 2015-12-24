//Algorithm 4.10 (P95-6)(A04.10.cpp)
//�������Сֵ��(3/2)n�㷨
#include "headers.h"
void maxMin(int A[], int n, int &maxX, int &minX)
{
	int low = 0, high = n-1;
	if (A[low] < A[high]) {
		minX = A[low];
		maxX = A[high];
	} else {
		minX = A[high];
		maxX = A[low];
	}
	while (low < high) {
		low++;
		high--;
		if (A[low] < A[high]) {
			if (minX > A[low])
				minX = A[low];
			if (maxX < A[high])
				maxX = A[high];
		} else {
			if (minX > A[high])
				minX = A[high];
			if (maxX < A[low])
				maxX = A[low];
		}
	}
}
void maxMinTest(int n)
{
	int *a = new int[n];
	printf("�����������Сֵ�Ŀ����㷨��\n");
	randRangeArr(n, 0, 500, a);
	printf("����:\n");
	printArr(a, n);
	int ma, mi;
	maxMin(a, n, ma, mi);
	printf("��Сֵ��%d�����ֵ��%d\n", mi, ma);
	mergeSort(a, n);
	printf("���������:\n");
	printArr(a, n);
	delete a;
}