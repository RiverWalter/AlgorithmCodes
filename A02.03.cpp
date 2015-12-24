//Algorithm 2.3 (P25-6)(A02.03.cpp)
//ÌÔÌ­ÈüËã·¨
#include "headers.h"
bool match(int a, int b)
{
	double r = randDbl();
	return (r > 0.5);
}
int knockout(int athletes[], int n, bool verbose)
{
	int i = n, k=1;
	while (i>1) {
		i = i/2;
		for (int j=0; j<i; j++)
			if (match(athletes[j+i],athletes[j]))
				athletes[j] = athletes[j+i];
		if (verbose) {
			printf("Round %d:\n", k);
			for (int j=0; j<i; j++)
				printf("%3d", athletes[j]);
			printf("\n");
		}
		k++;
	}
	return athletes[0];
}
void knockoutTest(int k, bool verbose)
{
	int n = power(2, k);
	int *a = new int[128];
	printf("%d athletes join the knockout:\n", n);
	for (int i=0; i<n; i++)
		a[i] = i+1;
	int champion = knockout(a, n, verbose);
	printf("The champion is: %d\n", champion);
	delete a;
}