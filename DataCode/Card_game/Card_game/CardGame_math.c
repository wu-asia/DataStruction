#include<stdio.h>

int card[60] = { 0 };
int main()
{
	for (int i = 1; i * i <= 52; i++)
	{
		card[i * i] = 1;
	}
	for (int i = 1; i <= 52; i++)
		if (card[i] == 0)
			printf("%d ", i);
	return 0;
}