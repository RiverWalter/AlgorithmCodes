//Algorithm 4.3 (P84-5)(A04.03.cpp)
//幂函数的logn算法
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
	printf("测试幂函数logn算法:\n");
	printf("%d^%d=%ld\n", a, b, power(a, b));
}