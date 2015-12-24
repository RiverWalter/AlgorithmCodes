//TSPDP.h
//TSP动态规划法有关的类和函数声明
#pragma once
#include <list>
using namespace std;
class ClsTSPDPNode {
public:
	list<int> *path;
	int dist;
	ClsTSPDPNode()
	{
		path = new list<int>();
		dist = -1;
	}
	~ClsTSPDPNode()
	{ 
		delete path; 
	}
	void set(int cityNo, int aDist)
	{
		path->push_front(cityNo);
		dist = aDist;
	}
	//检测cityNo是否在path中
	bool check(char cityNo)
	{
		bool b = false;
		list<int>::iterator it;
		for (it = path->begin(); it != path->end(); it++)
			if (*it == cityNo) {
				b = true;
				break;
			}
		return b;
	}
	//获取首个cityNo
	int firstCityNo()
	{
		int cityNo = -1;
		if (!path->empty())
			cityNo = path->front();
		return cityNo;
	}
};
