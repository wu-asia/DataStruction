#include<stdio.h>

int main()
{
	int sum, average;
	int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	t1 = 80;
	t2 = 85;
	t3 = 77;
	t4 = 56;
	t5 = 68;
	t6 = 83;
	t7 = 90;
	t8 = 92;
	t9 = 80;
	t10 = 98;
	sum = t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10;
	average = sum / 10;
	printf("总分：%d\n", sum); printf("平均分：%d", average);
	return 0;
}