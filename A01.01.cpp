//Algorithm 1.1(P1-2)(A01.01.cpp)
//ŷ�����(Euclid)���Լ��(GCD)�㷨
//������ԭ����(300 B.C.)��շת�����
//�������㾭������Ԫ3-5����
//��������¡����ؾ��أ�1247
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
	printf("%d��%d�����Լ��(GCD)�ǣ�%d\n",
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