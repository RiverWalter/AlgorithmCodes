//headers.h, ����ͷ�ļ�
#pragma once
#define Inf SHRT_MAX

#include <list>
#include <set>
using namespace std;

#include <stdio.h>
#include <time.h>
//time_t time(time_t * _Time)
/*
�˺����᷵�شӹ�Ԫ1970��1��1�յ�UTCʱ��
��0ʱ0��0������������������������
���tΪ�ǿ�ָ�룬�˺���Ҳ�Ὣ����ֵ�浽tָ����ָ���ڴ档
����ֵ��
�ɹ��򷵻�������ʧ���򷵻�((time_t)-1)ֵ������ԭ�����errno�С�
*/

#include <stdlib.h>
//void srand(unsigned int _Seed);
//��ʼ�������������������������
//int rand(void);
//����0��RAND_MAX (32767)֮��������. 

#include "algorithms.h"
#include "graph.h"
#include "data.h"
#include "Kruskal.h"
#include "RandomNumber.h"
#include "utilities.h"
#include "others.h"

#include "TSPDP.h"

//MergeSort.cpp
//�ϲ�����ģ�庯����
#include "MergeSortT.cpp"
//heapT.cpp
//�Ѳ�����ģ�庯����
#include "heapT.cpp"
//TwoDArrTemplate.cpp
//��ά����������ͷš�ģ�溯����
#include "TwoDArrTemplate.cpp"
