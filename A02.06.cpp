//Algorithm 2.6 (P29-30)(A02.06.cpp)
//�ո�ײ��㷨
#include "headers.h"
void reap(int B[],int n)
{
	int i, j, k, s, t;
	int *A = new int[n];
	for (i=0;i<n;i++)
		A[i] = i+1;
	j = 0; k = 3; s = n;
	while (j<n) {
		t = s; s= 0;
		for (i=0;i<t;i++) {
			if (--k != 0)
				A[s++] = A[i];
			else {
				B[j++] = A[i]; k = 3;
			}
		}
	}
	delete A;
}
void reapTest(int n)
{
	int *a = new int[n];
	for (int i=0;i<n;i++)
		a[i] = 0;
	printf("�ո�%d�Űײˡ�\n", n);
	printf("�ո�˳��\n");
	reap(a, n);
	printArr(a, n);
	delete a;
}