//algorithms.h
//֣�ں����㷨��������ơ���2���еĸ��㷨
#pragma once
#include "graph.h"
//Algorithm 1.1 (Pl)
//ŷ�����(Euclid)���Լ��(GCD)�㷨
//������ԭ����(300 B.C.)��շת�����
//�������㾭������Ԫ3-5����
//��������¡����ؾ��أ�1247
void euclidGCDTest(int n, bool verbose=false);
void euclidGCDTest(bool verbose=false);
void euclidGCDTest(int m, int n, bool verbose=false);
int euclidGCD(int m, int n, bool verbose=false);

//Algorithm 1.2 (P3-4)
//��Ԫ��ټ����⣬��ٷ�
void chickenSolutionTest(int n);
int chickenSolution(int n,int g[],int m[],int s[]);

//Algorithm 1.3 (P4)
//��Ԫ��ټ����⣬�Ľ�����ٷ�
void chickenSolutionATest(int n);
int chickenSolutionA(int n,int g[],int m[],int s[]);

//Algorithm 1.4 (P5)
//����������(TSP), ��ٷ�(Exhaustion) 
void findTSPMin(int **cityDist, int n, int *perm,
	int &minDist, int *minPath, bool verbose);
void TSPExhaustion(int **cityDist, int i, int n, 
	int *perm, int &minDist, int *minPath, bool verbose);
void TSPExhaustionTest(int n, bool verbose = false);
void TSPExhaustionTestEx5_2(bool verbose=false);

//Algorithm 2.1 (P23-4)
//Horner���������ʽ(ѭ��ʵ��)
void polynomialTest(int n);

//Algorithm 2.2 (P24)
//ð�������㷨
void bubbleSortTest(int n);
void bubbleSort(int a[], int n);

//Algorithm 2.3 (P25-6)
//��̭��
void knockoutTest(int k, bool verbose);

//Algorithm 2.5 (P27-8)
//�ϲ���������������㷨
void merge(int a[],int p,int q,int r);
void mergeTest(int m, int n);

//Algorithm 2.6 (P29-30)(A02.06.cpp)
//�ո�ײ��㷨
void reap(int B[],int n);
void reapTest(int n);

//Algorithm 2.7 (P31)
//��������
void insertionSort(int a[],int n);
void insertionSortTest(int n);

//Algorithm 2.8 (P22-33)
//���Բ����㷨
int linearSearch(int a[],int n,int x);
void linearSearchTest(int n);

//Algorithm 2.9 (P32-3)
//�۰����(��������)�㷨
int binarySearch(int a[], int n, int x);
void binarySearchTest(int n);

//Algorithm 2.11 (P36)
//�Ľ���ð�������㷨
void bubbleSortATest(int n);

//Algorithm 2.12 (P41)
//��ŵ��(Hanoi tower)����
void HanoiTest(int n);

//Algorithm 3.1 (P59)
//�ϲ�����(ѭ����)
void mergeSort(int a[],int n);
void mergeSortTest(int n);

//Algorithm 3.9 (P70)
//������
void heapSort(int A[],int n);
void heapSortTest(int n);

//Algorithm 4.1 (P83)
//�ݹ鷨��׳�
void factorialTest(int n);

//Algorithm 4.2 (P59)
//��������(�ݹ�ʵ��)
void insertionSortR(int A[],int n);
void insertionSortRTest(int n);

//Algorithm 4.3 (P84-5)
//�ݺ�����logn�㷨
long power(long a, int b);
void powerTest(int a, int b);

//Algorithm 4.5 (P87)
//����ȫ���еĵݹ��㷨
void permute(char *a, int i, int n);
void permuteTest(int n);

//Algorithm 4.10 (P95-6)
//�������Сֵ�Ŀ����㷨
void maxMinTest(int n);

//Algorithm 4.11 (P98)
//�ϲ�����ĵݹ�ʵ��
void mergeSortR(int A[],int low,int high);
void mergeSortRTest(int n);

//Algorithm 4.12 (P106-7)
//����Ԫ�ػ��������㷨
int pivotDivision(int A[], int low, int high);
void pivotDivisionTest(int n);

//Algorithm 4.13 (P107-8)
//���������㷨
void quickSort(int A[], int low, int high);
void quickSortTest(int n);

//Algorithm 5.0 (P141-2)
//TSP�����̰���㷨
void TSPGreedy(int *cityDist[], int n,
	int &minDist, int *minPath);
void TSPGreedyEx5_2();
void TSPGreedyTest(int n);

//Algorithm 5.1 (P143-4)
//�ɷָ��(knapsack)�����̰���㷨
void knapsackGreedyTest(int n);

//Algorithm 5.2 (P147-8)
//�Ͽ�˹����(Dijkstra)���·���㷨
void DijkstraEx5_3Test();
void DijkstraTest(int n);

//Algorithm 5.3 (P153-4)
//��³˹����(Kruskal)��С�����������㷨
void KruskalEx5_4Test();
void KruskalTest(int n);

//Algorithm 5.4 (P156-7)
//����ķ(Prim)��С�����������㷨
void PrimEx5_4Test();
void PrimTest(int n);

//Algorithm 5.5 (P163-4)
//������(Huffman)���Ŷ������㷨
void HuffmanTestEx5_6();
void HuffmanTest(int n);

//Algorithm 6.00 (P169-70)(A06.00.cpp)
//����������(TSP)�Ķ�̬�滮�㷨
void testTSPDPEx6_1();
void testTSPDP(int n);

//Algorithm 6.04 (P189-90)(A06.04.cpp)
//����������еĶ�̬�滮�㷨
void testLCSSDPEx6_5();
void testLCSSDP(int chars, int lenA, int lenB);

//Algorithm 6.05 (P192-3)(A06.05.cpp)
//0/1����(knapsack)����Ķ�̬�滮�㷨
void testKnapsackDPEx6_6();
void testKnapsackDP(int n);

//Algorithm 6.06 (P196-8)(A06.06.cpp)
//RNA�������ƥ��Ķ�̬�滮�㷨
void testRNADPEx6_7();
void testRNADP(int n);

//Algorithm 9.0 (P267)
void random_seed9(unsigned long d);
unsigned int random9(unsigned long low,unsigned long high);
void random9Test(int n, int low, int high);

//Algorithm 10.1 (P286-7)
//ͼ��������������㷨
int DFSTest(ClstoVertex *adjLst, int n);
void traverseDFSTest(int n, int nInf=5);
