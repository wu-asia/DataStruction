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
    //如果只有一个人，则直接返回
	if (n == 1)
		return a[0];
    //如果有多个人，则模拟出圈的过程
	int num = n;
	int cnt = 0;
	int index = 0;
	while (num != 1)
	{
        //如果当前这个人已经出圈了，则跳过
		if (st[index] == 1)
		{
			index = (index + 1) % n;
			continue;
		}
		cnt++;
        //如果数到第 m 个，则该人出圈
		if (cnt == m)
		{
			st[index] = 1;
			cnt = 0;
			num--;
		}
		index = (index + 1) % n;

	}
    //最后剩下的这个人就是大王，返回他的编号
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