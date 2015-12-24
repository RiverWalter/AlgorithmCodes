//Algorithm 4.2 (P83-4)(A04.02.cpp)
//插入排序法(递归实现)
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
	printf("测试插入排序算法(递归实现)：\n");
	randRangeArr(n, 0, 500, a);
	printf("排序前数组:\n");
	printArr(a, n);
	insertionSortR(a, n);
	printf("排序后数组:\n");
	printArr(a, n);
	delete a;
}
