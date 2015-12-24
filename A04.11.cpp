//Algorithm 4.11 (P98)(A04.11.cpp)
//合并排序的递归实现
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
	printf("测试合并排序算法(递归实现)：\n");
	randRangeArr(n, 0, 500, a);
	printf("排序前数组:\n");
	printArr(a, n);
	mergeSortR(a, 0, n-1);
	printf("排序后数组:\n");
	printArr(a, n);
	delete a;
}
