//Algorithm 9.0 (P267)(A09.00.cpp)
//random number generator by Linear Congruential Method
//����ͬ�෨����α�����
#include "headers.h"
#define MULTIPLIER 0x015A4E35L
#define INCREMENT 1
static unsigned long seed;
void random_seed9(unsigned long d)
{
	if (d==0)
		seed = (unsigned long)time(0);
	else
		seed = d;
}
unsigned int random9(unsigned long low,unsigned long high)
{
	seed = MULTIPLIER * seed + INCREMENT;
	return ((seed >> 16) % (high - low) + low);
}
void random9Test(int n, int low, int high)
{
	random_seed9(0);
	printf("����ͬ�෨(random9����)�������������\n");
	printf("��Χ��[%d,%d]���%d�������\n", low, high, n);
	for (int i=0; i<n; i++)
		printf("%3d:%d\n",i+1, random9(low, high+1));
}