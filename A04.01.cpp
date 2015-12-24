//Algorithm 4.1 (P83)(A04.01.cpp)
//µÝ¹é·¨Çó½×³Ë
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
	printf("µÝ¹é·¨Çó½×³Ë£º\n");
	printf("%d!=%ld\n", n, factorial(n));
}