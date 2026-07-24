#include<stdio.h>


int n;
int a[100010];


void insert_sort()
{
	for(int i = 2; i <= n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while(j >= 1 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int main()
{
    scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	insert_sort();
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}