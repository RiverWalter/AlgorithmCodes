//TwoDArrTemplate.cpp
//��ά����������ͷš�ģ�溯����
//Ϊ2ά�������ռ䲢��ʼ��
#pragma once
//�������б��뺬��ģ�����͵Ĳ���
//���򽫱���δ��ΪType�Ƶ�ģ�������(C2783)����
template <class Type>
Type **new2DArrT(int rows, int cols, Type *x)
{
	Type **a = new Type *[rows];
	for (int i=0; i<rows; i++) 
		a[i] = new Type[cols];
	return a;
}
//�ͷ�2ά����
template <class Type>
void delete2DArrT(Type **a, int rows)
{
	for (int i=0; i<rows; i++)
		delete[] a[i];
	delete a;
}
