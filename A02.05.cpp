//Algorithm 2.5 (P27-8)(A02.05.cpp)
//�ϲ�������������������㷨
#include "headers.h"
void merge(int a[],int p,int q,int r)
{
	int *b = new int[r-p+1];
	int i = p, j = q + 1, k = 0;
	while (i<=q && j<=r) {
		if (a[i]<a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	if (i==q+1)
		for (;j<=r;j++)
			b[k++] = a[j];
	else
		for (;i<=q;i++)
			b[k++] = a[i];
	k=0;
	for (i=p;i<=r;i++)
		a[i] = b[k++];
	delete b;
}
void mergeTest(int m, int n)
{
	int k = m+n;
	int *a = new int[k];
	randRangeArr(k, 0, 99, a);
	printf("�Գ���Ϊ%d��%d������������кϲ���\n", m, n);
	printf("ԭʼ���飺\n");
	printArr(a, k);
	bubbleSort(a, m);
	bubbleSort(a+m, n);
	printf("����������\n");
	printArr(a, k);
	merge(a, 0, m-1, k-1);
	printf("�ϲ���\n");
	printArr(a, k);
	delete a;
}