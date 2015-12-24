//utilities.h
#pragma once
//逆序打印整型数组
void printArrR(int a[], int n);
//打印整型数组
void printArr(int a[], int n);
//打印2维整型数组,如距离矩阵
void print2DArr(int **arr2, int n);
//打印字符型数组
void printArr(char a[], int n);
//交换两个整数
void swap(int *a, int *b);
//交换两个字符
void swap(char *a, char *b);
//为2维数组分配空间并进行0初始化
int **new2DArr(int rows, int cols);
//释放2维数组
void delete2DArr(int **a, int rows);
//为2维数组赋随机的初值(1-MAX_V)，如距离矩阵
//不包括对角线元素
//allowInf:作为Inf的比例
void randMatrix(int **arr2, int n, int allowInf=0);