//Algorithm 4.3 (P84-5)(A04.03.cpp)
//�ݺ�����logn�㷨
#include "headers.h"
long power(long a, int b)
{
	if (b == 1)
		return a;
	else {
		long x = power(a, b/2);
		x *= x;
		if (b % 2)
			x *= a;
		return x;
	}
}
void powerTest(int a, int b)
{
	printf("�����ݺ���logn�㷨:\n");
	printf("%d^%d=%ld\n", a, b, power(a, b));
}