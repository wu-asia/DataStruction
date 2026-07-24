#include<stdio.h>

#define N 10010

int father[N];

// 初始化集合
void init(int n)
{
    for (int i = 1; i <= n; i++)
        father[i] = i;
}

// 查找（路径压缩）
int find(int x)
{
    if (father[x] == x)
        return x;
    return father[x] = find(father[x]);
}

// 合并集合
void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if (fx != fy)
        father[fx] = fy;
}

// 输出当前集合结构（按根分类简单展示）
void printSets(int n)
{
    printf("\n当前集合结构：\n");

    for (int i = 1; i <= n; i++)
        printf("%d -> %d\n", i, find(i));
}

// 查询元素所属集合
void query(int x)
{
    printf("元素 %d 所属集合代表元：%d\n", x, find(x));
}

int main()
{
    int n = 0;
    int choice;

    while (1)
    {
        printf("\n====== 并查集菜单 ======\n");
        printf("1. 建立集合\n");
        printf("2. 查找（判定）元素所属集合\n");
        printf("3. 集合的并运算\n");
        printf("4. 输出集合结构\n");
        printf("0. 退出\n");
        printf("请选择 0-4：");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (choice == 1)
        {
            printf("输入元素个数 n：");
            scanf("%d", &n);
            init(n);
            printf("集合建立完成！\n");
        }
        else if (choice == 2)
        {
            int x;
            printf("输入元素 x：");
            scanf("%d", &x);
            query(x);
        }
        else if (choice == 3)
        {
            int x, y;
            printf("输入要合并的两个元素 x y：");
            scanf("%d %d", &x, &y);
            unite(x, y);
            printf("合并完成！\n");
        }
        else if (choice == 4)
        {
            printSets(n);
        }
        else
        {
            printf("无效选择！\n");
        }
    }

    return 0;
}