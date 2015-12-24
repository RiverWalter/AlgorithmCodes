//Algorithm 5.3 (P153-4)(A05.03.cpp)
//��³˹����(Kruskal)��С�����������㷨
#include "headers.h"
//��ɢ���͵�Find����
//Algorithm 3.15, P78
ClsKNode *DSFind(ClsKNode *V, int k)
{
	ClsKNode *v = &V[k];
	while (v->parent != NULL)
		v = v->parent;
	return v;
}
//��ɢ���͵�Union����
//Algorithm 3.16, P78
ClsKNode *DSUnion(ClsKNode *u, ClsKNode *v)
{
	if (u->rank <= v->rank) {
		u->parent = v;
		if (u->rank == v->rank)
			v->rank++;
		u = v;
	} else v->parent = u;
	return u;
}
void Kruskal(ClsKEdge E[], ClsKEdge T[], int Vs, int Es)
{
	ClsKEdge e;
	ClsKNode *u,*v;
	makeHeapMinT(E, Es);
	ClsKNode *V = new ClsKNode[Vs];
	for (int i=0; i<Vs; i++) 
		V[i].set(i, 0, NULL);
	int j = 0;
	while ((j < Vs-1) && (Es > 0)) {
		e = deleteTopMinT(E, Es);
		u = DSFind(V, e.u);
		v = DSFind(V, e.v);
		if (u!=v) {
			DSUnion(u, v);
			T[j++] = e;
		}
	}
}
//��ӡKruskal�㷨�����ע�⣺ֻ��n-1����
void printKruskal(ClsKEdge *T, int n)
{
	printf("Kruskal�㷨�����\n");
	printf("No: u v cost\n");
	int t = 0;
	for (int i=0; i<n-1; i++) {
		t += T[i].cost;
		printf("%2d  %c %c %2d\n",
			i+1, T[i].u+65, T[i].v+65, T[i].cost);
	}
	printf("The minimum spanning tree cost: %d\n", t);
}
void KruskalEx5_4Test()
{
	int n = 0;
	printf("����Kruskal�㷨��Ex5_4...\n");
	int **M = Ex5_4Matrix(n);
	print2DArr(M, n);
	int m = 0;
	ClsKEdge *E = getEdgeArrUG(M, n, m);
	ClsKEdge *T = new ClsKEdge[n];
	Kruskal(E, T, n, m);
	printKruskal(T, n);
	delete2DArr(M, n);
	delete E, T;
}
void KruskalTest(int n)
{
	printf("����Kruskal�㷨...\n");
	int **M = new2DArr(n, n);
	randMatrix(M, n, 4);
	print2DArr(M, n);
	int m = 0;
	ClsKEdge *E = getEdgeArrUG(M, n, m);
	ClsKEdge *T = new ClsKEdge[n];
	Kruskal(E, T, n, m);
	printKruskal(T, n);
	delete2DArr(M, n);
	delete E, T;
}