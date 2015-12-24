//Algorithm 1.1(P1-2)(A01.01.cpp)
//欧几里德(Euclid)最大公约数(GCD)算法
//《几何原本》(300 B.C.)，辗转相除法
//《孙子算经》，公元3-5世纪
//《数书九章》，秦九韶，1247
#include "headers.h"
void euclidGCDTest(int n, bool verbose)
{
	for (int i=0; i<n; i++)
		euclidGCDTest(verbose);
}
void euclidGCDTest(bool verbose)
{
	int m = randRange(2, 100);
	int n = randRange(2, 100);
	euclidGCDTest(m, n, verbose);
}
void euclidGCDTest(int m, int n, bool verbose)
{
	int r = euclidGCD(m, n, verbose);
	printf("%d和%d的最大公约数(GCD)是：%d\n",
		m, n, r);
}
int euclidGCD(int m, int n, bool verbose)
{
	if (verbose)
		printf("%4d%4d\n", m, n);
	int r;
	do {
		r = m % n;
		m = n;
		n = r;
		if (verbose)
			printf("%4d%4d\n", m, n);
	} while(r);
	return m;
}