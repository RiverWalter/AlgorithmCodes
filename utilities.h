//utilities.h
#pragma once
//�����ӡ��������
void printArrR(int a[], int n);
//��ӡ��������
void printArr(int a[], int n);
//��ӡ2ά��������,��������
void print2DArr(int **arr2, int n);
//��ӡ�ַ�������
void printArr(char a[], int n);
//������������
void swap(int *a, int *b);
//���������ַ�
void swap(char *a, char *b);
//Ϊ2ά�������ռ䲢����0��ʼ��
int **new2DArr(int rows, int cols);
//�ͷ�2ά����
void delete2DArr(int **a, int rows);
//Ϊ2ά���鸳����ĳ�ֵ(1-MAX_V)����������
//�������Խ���Ԫ��
//allowInf:��ΪInf�ı���
void randMatrix(int **arr2, int n, int allowInf=0);