#include<stdio.h>

int n;
int a[100010];

void swap(int* a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort()
{
	for(int i = 1; i < n; i++)
	{
		int flag = 0;
		for(int j = 1; j <= n - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if(!flag) break;
	}
}

int main()
{
    scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	bubble_sort();
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}