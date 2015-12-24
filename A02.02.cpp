//Algorithm 2.2 (P24)(A02.02.cpp)
//冒泡排序算法
#include "headers.h"
static int cnt = 0;
static int cnt1 = 0;
void bubbleSort(int a[], int n)
{
	for (int i=n-1; i>=1; i--) {
		for (int j=0; j<=i-1; j++) {
			cnt++;
			if (a[j]>a[j+1]) {
				cnt1++;
				swap(&a[j], &a[j+1]);
			}
		}
		//printArr(a, n);
	}
}
void bubbleSortTest(int n)
{
	int *a = new int[n];
	printf("测试冒泡排序算法：\n");
	randRangeArr(n, 0, 500, a);
	printf("排序前数组:\n");
	printArr(a, n);
	bubbleSort(a, n);
	printf("排序后数组:\n");
	printArr(a, n);
	printf("cnt=%d, cnt1=%d\n", cnt, cnt1);
	delete a;
}
