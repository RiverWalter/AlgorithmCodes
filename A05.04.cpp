//Algorithm 5.4 (P156-7)(A05.04.cpp)
//普里姆(Prim)最小花费生成树算法
#include "headers.h"
void Prim(int **M, int n, ClsKEdge *T)
{
	bool *s = new bool[n];
	int *nb = new int[n]; //近邻
	int *w = new int[n];
	s[0] = true;
	//初始化，所有其它结点均有唯一的最近邻0
	//但距离有可能是Inf
	for (int i=1; i<n; i++) {
		w[i] = M[0][i];
		nb[i] = 0;
		s[i] = false;
	}
	int t, u; 
	for (int i=1; i<n; i++) {
		t = Inf;
		//找出当前两个结点子集间的最小代价边
		for (int j=1; j<n; j++)
			if (!s[j] && w[j]<t) {
				u = j; t = w[j];
			}
		T[i-1].set(nb[u], u, w[u]);
		s[u] = true; //此结点已进入树中
		//用新入树的结点更新两个结点子集间的各最小代价边
		for (int j=1; j<n; j++)
			if (!s[j] && M[u][j]<w[j]) {
				w[j] =  M[u][j];
				nb[j] = u;
			}
	}
	delete s,nb,w;
}
//打印Prim算法结果，注意：只有n-1条边
void printPrim(ClsKEdge *T, int n)
{
	printf("Prim算法结果：\n");
	printf("No: u v cost\n");
	int t = 0;
	for (int i=0; i<n-1; i++) {
		t += T[i].cost;
		printf("%2d  %c %c %2d\n",
			i+1, T[i].u+65, T[i].v+65, T[i].cost);
	}
	printf("The minimum spanning tree cost: %d\n", t);
}
void PrimEx5_4Test()
{
	int n = 0;
	printf("测试Prim算法，Ex5_4...\n");
	int **M = Ex5_4Matrix(n);
	print2DArr(M, n);
	ClsKEdge *T = new ClsKEdge[n];
	Prim(M, n, T);
	printPrim(T, n);
	delete2DArr(M, n);
	delete T;
}
void PrimTest(int n)
{
	printf("测试Prim算法...\n");
	int **M = new2DArr(n, n);
	randMatrix(M, n, 4);
	print2DArr(M, n);
	ClsKEdge *T = new ClsKEdge[n];
	Prim(M, n, T);
	printPrim(T, n);
	delete2DArr(M, n);
	delete T;
}
