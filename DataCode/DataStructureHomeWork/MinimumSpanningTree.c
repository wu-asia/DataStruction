#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXV 100
#define INF 32767


// 图结构

//邻接矩阵(prim算法)
typedef struct
{
    int vexnum;
    int arcnum;
    int arcs[MAXV][MAXV];
} MGraph;


// 边结构(Kruskal算法)

typedef struct
{
    int begin;
    int end;
    int weight;
} Edge;


// 并查集

int parent[MAXV];

int Find(int x)
{
    if(parent[x] == x)
        return parent[x];
    else
        return parent[x] = Find(x);
}

void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);

    if (fx != fy)
        parent[fx] = fy;
}


// 建图

void CreateGraph(MGraph *G)
{
    int i, j;
    int u, v, w;

    printf("输入顶点数和边数：");
    scanf("%d%d", &G->vexnum, &G->arcnum);

    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            if (i == j)
                G->arcs[i][j] = 0;
            else
                G->arcs[i][j] = INF;
        }
    }

    printf("输入边(起点 终点 权值)：\n");

    for (i = 0; i < G->arcnum; i++)
    {
        scanf("%d%d%d", &u, &v, &w);

        G->arcs[u][v] = w;
        G->arcs[v][u] = w;
    }
}


// 输出邻接矩阵

void PrintGraph(MGraph G)
{
    int i, j;

    printf("\n邻接矩阵：\n");

    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
        {
            //其中的N表示的是无穷大
            if (G.arcs[i][j] == INF)
                printf("N ");
            else
                printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
}


// Prim算法

void Prim(MGraph G, int start)
{
    int lowcost[MAXV];
    int closest[MAXV];

    int i, j;
    int min;
    int k;

    int sum = 0;

    for (i = 0; i < G.vexnum; i++)
    {
        lowcost[i] = G.arcs[start][i];
        closest[i] = start;
    }

    lowcost[start] = 0;

    printf("\nPrim最小生成树：\n");

    for (i = 1; i < G.vexnum; i++)
    {
        min = INF;
        k = -1;

        for (j = 0; j < G.vexnum; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }

        printf("%d -- %d  权值=%d\n", closest[k], k, min);

        sum += min;

        lowcost[k] = 0;

        for (j = 0; j < G.vexnum; j++)
        {
            if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
            {
                lowcost[j] = G.arcs[k][j];
                closest[j] = k;
            }
        }
    }

    printf("最小生成树总权值=%d\n", sum);
}


// 边排序

int get_random_index(int left, int right)
{
    return rand() % (right - left + 1) + left;
}

void swap(Edge *a, Edge *b)
{
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void SortEdges(Edge edges[], int left, int right)
{
    if (left >= right)
        return;

    int index = get_random_index(left, right);

    int key = edges[index].weight;

    int l = left - 1;
    int i = left;
    int r = right + 1;

    while (i < r)
    {
        if (edges[i].weight < key)
        {
            swap(&edges[++l], &edges[i++]);
        }
        else if (edges[i].weight == key)
        {
            i++;
        }
        else
        {
            swap(&edges[--r], &edges[i]);
        }
    }

    SortEdges(edges, left, l);
    SortEdges(edges, r, right);
}


// Kruskal算法

void Kruskal(MGraph G)
{
    Edge edges[MAXV * MAXV];

    int edgeCount = 0;

    int i, j;

    // 提取边
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = i + 1; j < G.vexnum; j++)
        {
            if (G.arcs[i][j] != INF && G.arcs[i][j] != 0)
            {
                edges[edgeCount].begin = i;
                edges[edgeCount].end = j;
                edges[edgeCount].weight = G.arcs[i][j];

                edgeCount++;
            }
        }
    }

    SortEdges(edges, 0, edgeCount - 1);

    for (i = 0; i < G.vexnum; i++)
        parent[i] = i;

    int sum = 0;
    int cnt = 0;

    printf("\nKruskal最小生成树：\n");

    for (i = 0; i < edgeCount; i++)
    {
        int u = edges[i].begin;
        int v = edges[i].end;
        int w = edges[i].weight;

        if (Find(u) != Find(v))
        {
            Union(u, v);

            printf("%d -- %d  权值=%d\n",u, v, w);

            sum += w;
            cnt++;

            if (cnt == G.vexnum - 1)
                break;
        }
    }

    printf("最小生成树总权值=%d\n", sum);
}


int main()
{
    srand(time(NULL));
    MGraph G;

    CreateGraph(&G);

    PrintGraph(G);

    Prim(G, 0);

    Kruskal(G);

    return 0;
}