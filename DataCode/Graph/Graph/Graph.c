#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"

#define MAXV 100
#define INF 999999

//邻接矩阵（带权无向图）

typedef struct
{
    char vex[MAXV];
    int edge[MAXV][MAXV];
    int vexnum;
    int arcnum;
}MGraph;


//邻接表（带权有向图）
typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode* next;
}ArcNode;

typedef struct
{
    char data;
    ArcNode* first;
}VNode;

typedef struct
{
    VNode vertices[MAXV];
    int vexnum;
    int arcnum;
}ALGraph;


// 查找顶点下标

int LocateVertex(char vex[], int n, char ch)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vex[i] == ch)
            return i;
    }

    return -1;
}


// 创建带权无向图邻接矩阵

void CreateMGraph(MGraph* G)
{
    int i, j, k, w;
    char v1, v2;

    printf("输入顶点数 边数:");
    scanf("%d%d", &G->vexnum, &G->arcnum);

    printf("输入各顶点:\n");

    for (i = 0; i < G->vexnum; i++)
        scanf(" %c", &G->vex[i]);

    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            if (i == j)
                G->edge[i][j] = 0;
            else
                G->edge[i][j] = INF;
        }
    }

    printf("输入边(顶点1 顶点2 权值):\n");

    for (k = 0; k < G->arcnum; k++)
    {
        scanf(" %c %c %d", &v1, &v2, &w);

        i = LocateVertex(G->vex, G->vexnum, v1);
        j = LocateVertex(G->vex, G->vexnum, v2);

        G->edge[i][j] = w;
        G->edge[j][i] = w;
    }
}


// 输出邻接矩阵
void PrintMatrix(MGraph* G)
{
    int i, j;

    printf("\n邻接矩阵:\n");

    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            if (G->edge[i][j] == INF)
                printf("∞ ");
            else
                printf("%d ", G->edge[i][j]);
        }

        printf("\n");
    }
}



// 创建带权有向图邻接表
void CreateALGraph(ALGraph* G)
{
    int i, k, w;
    char v1, v2;

    ArcNode* p;

    printf("\n输入顶点数 弧数:");
    scanf("%d%d", &G->vexnum, &G->arcnum);

    printf("输入各顶点:\n");

    for (i = 0; i < G->vexnum; i++)
    {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].first = NULL;
    }

    printf("输入弧(起点 终点 权值):\n");

    for (k = 0; k < G->arcnum; k++)
    {
        scanf(" %c %c %d", &v1, &v2, &w);

        int from = -1, to = -1;

        for (i = 0; i < G->vexnum; i++)
        {
            if (G->vertices[i].data == v1)
                from = i;

            if (G->vertices[i].data == v2)
                to = i;
        }

        p = (ArcNode*)malloc(sizeof(ArcNode));

        p->adjvex = to;
        p->weight = w;

        p->next = G->vertices[from].first;
        G->vertices[from].first = p;
    }
}


//DFS（利用栈）

void DFS(MGraph* G, int start)
{
    int visited[MAXV] = { 0 };

    SeqStack S;
    InitStack(&S);

    Push(&S, start);
    visited[start] = 1;

    printf("\nDFS:");

    while (!IsStackEmpty(&S))
    {
        char top;
        Pop(&S, &top);

        printf("%c ", G->vex[(int)top]);

        int i;

        for (i = G->vexnum - 1; i >= 0; i--)
        {
            if (G->edge[(int)top][i] != INF
                && G->edge[(int)top][i] != 0
                && !visited[i])
            {
                Push(&S, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}


// BFS（利用队列）

void BFS(MGraph* G, int start)
{
    int visited[MAXV] = { 0 };

    SeqQueue Q;
    InitQueue(&Q);

    EnterQueue(&Q, start);
    visited[start] = 1;

    printf("BFS:");

    while (!IsEmptyQueue(&Q))
    {
        int u;

        DeleteQueue(&Q, &u);

        printf("%c ", G->vex[u]);

        int i;

        for (i = 0; i < G->vexnum; i++)
        {
            if (G->edge[u][i] != INF
                && G->edge[u][i] != 0
                && !visited[i])
            {
                EnterQueue(&Q, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}



int main()
{
    MGraph MG;
    ALGraph AG;
    CreateMGraph(&MG);
    PrintMatrix(&MG);
    DFS(&MG, 0);
    BFS(&MG, 0);
    CreateALGraph(&AG);

    return 0;
}