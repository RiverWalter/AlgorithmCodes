//Kruskal.h
//Algorithm 5.3 (P153-4)
//克鲁斯卡尔(Kruskal)最小花费生成树算法
#pragma once
class ClsKEdge {
public:
	int u;
	int v;
	int cost;
	ClsKEdge(){};
	ClsKEdge(int au, int av, int acost) {
		set(au, av, acost);
	}
	void set(int au, int av, int acost) {
		u = au;
		v = av;
		cost = acost;
	}
	bool operator < (ClsKEdge &right)
	{
		return cost < right.cost;
	}
	bool operator > (ClsKEdge &right)
	{
		return cost > right.cost;
	}
	ClsKEdge operator = (ClsKEdge &right)
	{
		u = right.u;
		v = right.v;
		cost = right.cost;
		return *this;
	}
};
class ClsKNode {
public:
	int vNo;
	int rank;
	ClsKNode *parent;
	ClsKNode(){};
	ClsKNode(int aVno, int arank, ClsKNode *aparent) {
		set(aVno, arank, aparent);
	}
	void set(int aVno, int arank, ClsKNode *aparent) {
		vNo = aVno;
		rank = arank;
		parent = aparent;
	}
};