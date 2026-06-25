#include<stdio.h>

#define N 10010
int father[N];

int find(int x)
{
    return (father[x] == x) ? father[x] : (father[x] = find(father[x]));
}

void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    father[fx] = fy;
}
int issame(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化
    for (int i = 1; i <= n; i++)
        father[i] = i;

    // 示例操作
    for (int i = 0; i < m; i++)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);

        if (op == 1)
            unite(x, y);
        else if (op == 2)
            printf("%d\n", issame(x, y));
    }
    return 0;
}