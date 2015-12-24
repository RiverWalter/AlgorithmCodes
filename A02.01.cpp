//Algorithm 2.1 (P23-4)(A02.01.cpp)
//Horner法计算多项式(循环实现)
#include "headers.h"
long polynomial(int a[],int n,long x)
{
	long ret = a[n];
	for (int i = n; i > 0; i--) 
		ret = ret * x + a[i-1];
	return ret;
}
void polynomialTest(int n)
{
	int *a = new int[n+1];
	randRangeArr(n+1, -n, n, a);
	printf("Horner法计算多项式:\n");
	printf("系数:\n");
	printArrR(a, n+1);
	printf("多项式:\n");
	bool first=false;
	printf("p(x)=");
	for (int i=n; i>=0; i--) {
		if (!first) {
			if (a[i]) {
				if (i>0 && abs(a[i])==1) {
					if (a[i]==-1)
						printf("-");
					printf("x^%d", i);
				}
				else if (i==0)
					printf("%d", a[i]);
				else if (i==1)
					printf("%dx", a[i]);
				else
					printf("%dx^%d", a[i], i);
				first = true;
			}
		}
		else if (a[i])
			if (i>0 && abs(a[i])==1) {
				if (a[i]==-1)
					printf("-x^%d", i);
				else
					printf("+x^%d", i);
			}
			else if (i==0)
				printf("%+d", a[i]);
			else if (i==1)
				printf("%+dx", a[i]);
			else
				printf("%+dx^%d", a[i], i);
	}
	if (!first)
		printf("0");
	printf("\n");
	printf("求值:\n");
	int x[3];
	printf("  x ");
	for (int i=0; i<3; i++) {
		x[i] = randRange(-n, n);
		printf("%6d", x[i]);
	}
	printf("\n");
	printf("p(x)");
	for (int i=0; i<3; i++) {
		printf("%6ld", polynomial(a, n, x[i]));
	}
	printf("\n");
	delete a;
}