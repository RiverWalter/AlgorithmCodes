//Algorithm 6.00 (P169-70)(A06.00.cpp)
//旅行商问题(TSP)的动态规划算法
#include "headers.h"
void TSPDP(int **cityDist, ClsTSPDPNode **DPArr, int n)
{
	//第一轮，各点到源点的距离
	for (int cityNo=1; cityNo<n; cityNo++) {
		if (cityDist[cityNo][0] != Inf)
			DPArr[0][cityNo].set(cityNo, cityDist[cityNo][0]);
	}
	int firstCityNo;
	int minDist, minPathNo;
	//中间各轮，在前面一轮计算结果的基础上后延路径
	for (int i=1; i<n-1; i++) {
		for (int cityNo=1; cityNo<n; cityNo++) {
			minDist = Inf;
			minPathNo = -1;
			for (int pathNo = 1; pathNo<n; pathNo++) {
				if (!DPArr[i-1][pathNo].path->empty()) 
					if (!DPArr[i-1][pathNo].check(cityNo)) {
						firstCityNo = DPArr[i-1][pathNo].firstCityNo();
						if (cityDist[cityNo][firstCityNo] + 
							DPArr[i-1][pathNo].dist < minDist) {
								minPathNo = pathNo;
								minDist = cityDist[cityNo][firstCityNo] + 
									DPArr[i-1][pathNo].dist;
						}
					}
			}
			//路径后延
			if (minPathNo != -1) {
				DPArr[i][cityNo].path->assign(
					DPArr[i-1][minPathNo].path->begin(),
					DPArr[i-1][minPathNo].path->end());
				DPArr[i][cityNo].set(cityNo, minDist);
			}
		}
	}
	//最后一轮，后延到源点
	minDist = Inf;
	minPathNo = -1;
	int cityNo = 0;
	for (int pathNo = 1; pathNo<n; pathNo++) {
		if (!DPArr[n-2][pathNo].path->empty()) {
			firstCityNo = DPArr[n-2][pathNo].firstCityNo();
			if (cityDist[cityNo][firstCityNo] + 
				DPArr[n-2][pathNo].dist < minDist) {
					minPathNo = pathNo;
					minDist = cityDist[cityNo][firstCityNo] + 
						DPArr[n-2][pathNo].dist;
			}
		}
	}
	//路径后延
	if (minPathNo != -1) {
		DPArr[n-1][cityNo].path->assign(
			DPArr[n-2][minPathNo].path->begin(),
			DPArr[n-2][minPathNo].path->end());
		DPArr[n-1][cityNo].set(cityNo, minDist);
	}
}
void printFinal(ClsTSPDPNode **DPArr, int n)
{
	printf("minDist = %d\n", DPArr[n-1][0].dist);
	printf("min Path: ");
	list<int>::iterator it = DPArr[n-1][0].path->begin();
	for ( ; it != DPArr[n-1][0].path->end(); it++)
		printf("%c ", *it + 65);
	printf("A\n");
}
void printDetail(ClsTSPDPNode **DPArr, int n)
{
	list<int>::iterator it;
	for (int i = 0; i<n; i++) {
		printf("第%d轮：\n", i+1);
		for (int j=0; j<n; j++)
			if (!DPArr[i][j].path->empty()) {
				printf("\t路径#%d：", j+1);
				for (it = DPArr[i][j].path->begin(); 
					it != DPArr[i][j].path->end(); it++)
					printf("%c ", *it + 65);
				printf("\t路径长度：%d\n", DPArr[i][j].dist);
			}
	}
}
void testTSPDPEx6_1()
{
	//初始化距离矩阵
	int n;
	int **cityDist = Ex6_1aMatrix(n);
	//初始化DP数组
	ClsTSPDPNode x;
	ClsTSPDPNode **DPArr = new2DArrT(n, n, &x);
	printf("测试TSP的DP算法(Ex6-1)...\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPDP(cityDist, DPArr, n);
	printf("DP结果：\n");
	printFinal(DPArr, n);
	printf("DP详细：\n");
	printDetail(DPArr, n);
	delete2DArr(cityDist, n);
	delete2DArrT(DPArr, n);
}
void testTSPDP(int n)
{
	//初始化距离矩阵
	int **cityDist = new2DArr(n, n);
	randMatrix(cityDist, n, 3);
	//初始化DP数组
	ClsTSPDPNode x;
	ClsTSPDPNode **DPArr = new2DArrT(n, n, &x);
	printf("测试TSP的DP算法(Ex6-1)...\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPDP(cityDist, DPArr, n);
	printf("DP结果：\n");
	printFinal(DPArr, n);
	printf("DP详细：\n");
	printDetail(DPArr, n);
	delete2DArr(cityDist, n);
	delete2DArrT(DPArr, n);
}
