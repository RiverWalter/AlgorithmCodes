//GenGraph.cpp
//图的随机生成函数
#include "headers.h"
//随机生成图的带权邻接矩阵
int **genGraphMatrix(int n, int allowInf)
{
	int **M = new2DArr(n, n);
	randMatrix(M, n, allowInf);
	return M;
}
//从邻接矩阵创建邻接表
ClstoVertex *getAdjList(int **M, int n)
{
	ClstoVertex *adjLst = new ClstoVertex[n];
	ClstoVertex *vp;
	for (int i=0; i<n; i++) {
		adjLst[i].set(-1, i, 0);
		vp = &adjLst[i];
		for (int j=0; j<n; j++) {
			if (j == i || M[i][j]==Inf)
				continue;
			vp->next = new ClstoVertex(j, M[i][j]);
			vp = vp->next;
		}
	}
	return adjLst;
}
//从邻接矩阵创建边的集合(数组表示),无向图
ClsKEdge *getEdgeArrUG(int **M, int n, int &m)
{
	m = 0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (M[i][j] != Inf)
				m++;
	ClsKEdge *e = new ClsKEdge[m];
	int k = 0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (M[i][j] != Inf)
				e[k++].set(i, j, M[i][j]);
	return e;
}
//打印图的邻接表
void printAdjList(ClstoVertex *adjLst, int n)
{
	printf("邻接表：\n");
	ClstoVertex *v;
	for (int i=0; i<n; i++) {
		printf("%c: ", i+65);
		v = adjLst[i].next;
		while (v) {
			printf("%c(%d) ", v->selfV+65, v->cost);
			v = v->next;
		}
		printf("\n");
	}
}
void testAdjList(int n)
{
	int **M = genGraphMatrix(n, 4);
	print2DArr(M, n);
	ClstoVertex *adjLst = getAdjList(M, n);
	printAdjList(adjLst, n);
	delete adjLst;
	delete2DArr(M, n);
}
