//graph.h
#pragma once
//ͼ���ڽӱ��еĽ����
#include "Kruskal.h"
class ClstoVertex {
public:
	int selfV; //��ǰ����
	int cost;  //���ۻ����,��ͷ���ʱȡ0
	ClstoVertex *next; //��һ�����
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

//�������ͼ�Ĵ�Ȩ�ڽӾ���
int **genGraphMatrix(int n, int allowInf);
//���ڽӾ��󴴽��ڽӱ�
ClstoVertex *getAdjList(int **M, int n);
//���ڽӾ��󴴽��ߵļ���(�����ʾ),����ͼ
ClsKEdge *getEdgeArrUG(int **M, int n, int &m);
//��ӡͼ���ڽӱ�
void printAdjList(ClstoVertex *adjLst, int n);
void testAdjList(int n);
