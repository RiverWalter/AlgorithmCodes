//Algorithm 3.1 (P59)(A03.01.cpp)
//�ϲ�����(ѭ��ʵ��)
#include "headers.h"
void mergeSort(int a[],int n)
{
	int i,s,t = 1;
	while (t<n) {
		s = t; t = 2 * s; i = 0;
		while (i+t<n) {
			merge(a,i,i+s-1,i+t-1);
			i = i + t;
		}
		if (i+s<n)
			merge(a,i,i+s-1,n-1);
	}
}
void mergeSortTest(int n)
{
	int *a = new int[n];
	printf("���Ժϲ������㷨(ѭ��ʵ��)��\n");
	randRangeArr(n, 0, 500, a);
	printf("����ǰ����:\n");
	printArr(a, n);
	mergeSort(a, n);
	printf("���������:\n");
	printArr(a, n);
	delete a;
}
