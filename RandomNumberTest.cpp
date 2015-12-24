//RandomNumberTest.cpp
#include "headers.h"

void randRangeTest(int n, int low, int high)
{
	printf("%d到%d间的%d个随机数\n", low, high, n);
	for (int i=0; i<n; i++)
		printf("%3d:%d\n",i+1, randRange(low, high));
}
void randRangeSetTest(int n)
{
	set<int> randSet;
	set<int>::iterator it, it1;
	randRangeSet(n, 1, 10, randSet);
	printf("生成[1,10]间的%d个随机数存放在集合中：\n", n);
	for (it = randSet.begin(); it != randSet.end(); it++)
		printf("%d ", *it);
	printf("\n");
	it = randSet.begin();
	it1 = randSet.find(*it);
	printf("%d in set: %d\n", *it, it1 != randSet.end());
	it1 = randSet.find(100);
	printf("%d in set: %d\n", 100, it1 != randSet.end());
}
void randDblTest(int n)
{
	printf("范围在[0,1)间的%d个随机数\n", n);
	for (int i=0; i<n; i++)
		printf("%3d:%lf\n",i+1, randDbl());
}
void randTest(int n)
{
	printf("范围在[0,%d]间的%d个随机数\n", RAND_MAX, n);
	for (int i=0; i<n; i++)
		printf("%3d:%d\n",i+1, rand());
}