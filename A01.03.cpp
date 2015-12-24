//Algorithm 1.3 (P4)(A01.03.cpp)
//百元买百鸡问题，改进的穷举法
#include "headers.h"
void chickenSolutionATest(int n)
{
	int *g = new int[n];
	int *m = new int[n];
	int *s = new int[n];
	int k = chickenSolutionA(n, g, m, s);
	printf("%d元买%d鸡A:\n", n, n);
	printf("%4s%4s%4s%4s\n", "No", "公", "母", "小");
	for (int i=0; i<k; i++)
		printf("%4d%4d%4d%4d\n", i+1, g[i], m[i], s[i]);
	delete g; delete m; delete s;
}
int chickenSolutionA(int n,int g[],int m[],int s[])
{
	int k = 0;
	int na = n/5;
	int nb = n/3;
	for (int a=0;a<=na;a++) {
		for (int b=0;b<=nb;b++) {
			int c = n - a - b;
			if ((a+b+c==n)&&(c%3==0)&&(5*a+3*b+c/3==n)) {
				g[k] = a;
				m[k] = b;
				s[k] = c;
				k++;
			}
		}
	}
	return k;
}