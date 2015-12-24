//RandomNumber.cpp
#include "headers.h"

//high-low<RAND_MAX in the following
//Generate random integers to array in the range [low, high]
void randRangeArr(int n, int low, int high, int a[])
{
	for (int i=0; i<n; i++)
		a[i] = randRange(low, high);
}
//Generate random integers to set<int> in the range [low, high]
void randRangeSet(int n, int low, int high, set<int> &randSet)
{
	while (randSet.size() != n)
		randSet.insert(randRange(low, high));
}
//Generate one random integer in the range [low, high],
int randRange(int low, int high)
{
	return rand() % (high - low + 1) + low;
}
//Generate one random real in the range [0, 1) 
double randDbl()
{
	return (double)rand()/(RAND_MAX+1);
}
