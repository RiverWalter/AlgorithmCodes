//headers.h, 所有头文件
#pragma once
#define Inf SHRT_MAX

#include <list>
#include <set>
using namespace std;

#include <stdio.h>
#include <time.h>
//time_t time(time_t * _Time)
/*
此函数会返回从公元1970年1月1日的UTC时间
从0时0分0秒算起到现在所经过的秒数。
如果t为非空指针，此函数也会将返回值存到t指针所指的内存。
返回值：
成功则返回秒数，失败则返回((time_t)-1)值，错误原因存于errno中。
*/

#include <stdlib.h>
//void srand(unsigned int _Seed);
//初始化随机数发生器，即设置种子
//int rand(void);
//返回0到RAND_MAX (32767)之间的随机数. 

#include "algorithms.h"
#include "graph.h"
#include "data.h"
#include "Kruskal.h"
#include "RandomNumber.h"
#include "utilities.h"
#include "others.h"

#include "TSPDP.h"

//MergeSort.cpp
//合并排序—模板函数版
#include "MergeSortT.cpp"
//heapT.cpp
//堆操作—模板函数版
#include "heapT.cpp"
//TwoDArrTemplate.cpp
//二维数组分配与释放—模版函数版
#include "TwoDArrTemplate.cpp"
