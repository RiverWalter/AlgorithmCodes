//Algorithm 2.9 (P32-3)(A02.09.cpp)
//折半查找(二叉搜索)算法
#include "headers.h"
int binarySearch(int a[], int n, int x)
{
	int mid, low = 0, high = n - 1, j = -1;
	int k = 0;
	while (low<=high && j<0) {
		mid = (low + high) / 2;
		if (x==a[mid]) j = mid;
		else if (x<a[mid]) 
			high = mid -1;
		else low = mid + 1;
		k++;
	}
	printf("k=%d\n", k);
	return j;
}
void binarySearchTest(int n)
{
	int *a = new int[n];
	int m = 3*n/2;
	randRangeArr(n, 1, m, a);
	insertionSort(a, n);
	int x = randRange(1, m);
	int p = binarySearch(a, n, x);
	printf("折半查找测试:\n");
	printf("数组：\n");
	printArr(a, n);
	printf("待查元素: %d\n", x);
	if (p != -1)
		printf("位置: %d\n", p);
	else
		printf("未找到！\n");
	delete a;
}
