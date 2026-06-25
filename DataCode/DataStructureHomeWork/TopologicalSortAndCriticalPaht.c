#include<stdio.h>
#include<stdlib.h>
#define MAXV 100

// 边结点结构体
typedef struct EdgeNode
{
    int adjvex;       // 邻接顶点下标
    int weight;       // 边的权值
    struct EdgeNode *nextedge;
} EdgeNode;

// 顶点结构体
typedef struct VertexNode
{
    int data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXV];

// 邻接表存储的图
typedef struct
{
    AdjList vertex;
    int n, e; // n:顶点总数  e:边总数
} GraphAdjList;

int inDegree[MAXV];    // 记录每个顶点入度
int topoSeq[MAXV];     // 存储拓扑排序序列
int ve[MAXV], vl[MAXV];// ve顶点最早发生时间 vl顶点最迟发生时间

// 创建带权有向图邻接表
void CreateGraph(GraphAdjList *G)
{
    int i, u, v, w;
    EdgeNode *p;
    printf("请输入顶点数、边数：");
    scanf("%d%d", &G->n, &G->e);

    // 初始化顶点数组与入度
    for (i = 0; i < G->n; i++)
    {
        G->vertex[i].data = i;
        G->vertex[i].firstedge = NULL;
        inDegree[i] = 0;
    }

    // 逐条输入有向边 u -> v，权值w
    for (i = 0; i < G->e; i++)
    {
        printf("输入第%d条边 起点u 终点v 权值w：", i + 1);
        scanf("%d%d%d", &u, &v, &w);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = v;
        p->weight = w;
        p->nextedge = G->vertex[u].firstedge;
        G->vertex[u].firstedge = p;
        inDegree[v]++;
    }
}

// 打印邻接表结构
void PrintGraph(GraphAdjList *G)
{
    int i;
    EdgeNode *p;
    printf("\n图邻接表\n");
    for (i = 0; i < G->n; i++)
    {
        printf("顶点%d：", G->vertex[i].data);
        p = G->vertex[i].firstedge;
        while (p != NULL)
        {
            printf("(邻接: %d, 权: %d) ", p->adjvex, p->weight);
            p = p->nextedge;
        }
        printf("\n");
    }
}

// 拓扑排序，返回有效顶点个数（有环则小于总顶点数）
int TopologicalSort(GraphAdjList *G)
{
    int stack[MAXV], top = -1;
    int i, cnt = 0, cur;
    EdgeNode *p;

    // 入度为0的顶点入栈
    for (i = 0; i < G->n; i++)
        if (inDegree[i] == 0)
            stack[++top] = i;

    while (top != -1)
    {
        cur = stack[top--];
        topoSeq[cnt++] = cur;
        p = G->vertex[cur].firstedge;
        while (p != NULL)
        {
            int v = p->adjvex;
            inDegree[v]--;
            if (inDegree[v] == 0)
                stack[++top] = v;
            p = p->nextedge;
        }
    }
    return cnt;
}

// 计算各顶点最早发生时间 ve
void CalcVE(GraphAdjList *G, int cntTopo)
{
    int i, u, v;
    EdgeNode *p;
    for (i = 0; i < G->n; i++)
        ve[i] = 0;
    // 按拓扑正序遍历
    for (i = 0; i < cntTopo; i++)
    {
        u = topoSeq[i];
        p = G->vertex[u].firstedge;
        while (p != NULL)
        {
            v = p->adjvex;
            if (ve[v] < ve[u] + p->weight)
                ve[v] = ve[u] + p->weight;
            p = p->nextedge;
        }
    }
}

// 计算各顶点最迟发生时间 vl
void CalcVL(GraphAdjList *G, int cntTopo)
{
    int i, u, v;
    EdgeNode *p;

    int T = ve[topoSeq[cntTopo - 1]];

    for (i = 0; i < G->n; i++)
        vl[i] = T;

    for (i = cntTopo - 1; i >= 0; i--)
    {
        u = topoSeq[i];
        p = G->vertex[u].firstedge;

        while (p != NULL)
        {
            v = p->adjvex;
            if (vl[u] > vl[v] - p->weight)
                vl[u] = vl[v] - p->weight;

            p = p->nextedge;
        }
    }
}


//输出关键活动、关键路径、总工期
void PrintKeyPath(GraphAdjList *G)
{
    printf("\n关键活动：\n");

    for (int u = 0; u < G->n; u++)
    {
        EdgeNode *p = G->vertex[u].firstedge;
        while (p != NULL)
        {
            int v = p->adjvex;

            if (ve[u] == vl[v] - p->weight)
            {
                printf("%d -> %d\n", u, v);
            }

            p = p->nextedge;
        }
    }

    int T = 0;
    for (int i = 0; i < G->n; i++)
        if (ve[i] > T) T = ve[i];

    printf("工程总工期：%d\n", T);
}

int main()
{
    GraphAdjList G;
    int topoCount, i;
    CreateGraph(&G);
    PrintGraph(&G);

    // 执行拓扑排序
    topoCount = TopologicalSort(&G);
    if (topoCount < G.n)
    {
        printf("\n图存在环路，无法求解拓扑排序与关键路径！\n");
        return 0;
    }

    // 输出拓扑序列
    printf("\n拓扑排序序列\n");
    for (i = 0; i < topoCount; i++)
        printf("%d ", topoSeq[i]);
    printf("\n");

    // 计算ve、vl并输出关键路径
    CalcVE(&G, topoCount);
    CalcVL(&G, topoCount);
    PrintKeyPath(&G);

    return 0;
}