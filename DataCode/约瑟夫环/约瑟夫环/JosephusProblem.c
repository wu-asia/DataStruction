//# 模块一：线性结构
//## 1．约瑟夫环
//任务：一堆猴子都有编号，编号是 1，2，3 … n ，
// 这群猴子（n 个）按照 1～n 的顺序围坐一圈，从第 1 开始数，
// 每数到第 m 个，该猴子就要离开此圈，这样依次下来，
// 直到圈中只剩下最后一只猴子，则该猴子为大王。
// 请设计算法编写程序输出为大王的猴子的编号。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000
int a[N], n, m;
int st[N];

int josephus_circle()
{
	if (n == 1)
		return a[0];
	int num = n;
	int cnt = 0;
	int index = 0;
	while (num != 1)
	{
		if (st[index] == 1)
		{
			index = (index + 1) % n;
			continue;
		}
		cnt++;
		if (cnt == m)
		{
			st[index] = 1;
			cnt = 0;
			num--;
		}
		index = (index + 1) % n;

	}
	for (int i = 0; i < n; i++)
		if (st[i] == 0)
			return a[i];
	return -1;
}

int main()
{
	printf("请输入n, m:");
	scanf("%d %d", &n, &m);
	memset(st, 0, sizeof st);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	int ret = josephus_circle();
	printf("结果是:%d", ret);
	return 0;
}