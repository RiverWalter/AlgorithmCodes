//Algorithm 2.7 (P31)(A02.07.cpp)
//插入排序法(循环实现)
#include "headers.h"
static int cnt = 0;
void insertionSort(int a[],int n)
{
	int x, j, k;
	for (int i=1;i<n;i++) {
		x = a[i];
		j = i - 1;
		k = 1;
		while (j>=0 && a[j]>x) {
			a[j+1] = a[j];
			j--;
			k++;
		}
		a[j+1] = x;
		cnt += k;
		//printf("i=%d, k=%d\n", i, k);
		//printArr(a, n);
	}
}
void insertionSortTest(int n)
{
	int *a = new int[n];
	printf("测试插入排序算法(循环实现)：\n");
	randRangeArr(n, 0, 500, a);
	printf("排序前数组:\n");
	printArr(a, n);
	bubbleSort(a, n);
	for (int i=0; i<n/2; i++)
		swap(&a[i], &a[n-1-i]);
	printArr(a, n);
	insertionSort(a, n);
	printf("排序后数组:\n");
	printArr(a, n);
	printf("cnt=%d\n", cnt);
	delete a;
}
