//Algorithm 5.1 (P143-4)(A05.01.cpp)
//�ɷָ��(knapsack)�����̰���㷨
#include "headers.h"
class ClsKnapsackObj 
{
public:
	int volume;  //���
	int value; //��ֵ
	double vaRatio; //��λ����ļ�ֵ
	ClsKnapsackObj(){}
	void set(int vo, int va)
	{
		volume = vo;
		value = va;
		vaRatio = (double)va / vo;
	}
	bool operator < (ClsKnapsackObj &right)
	{
		return vaRatio < right.vaRatio;
	}
};
double knapsackGreedy(ClsKnapsackObj objs[],int n,
	int tVo, double voArr[])
{
	double tva = 0;
	int tvo = tVo;
	for (int i=n-1; i>=0; i--) {
		if (objs[i].volume <= tvo) {
			voArr[i] = 1; 
			tvo -= objs[i].volume;
			tva += objs[i].value;
		}
		else {
			voArr[i] = (double)tvo / objs[i].volume;
			tva += tvo * objs[i].vaRatio;
			break;
		}
	}
	return tva;
}
int initKnapsackObjs(ClsKnapsackObj *objs, int n)
{
	int V=0;
	for (int i=0; i<n; i++) {
		objs[i].set(randRange(1,20), randRange(1,20));
		V += objs[i].volume;
	}
	return V;
}
void printKnapsackData(ClsKnapsackObj *objs, int n)
{
	printf("Obj No");
	for (int i=0; i<n; i++)
		printf("%6d", i+1);
	printf("\n");
	printf("Volume");
	for (int i=0; i<n; i++)
		printf("%6d", objs[i].volume);
	printf("\n");
	printf("Value ");
	for (int i=0; i<n; i++)
		printf("%6d", objs[i].value);
	printf("\n");
	printf("Ratio ");
	for (int i=0; i<n; i++)
		printf("%6.2lf", objs[i].vaRatio);
	printf("\n");
}
void knapsackGreedyTest(int n)
{
	printf("���Կɷָ��(knapsack)�����̰���㷨...\n");
	ClsKnapsackObj *objs = new ClsKnapsackObj[n];
	int Vt = initKnapsackObjs(objs, n);
	printf("ԭʼ��Ʒ��\n");
	printKnapsackData(objs, n);
	mergeSortRT <ClsKnapsackObj> (objs,0,n-1);
	printf("����λ��ֵ����\n");
	printKnapsackData(objs, n);
	int V = randRange(Vt/3, Vt);
	double *voArr = new double[n];
	for (int i=0; i<n; i++)
		voArr[i] = 0;
	double Va = knapsackGreedy(objs, n, V, voArr);
	printf("���Ϊ%d�ı�������װ�¼�ֵΪ%5.2lf����Ʒ��\n",
		V, Va);
	printf("�������Ϊ��\n");
	printf("Vols  ");
	for (int i=0; i<n; i++)
		printf("%6.2lf", voArr[i]*objs[i].volume);
	printf("\n");
	printf("Values");
	for (int i=0; i<n; i++)
		printf("%6.2lf", voArr[i]*objs[i].volume*objs[i].vaRatio);
	printf("\n");
	delete objs;
	delete voArr;
}