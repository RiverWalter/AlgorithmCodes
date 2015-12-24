//algorithms.h
//郑宗汉《算法分析与设计》第2版中的各算法
#pragma once
#include "graph.h"
//Algorithm 1.1 (Pl)
//欧几里德(Euclid)最大公约数(GCD)算法
//《几何原本》(300 B.C.)，辗转相除法
//《孙子算经》，公元3-5世纪
//《数书九章》，秦九韶，1247
void euclidGCDTest(int n, bool verbose=false);
void euclidGCDTest(bool verbose=false);
void euclidGCDTest(int m, int n, bool verbose=false);
int euclidGCD(int m, int n, bool verbose=false);

//Algorithm 1.2 (P3-4)
//百元买百鸡问题，穷举法
void chickenSolutionTest(int n);
int chickenSolution(int n,int g[],int m[],int s[]);

//Algorithm 1.3 (P4)
//百元买百鸡问题，改进的穷举法
void chickenSolutionATest(int n);
int chickenSolutionA(int n,int g[],int m[],int s[]);

//Algorithm 1.4 (P5)
//旅行商问题(TSP), 穷举法(Exhaustion) 
void findTSPMin(int **cityDist, int n, int *perm,
	int &minDist, int *minPath, bool verbose);
void TSPExhaustion(int **cityDist, int i, int n, 
	int *perm, int &minDist, int *minPath, bool verbose);
void TSPExhaustionTest(int n, bool verbose = false);
void TSPExhaustionTestEx5_2(bool verbose=false);

//Algorithm 2.1 (P23-4)
//Horner法计算多项式(循环实现)
void polynomialTest(int n);

//Algorithm 2.2 (P24)
//冒泡排序算法
void bubbleSortTest(int n);
void bubbleSort(int a[], int n);

//Algorithm 2.3 (P25-6)
//淘汰赛
void knockoutTest(int k, bool verbose);

//Algorithm 2.5 (P27-8)
//合并两个有序数组的算法
void merge(int a[],int p,int q,int r);
void mergeTest(int m, int n);

//Algorithm 2.6 (P29-30)(A02.06.cpp)
//收割白菜算法
void reap(int B[],int n);
void reapTest(int n);

//Algorithm 2.7 (P31)
//插入排序法
void insertionSort(int a[],int n);
void insertionSortTest(int n);

//Algorithm 2.8 (P22-33)
//线性查找算法
int linearSearch(int a[],int n,int x);
void linearSearchTest(int n);

//Algorithm 2.9 (P32-3)
//折半查找(二叉搜索)算法
int binarySearch(int a[], int n, int x);
void binarySearchTest(int n);

//Algorithm 2.11 (P36)
//改进的冒泡排序算法
void bubbleSortATest(int n);

//Algorithm 2.12 (P41)
//汉诺塔(Hanoi tower)问题
void HanoiTest(int n);

//Algorithm 3.1 (P59)
//合并排序(循环法)
void mergeSort(int a[],int n);
void mergeSortTest(int n);

//Algorithm 3.9 (P70)
//堆排序
void heapSort(int A[],int n);
void heapSortTest(int n);

//Algorithm 4.1 (P83)
//递归法求阶乘
void factorialTest(int n);

//Algorithm 4.2 (P59)
//插入排序法(递归实现)
void insertionSortR(int A[],int n);
void insertionSortRTest(int n);

//Algorithm 4.3 (P84-5)
//幂函数的logn算法
long power(long a, int b);
void powerTest(int a, int b);

//Algorithm 4.5 (P87)
//生成全排列的递归算法
void permute(char *a, int i, int n);
void permuteTest(int n);

//Algorithm 4.10 (P95-6)
//求最大最小值的快速算法
void maxMinTest(int n);

//Algorithm 4.11 (P98)
//合并排序的递归实现
void mergeSortR(int A[],int low,int high);
void mergeSortRTest(int n);

//Algorithm 4.12 (P106-7)
//枢轴元素划分序列算法
int pivotDivision(int A[], int low, int high);
void pivotDivisionTest(int n);

//Algorithm 4.13 (P107-8)
//快速排序算法
void quickSort(int A[], int low, int high);
void quickSortTest(int n);

//Algorithm 5.0 (P141-2)
//TSP问题的贪婪算法
void TSPGreedy(int *cityDist[], int n,
	int &minDist, int *minPath);
void TSPGreedyEx5_2();
void TSPGreedyTest(int n);

//Algorithm 5.1 (P143-4)
//可分割背包(knapsack)问题的贪婪算法
void knapsackGreedyTest(int n);

//Algorithm 5.2 (P147-8)
//迪克斯特拉(Dijkstra)最短路径算法
void DijkstraEx5_3Test();
void DijkstraTest(int n);

//Algorithm 5.3 (P153-4)
//克鲁斯卡尔(Kruskal)最小花费生成树算法
void KruskalEx5_4Test();
void KruskalTest(int n);

//Algorithm 5.4 (P156-7)
//普里姆(Prim)最小花费生成树算法
void PrimEx5_4Test();
void PrimTest(int n);

//Algorithm 5.5 (P163-4)
//哈夫曼(Huffman)最优二叉树算法
void HuffmanTestEx5_6();
void HuffmanTest(int n);

//Algorithm 6.00 (P169-70)(A06.00.cpp)
//旅行商问题(TSP)的动态规划算法
void testTSPDPEx6_1();
void testTSPDP(int n);

//Algorithm 6.04 (P189-90)(A06.04.cpp)
//最长公共子序列的动态规划算法
void testLCSSDPEx6_5();
void testLCSSDP(int chars, int lenA, int lenB);

//Algorithm 6.05 (P192-3)(A06.05.cpp)
//0/1背包(knapsack)问题的动态规划算法
void testKnapsackDPEx6_6();
void testKnapsackDP(int n);

//Algorithm 6.06 (P196-8)(A06.06.cpp)
//RNA最大碱基对匹配的动态规划算法
void testRNADPEx6_7();
void testRNADP(int n);

//Algorithm 9.0 (P267)
void random_seed9(unsigned long d);
unsigned int random9(unsigned long low,unsigned long high);
void random9Test(int n, int low, int high);

//Algorithm 10.1 (P286-7)
//图的深度优先搜索算法
int DFSTest(ClstoVertex *adjLst, int n);
void traverseDFSTest(int n, int nInf=5);
