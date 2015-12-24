//RandomNumber.h
#pragma once
#include <set>
//high-low<RAND_MAX in the following
//Generate one random integer in the range [low, high],
int randRange(int low, int high);
//Generate one random real number in the range [0, 1) 
double randDbl();
//Generate random integers to array in the range [low, high]
void randRangeArr(int n, int low, int high, int a[]);
//Generate random integers to set<int> in the range [low, high]
void randRangeSet(int n, int low, int high, set<int> &randSet);
