//Algorithm 1.2 (P3-4)(A01.02.cpp)
//��Ԫ��ټ����⣬��ٷ�
#include "headers.h"
void chickenSolutionTest(int n)
{
	int *g = new int[n];
	int *m = new int[n];
	int *s = new int[n];
	int k = chickenSolution(n, g, m, s);
	printf("%dԪ��%d��:\n", n, n);
	printf("%4s%4s%4s%4s\n", "No", "��", "ĸ", "С");
	for (int i=0; i<k; i++)
		printf("%4d%4d%4d%4d\n", i+1, g[i], m[i], s[i]);
	delete g; delete m; delete s;
}
int chickenSolution(int n,int g[],int m[],int s[])
{
	int k = 0;
	for (int a=0;a<=n;a++) {
		for (int b=0;b<=n;b++) {
			for (int c=0;c<=n;c++) {
				if ((a+b+c==n)&&(c%3==0)&&(5*a+3*b+c/3==n)) {
					g[k] = a;
					m[k] = b;
					s[k] = c;
					k++;
				}
			}
		}
	}
	return k;
}