#include<stdio.h>


int n;
int a[100010];

void swap(int* a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort()
{
	for(int i = 1; i <= n; i++)
	{
		int pos = i;
		for(int j = i; j <= n; j++)
		{
			if(a[j] < a[pos])
				pos = j;
		}
		swap(&a[i], &a[pos]);
	}
}

int main()
{
    scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	selection_sort();
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
