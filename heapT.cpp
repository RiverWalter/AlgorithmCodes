//heapT.cpp
//�Ѳ�����ģ�庯����
#pragma once
//���������������Ķ���
template <class Type>
void swapT(Type &a, Type &b)
{
	Type t = a;
	a = b;
	b = t;
}
//�������max
template <class Type>
void siftUpMaxT(Type H[],int i)
{
	bool done = false;
	if (i!=0) {
		while (!done && i!=0) {
			if (H[i] > H[(i-1)/2])
				swapT(H[i],H[(i-1)/2]);
			else done = true;
			i=(i-1)/2;
		}
	}
}
//���������min
template <class Type>
void siftUpMinT(Type H[],int i)
{
	bool done = false;
	if (i!=0) {
		while (!done && i!=0) {
			if (H[i] < H[(i-1)/2])
				swapT(H[i],H[(i-1)/2]);
			else done = true;
			i=(i-1)/2;
		}
	}
}
//�������Max
template <class Type>
void siftDownMaxT(Type H[],int n,int i)
{
	bool done = false;
	while (!done && ((i=2*i+1)<n)) {
		if ((i+1<n)&&(H[i+1]>H[i]))
			i = i + 1;
		if (H[(i-1)/2] < H[i])
			swapT(H[(i-1)/2],H[i]);
		else done = true;
	}
}
//�������Min
template <class Type>
void siftDownMinT(Type H[],int n,int i)
{
	bool done = false;
	while (!done && ((i=2*i+1)<n)) {
		if ((i+1<n)&&(H[i+1]<H[i]))
			i = i + 1;
		if (H[(i-1)/2] > H[i])
			swap(H[(i-1)/2],H[i]);
		else done = true;
	}
}
//����Ԫ��Max, ����������ж���Ŀռ�
template <class Type>
void insertMaxT(Type H[],int &n, Type x)
{
	H[n++] = x;
	siftUpMaxT(H,n-1);
}
//����Ԫ��Min, ����������ж���Ŀռ�
template <class Type>
void insertMinT(Type H[],int &n, Type x)
{
	H[n++] = x;
	siftUpMinT(H,n-1);
}
//ɾ��Ԫ��max
template <class Type>
Type deleteIMaxT(Type H[],int &n,int i)
{
	Type x,y;
	x = H[i]; y = H[n-1];
	n = n - 1;
	if (i<n) {
		H[i] = y;
		if (y>x)
			siftUpMaxT(H,i);
		else
			siftDownMaxT(H,n,i);
	}
	return x;
}
//ɾ��Ԫ��min
template <class Type>
Type deleteIMinT(Type H[],int &n,int i)
{
	Type x,y;
	x = H[i]; y = H[n-1];
	n = n - 1;
	if (i<n) {
		H[i] = y;
		if (y<x)
			siftUpMinT(H,i);
		else
			siftDownMinT(H,n,i);
	}
	return x;
}
//ɾ����Ԫ��Max
template <class Type>
Type deleteTopMaxT(Type H[],int &n)
{
	Type x = deleteIMaxT(H,n,0);
	return x;
}
//ɾ����Ԫ��Min
template <class Type>
Type deleteTopMinT(Type H[],int &n)
{
	Type x = deleteIMinT(H,n,0);
	return x;
}
//�ѷ�����max
template <class Type>
void makeHeapMaxT(Type A[],int n)
{
	for (int i=n/2-1; i>=0; i--) {
		siftDownMaxT(A,n,i);
	}
}
//�ѷ�����min
template <class Type>
void makeHeapMinT(Type A[],int n)
{
	for (int i=n/2-1; i>=0; i--) {
		siftDownMinT(A,n,i);
	}
}
//������max
template <class Type>
void heapSortMaxT(Type A[],int n)
{
	makeHeapMaxT(A,n);
	for (int i=n-1;i>0;i--) {
		swapT(A[0],A[i] );
		siftDownMaxT(A,i,0);
	}
}
//������min
template <class Type>
void heapSortMinT(Type A[],int n)
{
	makeHeapMinT(A,n);
	for (int i=n-1;i>0;i--) {
		swapT(A[0],A[i] );
		siftDownMinT(A,i,0);
	}
}