//Algorithm 4.5 (P87)(A04.05.cpp)
//生成全排列的递归算法
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
	printf("测试生成全排列的递归算法：\n");
	char a[10];
	for (int i=0; i<n; i++)
		a[i] = i+49;
	printf("1--%d的全排列:\n", n);
	permute(a, 0, n);
}
