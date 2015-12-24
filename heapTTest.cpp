//heapTTest.cpp
//���ԶѲ�����ģ��ʵ��
#include "headers.h"
void heapTSortTest(int n)
{
	ClsKEdge *e = new ClsKEdge[n];
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("ԭʼ�����У�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMaxT(e, n);
	printf("�����򣬴�С����\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("ԭʼ�����У�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMinT(e, n);
	printf("�����򣬴Ӵ�С��\n");
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
	printf("ԭʼ�����У�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMaxT(e, n);
	printf("���ѣ�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMaxT(e, n);
	printf("ȡ��Ԫ��: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMaxT(e, n);
	printf("ȡ��Ԫ��: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	for (int i=0; i<n; i++) 
		e[i].set(i, i, randRange(0, 99));
	printf("ԭʼ�����У�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	makeHeapMinT(e, n);
	printf("��С�ѣ�\n");
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMinT(e, n);
	printf("ȡ��Ԫ��: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	e1 = deleteTopMinT(e, n);
	printf("ȡ��Ԫ��: %d, n=%d\n", e1.cost, n);
	for (int i=0; i<n; i++) 
		printf("%3d", e[i].cost);
	printf("\n");
	delete e;
}