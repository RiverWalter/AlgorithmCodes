//utilities.cpp
#include "headers.h"
//�����ӡ��������
void printArrR(int a[], int n)
{
	for (int i=n-1; i>=0; i--)
		printf("%4d", a[i]);
	printf("\n");
}
//��ӡ��������
void printArr(int a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%4d", a[i]);
	printf("\n");
}
//��ӡ2ά��������,��������
void print2DArr(int **arr2, int n)
{
	printf("����/�ڽӾ���\n");
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
//��ӡ�ַ�������
void printArr(char a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%2c", a[i]);
	printf("\n");
}
//������������
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//���������ַ�
void swap(char *a, char *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//Ϊ2ά�������ռ䲢��ʼ��
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
//�ͷ�2ά����
void delete2DArr(int **a, int rows)
{
	for (int i=0; i<rows; i++)
		delete a[i];
	delete a;
}
//Ϊ2ά���鸳����ĳ�ֵ(1-MAX_V)����������
//�������Խ���Ԫ��
//allowInf:��ΪInf�����ݸ���
#define MAX_V 9
void randMatrix(int **arr2, int n, int allowInf)
{
	//���������ΪInf��ֵ
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
