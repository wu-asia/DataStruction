// 八皇后问题
// 任务：国际西洋棋棋手马克斯·贝瑟尔于1848年提出在8X8格的国际象棋上摆放八个皇后，
// 使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种
// 摆法。请设计算法编写程序解决。
// 要求：（1）求解并输出八皇后的一个解；（2）在（1）的基础上，求解并输出八皇后的所
// 有解（92个解）。

#include<stdio.h>

#define N 10
int col[N * N] = {0}; //标记列是否放置皇后
int st1[N * N] = {0};
int st2[N * N] = {0}; //标记两个对角线
//主对角线上的是形如y=kx+b;
//副对角线上的是形如y=-kx+b;

int n; //棋盘的规模
int path[N * N]; //存储的是合法的纵坐标
int id = 1;
void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1; i <= n; i++)
        {
            printf("(%d, %d)", i, path[i]);
        }
        printf("\n");
        return;
    }
    for(int y = 1; y <= n; y++)
    {
        if(col[y] || st1[x - y + n] || st2[x + y]) continue;
        path[id++] = y;
        col[y] = st1[x - y + n] = st2[x + y] = 1;
        dfs(x + 1);
        col[y] = st1[x - y + n] = st2[x + y] = 0;
        path[id] = 0;
        id--;
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}