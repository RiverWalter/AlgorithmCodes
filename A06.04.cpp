//Algorithm 6.04 (P189-90)(A06.04.cpp)
//最长公共子序列的动态规划算法
//Longest common subsequence problem
#include "headers.h"
void printDetail(int **L, int **s, int n, int m);
char *LCSSDP(char *A, char *B, bool verbose = false)
{
	int n = strlen(A);
	int m = strlen(B);
	int **L = new2DArr(n+1, m+1);
	int **s = new2DArr(n+1, m+1);
	char *C = new char[min(n, m) + 1];
	//0:初始化
	for (int i=0; i<n+1; i++)
		L[i][0] = 0;
	for (int i=0; i<m+1; i++)
		L[0][i] = 0;
	//1:长度与状态计算
	for (int i=1; i<n+1; i++) 
		for (int j=1; j<m+1; j++) {
			if (A[i-1] == B[j-1]) {
				L[i][j] = L[i-1][j-1] + 1;
				s[i][j] = 1;
			} else if (L[i-1][j] >= L[i][j-1]) {
				L[i][j] = L[i-1][j];
				s[i][j] = 2;
			} else {
				L[i][j] = L[i][j-1];
				s[i][j] = 3;
			}
		}
	//2:序列搜索
	int i, j, len, k;
	i=n; j=m; len=L[n][m]; k=len;
	C[len] = 0;
	while (i != 0 && j != 0) {
		switch (s[i][j]) {
		case 1: 
			k--; i--; j--;
			C[k] = A[i];
			break;
		case 2:
			i--; break;
		case 3:
			j--; break;
		}
	}
	if (verbose)
		printDetail(L, s, n, m);
	delete2DArr(L, n+1);
	delete2DArr(s, n+1);
	return C;
}
void printDetail(int **L, int **s, int n, int m)
{
	printf("长度矩阵：\n");
	printf("  ");
	for (int i=0; i<m+1; i++)
		printf("%3d", i);
	printf("\n");
	for (int i=0; i<n+1; i++) {
		printf("%2d", i);
		for (int j=0; j<m+1; j++)
			printf("%3d", L[i][j]);
		printf("\n");
	}
	printf("状态矩阵：\n");
	printf("  ");
	for (int i=0; i<m+1; i++)
		printf("%3d", i);
	printf("\n");
	for (int i=0; i<n+1; i++) {
		printf("%2d", i);
		for (int j=0; j<m+1; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}
//p188
void testLCSSDPEx6_5()
{
	char *s1 = "xyxzyxyzzy";
	char *s2 = "xzyzxyzxyzxy";
	char *s = LCSSDP(s1, s2, true);
	printf("最长公共子序列的DP算法测试(Ex6-4)...\n");
	printf("原始序列：\n");
	printf("%s\n%s\n", s1, s2);
	printf("结果：%s, 长度：%d\n", s, strlen(s));
	delete s;
}
void genStrings(int chars, char *s1, char *s2)
{
	for (int i=0; i<strlen(s1); i++)
		s1[i] = randRange(0, chars-1)+65;
	for (int i=0; i<strlen(s2); i++)
		s2[i] = randRange(0, chars-1)+65;
}
void testLCSSDP(int chars, int lenA, int lenB)
{
	char *s1 = (char *)malloc(lenA+1);
	char *s2 = (char *)malloc(lenB+1);
	memset(s1, '*', lenA);
	memset(s2, '*', lenB);
	s1[lenA+1] = 0;
	s2[lenB+1] = 0;
	genStrings(chars, s1, s2);
	char *s = LCSSDP(s1, s2, true);
	printf("最长公共子序列的DP算法测试...\n");
	printf("原始序列：\n");
	printf("%s\n%s\n", s1, s2);
	printf("结果：%s, 长度：%d\n", s, strlen(s));
	delete s, s1, s2;
}