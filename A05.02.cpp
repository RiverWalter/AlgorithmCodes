//Algorithm 5.2 (P147-8)(A05.02.cpp)
//迪克斯特拉(Dijkstra)最短路径算法
#include "headers.h"
//虚拟的根，用于结束遍历
#define ROOT_V -1
void printH(int n)
{
	printf("No Done    ");
	for (int i=0; i<n; i++)
		printf("d%c ", i+65);
	printf(" t \n");
}
void Dijkstra(ClstoVertex *adjLst, int n, int v,
	int *dist, int *previous, bool verbose = false)
{
	char *s = new char[n+1];
	bool *done = new bool[n];
	for (int i=0; i<n; i++) {
		dist[i] = Inf;
		previous[i] = ROOT_V;
		done[i] = false;
		s[i] = 0;
	}
	s[n] = 0;
	dist[v] = 0;
	int d, u;
	ClstoVertex *vt;
	int doneNum = 0;
	if (verbose)
		printH(n);
	while (doneNum < n) {
		if (verbose) {
		printf("%2d %-8s", doneNum, s);
		for (int i=0; i<n; i++)
			if (done[i])
				printf("%-3c", ' ');
			else if (dist[i] == Inf)
				printf("%-3c", 'x');
			else
				printf("%-3d", dist[i]);
		}
		d = Inf; u = -1;
		for (int i=0; i<n; i++) 
			if (!done[i] && dist[i] < d) {
				d = dist[i]; u = i;
			}
		done[u] = true;
		if (verbose)
			printf(" %c\n", u+65);
		s[doneNum] = u+65;
		doneNum++;
		vt = adjLst[u].next;
		while (vt) {
			if (dist[u] + vt->cost < dist[vt->selfV]) {
				dist[vt->selfV] = dist[u] + vt->cost;
				previous[vt->selfV] = u;
			}
			vt = vt->next;
		}
	}
	delete s, done;
}
void printOnePath(int *previous, bool *b, int last, int startV)
{
	if (previous[last] == ROOT_V)
		printf("%c ", last+65);
	else {
		printOnePath(previous, b, previous[last], startV);
		b[last] = true;
		printf("%c ", last+65);
	}
}
void printDistAndPath(int *dist, int *previous, int n, int startV)
{
	printf("最短距离:\n");
	for (int i=0; i<n; i++)
		printf("%3c", i + 65);
	printf("\n");
	for (int i=0; i<n; i++)
		printf("%3d", dist[i]);
	printf("\n");
	printf("最短路径:\n");
	bool *b = new bool[n];
	for (int i=0; i<n; i++)
		b[i] = false;
	for (int i=n; i>0; i--) {
		if (!b[i]) {
			printOnePath(previous, b, i, startV);
			printf("\n");
		}
	}
	delete b;
}
void DijkstraEx5_3Test()
{
	int n = 0;
	printf("测试Dijkstra算法，Ex5_3...\n");
	int **M = Ex5_3Matrix(n);
	print2DArr(M, n);
	ClstoVertex *adjLst = getAdjList(M, n);
	printAdjList(adjLst, n);
	int *dist = new int[n];
	int *previous = new int[n];
	int startV = 0;
	Dijkstra(adjLst, n, startV, dist, previous, true);
	printDistAndPath(dist, previous, n, startV);
	delete2DArr(M, n);
	delete dist, previous;
}
void DijkstraTest(int n)
{
	printf("测试Dijkstra算法...\n");
	int **M = new2DArr(n, n);
	randMatrix(M, n, 4);
	print2DArr(M, n);
	ClstoVertex *adjLst = getAdjList(M, n);
	printAdjList(adjLst, n);
	int m = DFSTest(adjLst, n);
	if (m > 1) {
		printf("连通分量数不止1个，不能进行测试\n");
		delete2DArr(M, n);
		return;
	}
	int *dist = new int[n];
	int *previous = new int[n];
	int startV = 0;
	Dijkstra(adjLst, n, startV, dist, previous);
	printDistAndPath(dist, previous, n, startV);
	delete2DArr(M, n);
	delete dist, previous;
}