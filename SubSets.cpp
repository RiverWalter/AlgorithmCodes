//SubSets.cpp,��ȡһ�����ϵ������Ӽ�
#include "headers.h"
//����λ����2^n
int powerOfTwo(int n)
{
	int ret = 1;
	for (int i=1; i<=n; i++)
		ret <<= 1;
	return ret;
}
int bitCounter(int n)
{
	int c = 0;
	for (c=0; n; c++)
		n &= n-1;
	return c;
}
void ClsSubSetNode::getElementNum()
{
	this->elementNum = bitCounter(this->subSetNo);
}
void ClsSubSetNode::getSubSet()
{
	if (!subSet) delete subSet;
	this->subSet = new list<char>();
	int n = this->subSetNo;
	int k;
	for (int i=0; i<this->setSize; i++) {
		k = n & 0x1;
		if (k) this->subSet->push_back(i+65);
		n >>= 1;
		if (!n) break;
	}
}
void ClsSubSetNode::print()
{
	printf("�Ӽ���: %d, Ԫ����: %d, ", 
		this->subSetNo, this->elementNum);
	printf("�Ӽ�: {");
	for (list<char>::iterator it = subSet->begin();
		it != subSet->end(); it++) {
		if (it != subSet->begin())
			printf(",", *it);
		printf("%c", *it);
	}
	printf("}\n");
}
void testPowerOfTwo(int n)
{
	for (int i=0; i<n; i++)
		printf("2^%d=%d\n", i, powerOfTwo(i));
}
void testBitCounter(int n)
{
	for (int i=0; i<n; i++)
		printf("Bits of %d: %d\n", i, bitCounter(i));
}
void testClsSubSetNode(int n)
{
	printf("�г�%d��Ԫ�صļ��ϵ������Ӽ�:\n");
	ClsSubSetNode nd;
	int m = powerOfTwo(n);
	for (int i=0; i<m; i++) {
		nd.set(n, i);
		nd.print();
	}
}