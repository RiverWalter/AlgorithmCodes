//Algorithm 4.1 (P83)(A04.01.cpp)
//�ݹ鷨��׳�
#include "headers.h"
long factorial(int n)
{
	if (n==0)
		return 1L;
	else
		return n * factorial(n-1);
}
void factorialTest(int n)
{
	printf("�ݹ鷨��׳ˣ�\n");
	printf("%d!=%ld\n", n, factorial(n));
}