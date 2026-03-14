#include<stdio.h>

void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a = 10, b = 20;
	printf("a = %d, b = %d\n", a, b);
	swap1(a, b);
	printf("a = %d, b = %d\n", a, b);
	a = 10, b = 20;
	printf("a = %d, b = %d\n", a, b);
	swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}