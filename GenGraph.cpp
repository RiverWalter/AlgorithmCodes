//GenGraph.cpp
//ͼ��������ɺ���
#include "headers.h"
//�������ͼ�Ĵ�Ȩ�ڽӾ���
int **genGraphMatrix(int n, int allowInf)
{
	int **M = new2DArr(n, n);
	randMatrix(M, n, allowInf);
	return M;
}
//���ڽӾ��󴴽��ڽӱ�
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
//���ڽӾ��󴴽��ߵļ���(�����ʾ),����ͼ
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
//��ӡͼ���ڽӱ�
void printAdjList(ClstoVertex *adjLst, int n)
{
	printf("�ڽӱ�\n");
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
