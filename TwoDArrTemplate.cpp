//TwoDArrTemplate.cpp
//二维数组分配与释放—模版函数版
//为2维数组分配空间并初始化
#pragma once
//参数表中必须含有模板类型的参数
//否则将报“未能为Type推导模板参数”(C2783)错误
template <class Type>
Type **new2DArrT(int rows, int cols, Type *x)
{
	Type **a = new Type *[rows];
	for (int i=0; i<rows; i++) 
		a[i] = new Type[cols];
	return a;
}
//释放2维数组
template <class Type>
void delete2DArrT(Type **a, int rows)
{
	for (int i=0; i<rows; i++)
		delete[] a[i];
	delete a;
}
