//Algorithm 3.2-3.9 (P63-70)(A03.02-09.cpp)
//堆排序算法
#include "headers.h"
//Algorithm 3.2
//结点上移
void siftUp(int H[],int i)
{
	bool done = false;
	if (i!=0) {
		while (!done && i!=0) {
			if (H[i] > H[(i-1)/2])
				swap(&H[i],&H[(i-1)/2]);
			else done = true;
			i=(i-1)/2;
		}
	}
}
//Algorithm 3.3 (P64-5)
//结点下移
void siftDown(int H[],int n,int i)
{
	bool done = false;
	while (!done && ((i=2*i+1)<n)) {
		if ((i+1<n)&&(H[i+1]>H[i]))
			i = i + 1;
		if (H[(i-1)/2] < H[i])
			swap(&H[(i-1)/2],&H[i]);
		else done = true;
	}
}
//Algorithm 3.4 (P65)
//插入元素
void insert(int H[],int &n, int x)
{
	n = n + 1;
	H[n] = x;
	siftUp(H,n);
}
//Algorithm 3.5 (P66)
//删除元素
void deleteI(int H[],int &n,int i)
{
	int x,y;
	x = H[i]; y = H[n];
	n = n - 1;
	if (i<n) {
		H[i] = y;
		if (y>x)
			siftUp(H,i);
		else
			siftDown(H,n,i);
	}
}
//Algorithm 3.6 (P66-7)
//删除最大元素
int deleteMax(int H[],int &n)
{
	int x;
	x = H[0];
	deleteI(H,n,0);
	return x;
}
//Algorithm 3.7 (P67)
//插入法建堆
void makeHeapIns(int A[],int H[],int n)
{
	int m=0;
	for (int i=0;i<n;i++)
		insert(H,m,A[i]);
}
//Algorithm 3.8 (P67)
//堆法建堆
void makeHeap(int A[],int n)
{
	for (int i=n/2-1;i>=0;i--) {
		siftDown(A,n,i);
	}
}
//Algorithm 3.9 (P70)
//堆排序
void heapSort(int A[],int n)
{
	makeHeap(A,n);
	for (int i=n-1;i>0;i--) {
		swap(&A[0],&A[i] );
		siftDown(A,i,0);
	}
}
void heapSortTest(int n)
{
	int *a = new int[n];
	printf("测试堆排序算法：\n");
	randRangeArr(n, 0, 500, a);
	printf("排序前数组:\n");
	printArr(a, n);
	heapSort(a, n);
	printf("排序后数组:\n");
	printArr(a, n);
	delete a;
}
