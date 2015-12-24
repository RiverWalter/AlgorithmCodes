//utilities.cpp
#include "headers.h"
//逆序打印整型数组
void printArrR(int a[], int n)
{
	for (int i=n-1; i>=0; i--)
		printf("%4d", a[i]);
	printf("\n");
}
//打印整型数组
void printArr(int a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%4d", a[i]);
	printf("\n");
}
//打印2维整型数组,如距离矩阵
void print2DArr(int **arr2, int n)
{
	printf("距离/邻接矩阵：\n");
	printf("  ");
	for (int i=0; i<n; i++)
		printf("%2c", i+65);
	printf("\n");
	for (int i=0; i<n; i++) {
		printf("%2c", i+65);
		for (int j=0; j<n; j++)
			if (arr2[i][j] == Inf)
				printf(" x");
			else
				printf("%2d", arr2[i][j]);
		printf("\n");
	}
}
//打印字符型数组
void printArr(char a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%2c", a[i]);
	printf("\n");
}
//交换两个整数
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//交换两个字符
void swap(char *a, char *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//为2维数组分配空间并初始化
int **new2DArr(int rows, int cols)
{
	int **a = new int *[rows];
	for (int i=0; i<rows; i++) {
		a[i] = new int[cols];
		for (int j=0; j<cols; j++)
			a[i][j] = 0;
	}
	return a;
}
//释放2维数组
void delete2DArr(int **a, int rows)
{
	for (int i=0; i<rows; i++)
		delete a[i];
	delete a;
}
//为2维数组赋随机的初值(1-MAX_V)，如距离矩阵
//不包括对角线元素
//allowInf:作为Inf的数据个数
#define MAX_V 9
void randMatrix(int **arr2, int n, int allowInf)
{
	//随机生成作为Inf的值
	set<int> randSet;
	set<int>::iterator it;
	randRangeSet(allowInf, 1, MAX_V, randSet);
	int d;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			d = randRange(1,MAX_V);
			it = randSet.find(d);
			if (it != randSet.end())
				d = Inf;
			arr2[i][j] = d;
			arr2[j][i] = d;
		}
	}
}
