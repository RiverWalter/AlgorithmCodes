//Algorithm 2.8 (P22-33)(A02.08.cpp)
//线性查找算法
#include "headers.h"
int linearSearch(int a[],int n,int x)
{
	int j = 0;
	while (j<n && x!=a[j])
		j++;
	printf("j=%d\n", j+1);
	if (j==n)
		j = -1;
	return j;
}
void linearSearchTest(int n)
{
	int *a = new int[n];
	int m = 3*n/2;
	randRangeArr(n, 1, m, a);
	int x = randRange(1, m);
	int p = linearSearch(a, n, x);
	printf("线性查找测试:\n");
	printf("数组：\n");
	printArr(a, n);
	printf("待查元素: %d\n", x);
	if (p != -1)
		printf("位置: %d\n", p);
	else
		printf("未找到！\n");
	delete a;
}
