//Algorithm 2.11 (P36)(A02.11.cpp)
//改进的冒泡排序算法
#include "headers.h"
int bubbleSortA(int a[], int n)
{
	bool done;
	int round = n-1;
	for (int i=n-1; i>=1; i--) {
		done = true;
		for (int j=0; j<=i-1; j++)
			if (a[j]>a[j+1]) {
				swap(&a[j], &a[j+1]);
				done = false;
			}
			if (done) {
				round = n-i;
				break;
			}
	}
	return round;
}
void bubbleSortATest(int n)
{
	int *a = new int[n];
	printf("测试改进的冒泡排序算法：\n");
	randRangeArr(n, -100, 100, a);
	printf("排序前数组:\n");
	printArr(a, n);
	int m = bubbleSortA(a, n);
	printf("排序后数组:\n");
	printArr(a, n);
	printf("外循环次数: %d\n", m);
	m = bubbleSortA(a, n);
	printf("再排序:\n");
	printArr(a, n);
	printf("再排序外循环次数: %d\n", m);
	delete a;
}
