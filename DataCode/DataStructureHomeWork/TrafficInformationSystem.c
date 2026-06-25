#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXV 100
#define INF  1000000

int G[MAXV][MAXV];   // 邻接矩阵
int n, m;            // 顶点数、边数
char city[MAXV][20]; // 城市名

//打印路径（递归
void printPath(int path[][MAXV], int i, int j)
{
    if (path[i][j] == -1)
    {
        printf("%s ", city[i]);
        if (i != j)
            printf("%s ", city[j]);
        return;
    }

    printPath(path, i, path[i][j]);
    printf("%s ", city[j]);
}

//输出图
void printGraph()
{
    printf("\n交通网络（邻接矩阵）：\n   ");
    for (int i = 0; i < n; i++)
        printf("%10s", city[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s", city[i]);
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == INF)
                printf("%10s", "INF");
            else
                printf("%10d", G[i][j]);
        }
        printf("\n");
    }
}

//Dijkstra
void Dijkstra(int src)
{
    int dist[MAXV], visited[MAXV], path[MAXV];

    for (int i = 0; i < n; i++)
    {
        dist[i] = G[src][i];
        visited[i] = 0;
        path[i] = (G[src][i] < INF && i != src) ? src : -1;
    }

    visited[src] = 1;
    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        int min = INF, u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && G[u][v] < INF)
            {
                if (dist[u] + G[u][v] < dist[v])
                {
                    dist[v] = dist[u] + G[u][v];
                    path[v] = u;
                }
            }
        }
    }

    printf("\nDijkstra:从 %s 出发\n", city[src]);

    for (int i = 0; i < n; i++)
    {
        if (i == src) continue;

        printf("\n到 %s 的最短路径：", city[i]);
        printPath(&path, src, i);
        printf("\n总距离：%d\n", dist[i]);
    }
}

// Floyd
int dis[MAXV][MAXV];
int P[MAXV][MAXV];

void Floyd()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = G[i][j];
            P[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    printf("\nFloyd 任意两点最短路径\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("\n%s -> %s 路径：", city[i], city[j]);
            printPath(P, i, j);
            printf("\n总距离：%d\n", dis[i][j]);
        }
    }
}

//主函数
int main()
{
    printf("输入城市数：");
    scanf("%d", &n);

    printf("输入城市名称：\n");
    for (int i = 0; i < n; i++)
        scanf("%s", city[i]);

    // 初始化图
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    printf("输入边数：");
    scanf("%d", &m);

    printf("输入边（起点 终点 距离）：\n");
    for (int i = 0; i < m; i++)
    {
        char a[20], b[20];
        int d, u = -1, v = -1;

        scanf("%s %s %d", a, b, &d);

        for (int j = 0; j < n; j++)
        {
            if (strcmp(city[j], a) == 0) u = j;
            if (strcmp(city[j], b) == 0) v = j;
        }

        G[u][v] = G[v][u] = d; // 无向图
    }

    printGraph();

    int src;
    printf("\n输入Dijkstra起点编号(0~%d)：", n - 1);
    scanf("%d", &src);

    Dijkstra(src);
    Floyd();

    return 0;
}