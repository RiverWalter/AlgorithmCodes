//MergeSortT.cpp
//合并排序—模板函数版
#pragma once
template <class Type>
void mergeT(Type a[],int p,int q,int r)
{
	Type *b = new Type[r-p+1];
	int i = p, j = q + 1, k = 0;
	while (i<=q && j<=r) {
		if (a[i]<a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	if (i==q+1)
		for (;j<=r;j++)
			b[k++] = a[j];
	else
		for (;i<=q;i++)
			b[k++] = a[i];
	k=0;
	for (i=p;i<=r;i++)
		a[i] = b[k++];
	delete b;
}
template <class Type>
void mergeSortRT(Type A[],int low,int high)
{
	if (low<high) {
		int mid = (low + high)/2;
		mergeSortRT(A,low,mid);
		mergeSortRT(A,mid+1,high);
		mergeT(A,low,mid,high);
	}
}
