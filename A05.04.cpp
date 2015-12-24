//Algorithm 5.4 (P156-7)(A05.04.cpp)
//����ķ(Prim)��С�����������㷨
#include "headers.h"
void Prim(int **M, int n, ClsKEdge *T)
{
	bool *s = new bool[n];
	int *nb = new int[n]; //����
	int *w = new int[n];
	s[0] = true;
	//��ʼ������������������Ψһ�������0
	//�������п�����Inf
	for (int i=1; i<n; i++) {
		w[i] = M[0][i];
		nb[i] = 0;
		s[i] = false;
	}
	int t, u; 
	for (int i=1; i<n; i++) {
		t = Inf;
		//�ҳ���ǰ��������Ӽ������С���۱�
		for (int j=1; j<n; j++)
			if (!s[j] && w[j]<t) {
				u = j; t = w[j];
			}
		T[i-1].set(nb[u], u, w[u]);
		s[u] = true; //�˽���ѽ�������
		//���������Ľ�������������Ӽ���ĸ���С���۱�
		for (int j=1; j<n; j++)
			if (!s[j] && M[u][j]<w[j]) {
				w[j] =  M[u][j];
				nb[j] = u;
			}
	}
	delete s,nb,w;
}
//��ӡPrim�㷨�����ע�⣺ֻ��n-1����
void printPrim(ClsKEdge *T, int n)
{
	printf("Prim�㷨�����\n");
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
	printf("����Prim�㷨��Ex5_4...\n");
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
	printf("����Prim�㷨...\n");
	int **M = new2DArr(n, n);
	randMatrix(M, n, 4);
	print2DArr(M, n);
	ClsKEdge *T = new ClsKEdge[n];
	Prim(M, n, T);
	printPrim(T, n);
	delete2DArr(M, n);
	delete T;
}
