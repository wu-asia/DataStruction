#include<stdio.h>

int card[60] = { 0 };
//可以得出规律，只有完全平方数位置的卡牌才可能是正面
//因为每一个数字的约数都是成双成对存在的，
//但是完全平方数的约数中有一个是重复的，所以完全平方数位置的卡牌被翻开的次数是奇数。
int main()
{
    
	for (int i = 1; i * i <= 52; i++)
	{
		card[i * i] = 1;
	}
	for (int i = 1; i <= 52; i++)
		if (card[i] == 1)
			printf("%d ", i);
	return 0;
}