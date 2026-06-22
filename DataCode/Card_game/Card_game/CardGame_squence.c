#include<stdio.h>

int card[60] = { 0 };
//0表示正面，1表示反面
int main()
{
	for (int i = 2; i <= 52; i++)
	{
		for (int j = i; j <= 52; j += i)
		{
			card[j] = card[j] ^ 1;
		}
	}
	for (int i = 1; i <= 52; i++)
	{
		if (card[i] == 0)
			printf("%d ", i);
	}
	return 0;
}