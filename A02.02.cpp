//Algorithm 2.2 (P24)(A02.02.cpp)
//ð�������㷨
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
	printf("����ð�������㷨��\n");
	randRangeArr(n, 0, 500, a);
	printf("����ǰ����:\n");
	printArr(a, n);
	bubbleSort(a, n);
	printf("���������:\n");
	printArr(a, n);
	printf("cnt=%d, cnt1=%d\n", cnt, cnt1);
	delete a;
}
