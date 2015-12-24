//TSPDP.h
//TSP��̬�滮���йص���ͺ�������
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
	//���cityNo�Ƿ���path��
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
	//��ȡ�׸�cityNo
	int firstCityNo()
	{
		int cityNo = -1;
		if (!path->empty())
			cityNo = path->front();
		return cityNo;
	}
};
