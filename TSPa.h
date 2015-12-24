//TSPa.h
//��̬�滮�йصĺ�������
#pragma once
//SubSets.cpp
void testPowerOfTwo(int n);
void testBitCounter(int n);
void testClsSubSetNode(int n);

class ClsSubSetNode {
public:
	int setSize;
	int subSetNo;
	int dist;
	ClsSubSetNode(){subSetNo = -1};
	void set(int aSetSize, int aSubSetNo)
	{
		setSize = aSetSize;
		subSetNo = aSubSetNo;
		getElementNum();
		getSubSet();
	}
	//void setBySubSet(list<char> *subSet
	int elementNum;
	list<char> *subSet;
	~ClsSubSetNode()
	{
		if (!subSet) delete subSet;
	};
	void print();
private:
	void getSubSet();
	void getElementNum();
};