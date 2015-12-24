//Algorithm 4.5 (P87)(A04.05.cpp)
//����ȫ���еĵݹ��㷨
#include "headers.h"
void permute(char *a, int i, int n)
{
	if (i == n-1)
		printArr(a, n);
	else
		for (int j = i; j < n; j++) {
			swap((a+i), (a+j));
			permute(a, i+1, n);
			swap((a+i), (a+j)); //backtrack
		}
}
void permuteTest(int n)
{
	printf("��������ȫ���еĵݹ��㷨��\n");
	char a[10];
	for (int i=0; i<n; i++)
		a[i] = i+49;
	printf("1--%d��ȫ����:\n", n);
	permute(a, 0, n);
}
