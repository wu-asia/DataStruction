#include<stdio.h>

int card[60] = { 0 };
//0表示正面，1表示反面
int main()
{
    //从第二张卡牌开始，以i为基数，反转卡牌
	for (int i = 2; i <= 52; i++)
	{
        //从第i张卡牌开始，每隔i张卡牌反转一次
		for (int j = i; j <= 52; j += i)
		{
			card[j] = card[j] ^ 1;
		}
	}
	for (int i = 1; i <= 52; i++)
	{
        //如果卡牌是正面，则输出卡牌编号
		if (card[i] == 0)
			printf("%d ", i);
	}
	return 0;
}