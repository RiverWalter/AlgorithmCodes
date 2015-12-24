//Algorithm 5.0 (P106-7)(A05.00.cpp)
//TSP�����̰���㷨
#include "headers.h"
void TSPGreedy(int *cityDist[], int n,
	int &minDist, int *minPath)
{
	list<int> cities(n-1);
	list<int>::iterator cityIt, cityItj;
	int i = 1;
	//��0�ų��п�ʼ���������н�����
	for (cityIt=cities.begin(); 
		cityIt != cities.end(); cityIt++) {
		*cityIt = i++;
	}
	minDist = 0;
	minPath[0] = 0;
	int d, k, j;
	for (i=1; i<n; i++) {
		k = minPath[i-1];
		cityItj=cities.begin();
		j = *cityItj; 
		d = cityDist[k][j];
		cityIt = cityItj;
		for (cityIt++; cityIt != cities.end(); cityIt++) {
			if (d > cityDist[k][*cityIt]) {
				cityItj = cityIt;
				j = *cityItj; 
				d = cityDist[k][j];
			}
		}
		minDist += d;
		minPath[i] = j;
		cities.erase(cityItj);
	}
	minDist += cityDist[j][0];
}
void TSPGreedyEx5_2()
{
	/*
	int cityDist0[][5] = {
		{0, 3, 3, 2, 6},
		{3, 0, 7, 3, 2},
		{3, 7, 0, 2, 5},
		{2, 3, 2, 0, 3},
		{6, 2, 5, 3, 0}};
	int n = 5;
	int **cityDist = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cityDist[i][j] = cityDist0[i][j];*/
	int n = 0;
	int **cityDist = Ex5_2Matrix(n);
	int minDist=0;
	int *minPath = new int[n];
	printf("����TSP��̰���㷨...\n");
	printf("֣�ں���5.2����(P141)\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPGreedy(cityDist, n, minDist, minPath);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	printf("\n�ʽ����...\n");
	//��ʼ���������б�
	int *perm = new int[n];
	for (int i=0; i<n; i++)
		perm[i] = i;
	TSPExhaustion(cityDist, 1, n, perm, 
		minDist, minPath, false);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	delete2DArr(cityDist, n);
	delete minPath;
	delete perm;
}
void TSPGreedyTest(int n)
{
	int **cityDist = new2DArr(n, n);
	randMatrix(cityDist, n);
	int minDist=0;
	int *minPath = new int[n];
	printf("����TSP��̰���㷨...\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPGreedy(cityDist, n, minDist, minPath);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	printf("\n�ʽ����...\n");
	//��ʼ���������б�
	int *perm = new int[n];
	for (int i=0; i<n; i++)
		perm[i] = i;
	TSPExhaustion(cityDist, 1, n, perm, 
		minDist, minPath, false);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	delete2DArr(cityDist, n);
	delete minPath;
	delete perm;
}
