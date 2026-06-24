#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} Node, *BiTree;

//栈结构体
typedef struct
{
    BiTree data[MAXSIZE];
    int top;
} Stack;

//队列结构体
typedef struct
{
    BiTree data[MAXSIZE];
    int front;
    int rear;
} Queue;

//栈初始化
void InitStack(Stack *s)
{
    s->top = -1;
}

//判栈空
int StackEmpty(Stack *s)
{
    return s->top == -1;
}

//入栈
void Push(Stack *s, BiTree x)
{
    s->data[++s->top] = x;
}

//出栈
BiTree Pop(Stack *s)
{
    return s->data[s->top--];
}

//队列初始化
void InitQueue(Queue *q)
{
    q->front = q->rear = 0;
}

//判队空
int QueueEmpty(Queue *q)
{
    return q->front == q->rear;
}

//入队
void EnQueue(Queue *q, BiTree x)
{
    q->data[q->rear++] = x;
}

//出队
BiTree DeQueue(Queue *q)
{
    return q->data[q->front++];
}

//建立二叉树

BiTree CreateTree()
{
    char ch;
    scanf(" %c", &ch);

    if (ch == '#')
        return NULL;

    BiTree T = (BiTree)malloc(sizeof(Node));
    T->data = ch;

    T->lchild = CreateTree();
    T->rchild = CreateTree();

    return T;
}


//递归先序遍历

void PreOrder(BiTree T)
{
    if (T)
    {
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}


//递归中序遍历

void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}


//递归后序遍历
void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}


//非递归先序遍历
void PreOrder_NR(BiTree T)
{
    Stack stack;
    InitStack(&stack);

    while (T || !StackEmpty(&stack))
    {
        while (T)
        {
            printf("%c ", T->data);
            Push(&stack, T);
            T = T->lchild;
        }

        if (!StackEmpty(&stack))
        {
            T = Pop(&stack);
            T = T->rchild;
        }
    }
}


//非递归中序遍历

void InOrder_NR(BiTree T)
{
    Stack stack;
    InitStack(&stack);

    while (T || !StackEmpty(&stack))
    {
        while (T)
        {
            Push(&stack, T);
            T = T->lchild;
        }

        if (!StackEmpty(&stack))
        {
            T = Pop(&stack);
            printf("%c ", T->data);
            T = T->rchild;
        }
    }
}


//层序遍历
void LevelOrder(BiTree T)
{
    if (!T)
        return;
    //队列
    Queue queue;
    InitQueue(&queue);

    EnQueue(&queue, T);

    while (!QueueEmpty(&queue))
    {
        BiTree p = DeQueue(&queue);

        printf("%c ", p->data);

        if (p->lchild)
            EnQueue(&queue, p->lchild);

        if (p->rchild)
            EnQueue(&queue, p->rchild);
    }
}


//求高度

int Height(BiTree T)
{
    if (T == NULL)
        return 0;
    //递归求出树的高度
    int lh = Height(T->lchild);
    int rh = Height(T->rchild);

    return (lh > rh ? lh : rh) + 1;
}


//求宽度
int Width(BiTree T)
{
    if (!T)
        return 0;
    //队列
    Queue queue;
    InitQueue(&queue);

    int maxWidth = 0;
    //根节点入队
    EnQueue(&queue, T);

    while (!QueueEmpty(&queue))
    {
        int count = queue.rear - queue.front;

        if (count > maxWidth)
            maxWidth = count;
        //一次遍历当前层的所有节点，即这一层的宽度
        for (int i = 0; i < count; i++)
        {
            BiTree p = DeQueue(&queue);

            if (p->lchild)
                EnQueue(&queue, p->lchild);

            if (p->rchild)
                EnQueue(&queue, p->rchild);
        }
    }

    return maxWidth;
}


//统计结点
void CountNodes(BiTree T, int *total, int *leaf, int *degree1, int *degree2)
{
    if (!T)
        return;

    (*total)++;

    int left = (T->lchild != NULL);
    int right = (T->rchild != NULL);

    if (!left && !right)
        (*leaf)++;
    else if (left + right == 1)
        (*degree1)++;
    else
        (*degree2)++;

    CountNodes(T->lchild, total, leaf, degree1, degree2);

    CountNodes(T->rchild, total, leaf, degree1, degree2);
}


//求路径

int FindPath(BiTree T, char target, char path[], int depth)
{
    if (!T)
        return 0;

    path[depth] = T->data;

    if (T->data == target)
    {
        printf("路径: ");

        for (int i = 0; i <= depth; i++)
            printf("%c ", path[i]);

        printf("\n");

        return 1;
    }

    if (FindPath(T->lchild, target, path, depth + 1))
        return 1;

    if (FindPath(T->rchild, target, path, depth + 1))
        return 1;

    return 0;
}


//释放树
//采用递归的方式来释放整颗二叉树
void DestroyTree(BiTree T)
{
    if (T)
    {
        DestroyTree(T->lchild);
        DestroyTree(T->rchild);
        free(T);
    }
}

int main()
{
    printf("请输入先序序列(#表示空结点):\n");

    BiTree T = CreateTree();

    printf("递归先序遍历:\n");
    PreOrder(T);

    printf("非递归先序遍历:\n");
    PreOrder_NR(T);

    printf("递归中序遍历:\n");
    InOrder(T);

    printf("非递归中序遍历:\n");
    InOrder_NR(T);

    printf("后序遍历:\n");
    PostOrder(T);

    printf("层序遍历:\n");
    LevelOrder(T);

    printf("高度=%d\n", Height(T));
    printf("宽度=%d\n", Width(T));

    int total = 0;
    int leaf = 0;
    int degree1 = 0;
    int degree2 = 0;

    CountNodes(T, &total, &leaf, &degree1, &degree2);

    printf("总结点数=%d\n", total);
    printf("叶子结点=%d\n", leaf);
    printf("度为1结点=%d\n", degree1);
    printf("度为2结点=%d\n", degree2);

    char target;
    printf("请输入要查找路径的结点:");
    scanf(" %c", &target);

    char path[MAXSIZE];

    if (!FindPath(T, target, path, 0))
        printf("未找到该结点!\n");

    DestroyTree(T);

    return 0;
}