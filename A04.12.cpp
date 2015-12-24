//Algorithm 4.12 (P106-7)(A04.12.cpp)
//枢轴元素划分序列算法
#include "headers.h"
int pivotDivision(int A[], int low, int high)
{
	int i = low;
	int x = A[low];
	for (int k=low+1; k<=high; k++) {
		if (A[k] <= x) {
			i = i + 1;
			if (i != k)
				swap(&A[i], &A[k]);
		}
	}
	swap(&A[low], &A[i]);
	return i;
}
void pivotDivisionTest(int n)
{
	int *a = new int[n];
	printf("测试枢轴元素划分序列算法：\n");
	randRangeArr(n, 0, 500, a);
	printf("原始数组:\n");
	printArr(a, n);
	int p = pivotDivision(a, 0, n-1);
	printf("划分后数组:\n");
	printArr(a, n);
	printf("枢轴元素: %d；最后位置: %d\n", a[p], p);
	delete a;
}
