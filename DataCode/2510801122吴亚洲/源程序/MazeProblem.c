//输入一个任意大小的迷宫数据，用非递归的方法求出走出迷宫的路径，并将路径输出。

#include <stdio.h>

#define MAXSIZE 100

// 坐标结构体
typedef struct
{
    int x;
    int y;
} Position;

// 顺序栈
typedef struct
{
    Position data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void InitStack(Stack *s)
{
    s->top = -1;
}

// 判空
int Empty(Stack *s)
{
    return s->top == -1;
}

// 入栈
void Push(Stack *s, Position p)
{
    s->data[++s->top] = p;
}

// 出栈
Position Pop(Stack *s)
{
    return s->data[s->top--];
}

// 取栈顶元素
Position GetTop(Stack *s)
{
    return s->data[s->top];
}

int maze[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];

int main()
{
    int m, n;

    printf("请输入迷宫行数和列数：");
    scanf("%d %d", &m, &n);

    printf("请输入迷宫（0表示通路，1表示障碍）：\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }

    Stack s;
    InitStack(&s);

    Position start = {0, 0};      // 起点
    Position end = {m - 1, n - 1}; // 终点

    // 起点或终点不可走
    if(maze[0][0] == 1 || maze[m - 1][n - 1] == 1)
    {
        printf("不存在路径！\n");
        return 0;
    }

    Push(&s, start);
    visited[0][0] = 1;

    // 方向数组：右、下、左、上
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int found = 0;

    while(!Empty(&s))
    {
        Position cur = GetTop(&s);

        // 到达终点
        if(cur.x == end.x && cur.y == end.y)
        {
            found = 1;
            break;
        }

        int flag = 0;

        // 找下一个位置
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 判断是否越界、是否可走、是否访问过
            if(nx >= 0 && nx < m &&
               ny >= 0 && ny < n &&
               maze[nx][ny] == 0 &&
               visited[nx][ny] == 0)
            {
                Position next = {nx, ny};
                Push(&s, next);
                visited[nx][ny] = 1;
                flag = 1;
                break;
            }
        }

        // 四个方向都不能走，回退
        if(flag == 0)
        {
            Pop(&s);
        }
    }

    if(found)
    {
        printf("找到路径：\n");

        for(int i = 0; i <= s.top; i++)
        {
            printf("(%d,%d)", s.data[i].x, s.data[i].y);

            if(i != s.top)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("不存在路径！\n");
    }

    return 0;
    
}