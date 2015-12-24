//heapTTest.cpp
//测试堆操作的模板实现
#include "headers.h"
void heapTSortTest(int n)
{
	ClsKEdge *e = new ClsKEdge[n];
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("原始数据列：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMaxT(e, n);
	printf("堆排序，从小到大：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("原始数据列：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMinT(e, n);
	printf("堆排序，从大到小：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	delete e;
}
void heapTTest(int n)
{
	ClsKEdge *e = new ClsKEdge[n];
	ClsKEdge e1;
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("原始数据列：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMaxT(e, n);
	printf("最大堆：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMaxT(e, n);
	printf("取顶元素: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMaxT(e, n);
	printf("取顶元素: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("原始数据列：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMinT(e, n);
	printf("最小堆：\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMinT(e, n);
	printf("取顶元素: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMinT(e, n);
	printf("取顶元素: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	delete e;
}