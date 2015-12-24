//Algorithm 10.1 (P286-7)(A10.01.cpp)
//ͼ��������������㷨
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
//������ͨ������
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
	printf("��������������:\n");
	printf("��ͨ������: %d\n", m);
	int j = 0;
	for (int i=0; i<m; i++) {
		printf("��ͨ����: %d\n", i+1);
		int next = i == m-1 ? -1 : trb[i+1];
		while (j < n && tra[j] != next) {
			printf("%c ", tra[j]+65);
			j++;
		}
		printf("\n");
	}
}
//������ͨ������
int DFSTest(ClstoVertex *adjLst, int n)
{
	//����DFS׼��
	int *pren = new int[n]; 
	int *postn = new int[n];
	int *tra = new int[n];
	//��¼��ͨ������
	int *trb = new int[n];
	for (int i=0; i<n; i++)
		trb[i] = -1;
	int m = traverseDFS(adjLst, n, pren,postn,tra,trb);
	printDFS(n, pren, postn, tra, trb, m);
	//�ͷŶ�̬����ı���
	delete pren, postn, tra, trb;
	return m;
}
void traverseDFSTest(int n, int nInf)
{
	//��ʼ��ͼ
	int **M = genGraphMatrix(n, nInf);
	print2DArr(M, n);
	ClstoVertex *adjLst = getAdjList(M, n);
	printAdjList(adjLst, n);
	DFSTest(adjLst, n);
	//�ͷŶ�̬����ı���
	delete adjLst;
	delete2DArr(M, n);
}