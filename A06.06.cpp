//Algorithm 6.06 (P196-8)(A06.06.cpp)
//RNA�������ƥ��Ķ�̬�滮�㷨
#include "headers.h"
#define GAP 5
void printDetail(char *R, int **L, int **s, int n);
int RNADP(char *R, list<pair<int, int>*> &RNAPairs,
	bool verbose = false)
{
	int n = strlen(R);
	int **L = new2DArr(n-GAP+1, n);
	int **s = new2DArr(n-GAP+1, n);
	list<pair<int, int>*> stackx;
	//0:��ʼ��
	for (int i=0; i<n-GAP+1; i++)
		for (int j=0; j<n; j++) {
			L[i][j] = 0;
			s[i][j] = -1;
		}
	//1:ƥ������״̬����
	int i, j, len, len1, temp;
	for (int k=GAP; k<=n-1; k++) 
	for (i=0; i<n-k; i++) {
		j = i+k; len = 0; temp = i;
		//��i-j��������jƥ���t
		for (int t=i; t<j-GAP+1; t++) {
			if (R[t] == 'A' && R[j] == 'U' ||
				R[t] == 'U' && R[j] == 'A' ||
				R[t] == 'C' && R[j] == 'G' ||
				R[t] == 'G' && R[j] == 'C') {
				if (i==t)
					len1 = L[i+1][j-1]+1;
				else 
					len1 = L[i][t-1]+L[t+1][j-1]+1;
				//6.7.3: ����t�����ƥ����
				if (len < len1) {
					len = len1; temp = t;
				}
			}
		} //for t
		//6.7.4: ����i�����ƥ����
		if (len > L[i][j-1]) {
			L[i][j] = len;
			s[i][j] = temp;
		} else {
			L[i][j] = L[i][j-1];
			s[i][j] = -1;
		}
	} //for i, for k
	//2:ƥ�������
	pair<int, int> *p;
	stackx.push_back(new pair<int, int>(0, n-1));
	while (!stackx.empty()) {
		p = stackx.back();
		stackx.pop_back();
		i = p->first; j = p->second;
		delete p;
		while (L[i][j]>0) {
			if (s[i][j] == -1) j--;
			else {
				//�ҵ�һ�������
				RNAPairs.push_back(
					new pair<int, int>(s[i][j], j));
				//���з�Ϊ����������
				//��1�����н�վ
				if (s[i][j]-1-i>=GAP)
					stackx.push_back(
					new pair<int,int>(i, s[i][j]-1));
				i = s[i][j]+1; j--;
			}
		} //�ڲ�while
	} //���while
	if (verbose)
		printDetail(R, L, s, n);
	j = L[0][n-1];
	delete2DArr(L, n-GAP+1);
	delete2DArr(s, n-GAP+1);
	return j;
}
void printDetail(char *R, int **L, int **s, int n)
{
	printf("ƥ��������\n");
	printf("  ");
	for (int i=0; i<n; i++)
		printf("%3c", R[i]);
	printf("\n");
	printf("  ");
	for (int i=0; i<n; i++)
		printf("%3d", i);
	printf("\n");
	for (int i=0; i<n-GAP+1; i++) {
		printf("%2d", i);
		for (int j=0; j<i+GAP-1; j++)
			printf("   ");
		for (int j=i+GAP-1; j<n; j++)
			printf("%3d", L[i][j]);
		printf("\n");
	}
	printf("״̬����\n");
	for (int i=0; i<n; i++)
		printf("%3c", R[i]);
	printf("\n");
	printf("  ");
	for (int i=0; i<n; i++)
		printf("%3d", i);
	printf("\n");
	for (int i=0; i<n-GAP+1; i++) {
		printf("%2d", i);
		for (int j=0; j<i+GAP-1; j++)
			printf("   ");
		for (int j=i+GAP-1; j<n; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}
void printMatch(char *RNA, 
	list<pair<int, int>*> &RNAPairs)
{
	printf("ƥ�������%d\n", RNAPairs.size());
	printf("ƥ��ԣ�\n");
	list<pair<int, int>*>::iterator it;
	int i,j,k=0;
	for (it=RNAPairs.begin(); 
		it!=RNAPairs.end(); it++) {
			i = (*it)->first;
			j = (*it)->second;
			printf("%c(%d)-%c(%d), ",
				RNA[i], i, RNA[j], j);
			k++;
			if (!(k%4)) printf("\n");
	}
	printf("\n");
}
//p196
void testRNADPEx6_7()
{
	//p195-6, ͼ6.9, ��6.7
	//char *RNA = "ACAUGAUGGCCAUGU";
	/*
	�������15
	ƥ�������5
	ƥ��ԣ�
	A(0)-U(14), C(1)-G(13), A(2)-U(12), U(3)-A(11),
	G(4)-C(9) */
	//P194, ͼ6.8
	char *RNA = "ACGUCGAUUCGAGCGAAUCGUAAC"
		"GAUACGAGCAUAGCGGCUUGAC";
	/*
	�������46
	ƥ�������14
	ƥ��ԣ�
	A(0)-U(42), A(30)-U(41), G(31)-C(40), C(32)-G(38)
	C(1)-G(29), G(2)-C(28), U(3)-A(25), C(4)-G(24),
	G(5)-C(23), U(7)-A(22), U(8)-A(21), C(9)-G(19),
	G(10)-C(18), A(11)-U(17)*/
	list<pair<int, int>*> RNAPairs;
	RNADP(RNA, RNAPairs, true);
	//printf("RNA�������ƥ���DP�㷨����(Ex6-7)\n");
	printf("RNA�������ƥ���DP�㷨����(ͼ6-8)\n");
	printf("ԭʼ���У�%s\n", RNA);
	printf("�������%d\n", strlen(RNA));
	printMatch(RNA, RNAPairs);
	//�ͷ���Դ
	pair<int, int>* p;
	while (!RNAPairs.empty()) {
		p = RNAPairs.back();
		RNAPairs.pop_back();
		delete p;
	}
}
char *genRNA(int n)
{
	char *Rs = "AGCU";
	int *RNAi = new int[n];
	randRangeArr(n, 0, 3, RNAi);
	char *RNA = new char[n+1];
	for (int i=0; i<n; i++)
		RNA[i] = Rs[RNAi[i]];
	RNA[n] = 0;
	delete RNAi;
	return RNA;
}
void testRNADP(int n)
{
	char *RNA = genRNA(n);
	list<pair<int, int>*> RNAPairs;
	RNADP(RNA, RNAPairs, true);
	printf("RNA�������ƥ���DP�㷨����\n");
	printf("ԭʼ���У�%s\n", RNA);
	printf("�������%d\n", strlen(RNA));
	printMatch(RNA, RNAPairs);
	//�ͷ���Դ
	pair<int, int>* p;
	while (!RNAPairs.empty()) {
		p = RNAPairs.back();
		RNAPairs.pop_back();
		delete p;
	}
	delete RNA;
}