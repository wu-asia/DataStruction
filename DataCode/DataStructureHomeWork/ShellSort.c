#include<stdio.h>

int n;
int a[100010];


void shell_sort()
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap + 1; i <= n; i++)
        {
            int tmp = a[i];
            int j = i - gap;

            while(j > 0 && a[j] > tmp)
            {
                a[j + gap] = a[j];
                j -= gap;
            }

            a[j + gap] = tmp;
        }
    }
}

int main()
{
    scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	shell_sort();
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
