#include <stdio.h>
#include <string.h>

#define MAXV 100
#define INF 1000000

int G[MAXV][MAXV];
char city[MAXV][20];
int n, m;

//输出邻接矩阵
void printGraph()
{
    printf("\n交通网络邻接矩阵：\n\n");

    printf("%8s", "");
    for (int i = 0; i < n; i++)
        printf("%8s", city[i]);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%8s", city[i]);

        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == INF)
                printf("%8s", "INF");
            else
                printf("%8d", G[i][j]);
        }

        printf("\n");
    }
}

//Dijkstra

void printDijkstraPath(int path[], int v)
{
    if (path[v] == -1)
    {
        printf("%s", city[v]);
        return;
    }

    printDijkstraPath(path, path[v]);
    printf(" -> %s", city[v]);
}

void Dijkstra(int src)
{
    int dist[MAXV];
    int visited[MAXV];
    int path[MAXV];

    for (int i = 0; i < n; i++)
    {
        dist[i] = G[src][i];
        visited[i] = 0;

        if (i != src && G[src][i] < INF)
            path[i] = src;
        else
            path[i] = -1;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (int i = 1; i < n; i++)
    {
        int min = INF;
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                G[u][v] < INF &&
                dist[u] + G[u][v] < dist[v])
            {
                dist[v] = dist[u] + G[u][v];
                path[v] = u;
            }
        }
    }

    printf("Dijkstra最短路径（起点：%s）\n", city[src]);

    for (int i = 0; i < n; i++)
    {
        if (i == src)
            continue;

        printf("\n%s -> %s\n", city[src], city[i]);

        if (dist[i] == INF)
        {
            printf("无路径\n");
            continue;
        }

        printf("路径：");
        printDijkstraPath(path, i);

        printf("\n距离：%d\n", dist[i]);
    }
}

//Floyd

int distF[MAXV][MAXV];
int pathF[MAXV][MAXV];

void Floyd()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distF[i][j] = G[i][j];

            if (i != j && G[i][j] < INF)
                pathF[i][j] = i;
            else
                pathF[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distF[i][k] < INF &&
                    distF[k][j] < INF &&
                    distF[i][k] + distF[k][j] < distF[i][j])
                {
                    distF[i][j] = distF[i][k] + distF[k][j];
                    pathF[i][j] = pathF[k][j];
                }
            }
        }
    }
}

void printFloydPath(int start, int end)
{
    int stack[MAXV];
    int top = -1;

    int cur = end;

    while (cur != start)
    {
        stack[++top] = cur;
        cur = pathF[start][cur];
    }

    printf("%s", city[start]);

    while (top >= 0)
    {
        printf(" -> %s", city[stack[top--]]);
    }
}

void showFloyd()
{
    printf("Floyd任意两点最短路径\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("\n%s -> %s\n", city[i], city[j]);

            if (distF[i][j] == INF)
            {
                printf("无路径\n");
                continue;
            }

            printf("路径：");
            printFloydPath(i, j);

            printf("\n距离：%d\n", distF[i][j]);
        }
    }
}

int main()
{
    printf("请输入城市数：");
    scanf("%d", &n);

    printf("请输入城市名称：\n");

    for (int i = 0; i < n; i++)
        scanf("%s", city[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = INF;
        }
    }

    printf("请输入道路数：");
    scanf("%d", &m);

    printf("请输入道路信息(城市1 城市2 距离)：\n");

    for (int i = 0; i < m; i++)
    {
        char a[20], b[20];
        int d;

        scanf("%s %s %d", a, b, &d);

        int u = -1, v = -1;

        for (int j = 0; j < n; j++)
        {
            if (strcmp(city[j], a) == 0)
                u = j;

            if (strcmp(city[j], b) == 0)
                v = j;
        }

        if (u == -1 || v == -1)
        {
            printf("城市不存在，忽略该边！\n");
            continue;
        }

        G[u][v] = d;
        G[v][u] = d;
    }

    printGraph();

    int src;

    printf("\n请输入Dijkstra起点编号(0~%d)：", n - 1);
    scanf("%d", &src);

    if (src < 0 || src >= n)
    {
        printf("起点编号错误！\n");
        return 0;
    }

    Dijkstra(src);

    Floyd();

    showFloyd();

    return 0;
}