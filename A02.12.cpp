//Algorithm 2.12 (P41)(A02.12.cpp)
//ººÅµËþ(Hanoi tower)ÎÊÌâ
#include "headers.h"
void Hanoi(char a, char b, char c, int n)
{
	if ( n == 1 ) printf("%c->%c\n", a, b);
	else {
		Hanoi(a, c, b, n-1);
		printf("%c->%c\n", a, b);
		Hanoi(c, b, a, n-1);
	}
}

void HanoiTest(int n)
{
	Hanoi('A', 'B', 'C', n);
}
