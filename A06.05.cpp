//Algorithm 6.05 (P192-3)(A06.05.cpp)
//0/1背包(knapsack)问题的动态规划算法
#include "headers.h"
void printDetail(int **s, int n, int W);
void KnapsackDP(int *w, int *v, int n, int W, 
	bool *x, int &wa, int &va, bool verbose = false)
{
	int **s = new2DArr(n+1, W+1);
	//0:初始化
	for (int i=0; i<n+1; i++) {
		s[i][0] = 0;
		if (i<n)
			x[i] = false;
	}
	for (int i=0; i<W+1; i++)
		s[0][i] = 0;
	//1:递推计算
	for (int i=1; i<n+1; i++) 
		for (int j=1; j<W+1; j++)
			if (j < w[i-1])
				s[i][j] = s[i-1][j];
			else 
				s[i][j] = max(s[i-1][j], 
					s[i-1][j-w[i-1]] + v[i-1]);
	//2:装入的物品搜索
	int j=W;
	for (int i=n; i>0; i--)
		if (s[i][j] > s[i-1][j]) {
			x[i-1] = true;
			j -= w[i-1];
		}
	va = s[n][W];
	wa = 0;
	for (int i=0; i<n; i++)
		if (x[i])
			wa += w[i];
	if (verbose)
		printDetail(s, n, W);
	delete2DArr(s, n+1);
}
void printDetail(int **s, int n, int W)
{
	printf("递推矩阵：\n");
	printf("  ");
	for (int i=0; i<W+1; i++)
		printf("%3d", i);
	printf("\n");
	for (int i=0; i<n+1; i++) {
		printf("%2d", i);
		for (int j=0; j<W+1; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}
void printResult(int &W, int *w, int *v, 
	bool *x, int &wa, int &va, int n)
{
	printf("物品及装包情况：\n");
	printf("No");
	for (int i=0; i<n; i++)
		printf("%3d", i+1);
	printf("\n");
	printf(" w");
	for (int i=0; i<n; i++)
		printf("%3d", w[i]);
	printf("\n");
	printf(" v");
	for (int i=0; i<n; i++)
		printf("%3d", v[i]);
	printf("\n");
	printf(" x");
	for (int i=0; i<n; i++)
		printf("%3d", x[i]);
	printf("\n");
	printf("背包容量：%d\n", W);
	printf("装入物品总重量：%d\n", wa);
	printf("装入物品总价值：%d\n", va);
}
//p191-2
void testKnapsackDPEx6_6()
{
	int w[] = {2, 2, 6, 5, 4};
	int v[] = {6, 3, 5, 4, 6};
	int n = 5;
	bool *x = new bool[n];
	int W = 10;
	int va=0, wa=0;
	printf("Knapsack的DP算法测试(Ex6-5)...\n");
	KnapsackDP(w, v, n, W, x, wa, va, true);
	printResult(W, w, v, x, wa, va, n);
	delete x;
}
void testKnapsackDP(int n)
{
	int *w = new int[n];
	int *v = new int[n];
	bool *x = new bool[n];
	randRangeArr(n, 1, 5, w);
	randRangeArr(n, 1, 9, v);
	int W = 0;
	for (int i=0; i<n; i++)
		W += w[i];
	W = 2*W/3;
	int va=0, wa=0;
	printf("Knapsack的DP算法测试(Ex6-5)...\n");
	KnapsackDP(w, v, n, W, x, wa, va, true);
	printResult(W, w, v, x, wa, va, n);
	delete w, v, x;
}