//graph.h
#pragma once
//图的邻接表中的结点类
#include "Kruskal.h"
class ClstoVertex {
public:
	int selfV; //当前结点号
	int cost;  //代价或距离,做头结点时取0
	ClstoVertex *next; //后一个结点
	ClstoVertex(){};
	ClstoVertex(int self, int c, ClstoVertex *n=NULL) {
		set(self, c, n);
	}
	void set(int self, int c, ClstoVertex *n=NULL) {
		selfV = self;
		cost = c;
		next = n;
	}
};

//随机生成图的带权邻接矩阵
int **genGraphMatrix(int n, int allowInf);
//从邻接矩阵创建邻接表
ClstoVertex *getAdjList(int **M, int n);
//从邻接矩阵创建边的集合(数组表示),无向图
ClsKEdge *getEdgeArrUG(int **M, int n, int &m);
//打印图的邻接表
void printAdjList(ClstoVertex *adjLst, int n);
void testAdjList(int n);
