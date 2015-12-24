//Algorithm 10.1 (P286-7)(A10.01.cpp)
//图的深度优先搜索算法
#include "headers.h"
void DFS(int v,ClstoVertex *adjLst,int n,
	int pren[],int postn[],bool b[],
	int &precnt,int &postcnt,int tra[],int &cnt)
{
	ClstoVertex *p;
	b[v] = true; 
	tra[cnt++] = v;
	pren[v] = ++precnt;
	p = adjLst[v].next;
	while (p != NULL) {
		if (!b[p->selfV])
			DFS(p->selfV, adjLst, n, pren, postn, b, 
				precnt, postcnt, tra, cnt);
		p = p->next;
	}
	postn[v] = ++postcnt;
}
//返回连通分量数
int traverseDFS(ClstoVertex *adjLst,int n,
	int pren[],int postn[],int tra[], int trb[])
{
	int m = 0;
	int precnt=0,postcnt=0,cnt=0;
	bool *b = new bool[n];
	for (int i=0; i<n; i++)
		b[i] = false;
	for (int i=0; i<n; i++)
		if (!b[i]) {
			trb[m++] = i;
			DFS(i, adjLst, n, pren, postn, b,
				precnt, postcnt, tra, cnt);
		}
	delete b;
	return m;
}
void printDFS(int n, int *pren, int *postn, 
	int *tra, int *trb, int m)
{
	printf("深度优先搜索结果:\n");
	printf("连通分量数: %d\n", m);
	int j = 0;
	for (int i=0; i<m; i++) {
		printf("连通分量: %d\n", i+1);
		int next = i == m-1 ? -1 : trb[i+1];
		while (j < n && tra[j] != next) {
			printf("%c ", tra[j]+65);
			j++;
		}
		printf("\n");
	}
}
//返回连通分量数
int DFSTest(ClstoVertex *adjLst, int n)
{
	//调用DFS准备
	int *pren = new int[n]; 
	int *postn = new int[n];
	int *tra = new int[n];
	//记录连通分量数
	int *trb = new int[n];
	for (int i=0; i<n; i++)
		trb[i] = -1;
	int m = traverseDFS(adjLst, n, pren,postn,tra,trb);
	printDFS(n, pren, postn, tra, trb, m);
	//释放动态申请的变量
	delete pren, postn, tra, trb;
	return m;
}
void traverseDFSTest(int n, int nInf)
{
	//初始化图
	int **M = genGraphMatrix(n, nInf);
	print2DArr(M, n);
	ClstoVertex *adjLst = getAdjList(M, n);
	printAdjList(adjLst, n);
	DFSTest(adjLst, n);
	//释放动态申请的变量
	delete adjLst;
	delete2DArr(M, n);
}