//Algorithm 4.12 (P106-7)(A04.12.cpp)
//����Ԫ�ػ��������㷨
#include "headers.h"
int pivotDivision(int A[], int low, int high)
{
	int i = low;
	int x = A[low];
	for (int k=low+1; k<=high; k++) {
		if (A[k] <= x) {
			i = i + 1;
			if (i != k)
				swap(&A[i], &A[k]);
		}
	}
	swap(&A[low], &A[i]);
	return i;
}
void pivotDivisionTest(int n)
{
	int *a = new int[n];
	printf("��������Ԫ�ػ��������㷨��\n");
	randRangeArr(n, 0, 500, a);
	printf("ԭʼ����:\n");
	printArr(a, n);
	int p = pivotDivision(a, 0, n-1);
	printf("���ֺ�����:\n");
	printArr(a, n);
	printf("����Ԫ��: %d�����λ��: %d\n", a[p], p);
	delete a;
}
