// 3． 一元多项式计算
// 任务：设计合适的存储结构，完成一元多项式的相关运算。
// 要求：（1）能够按照指数降序排列建立并输出多项式；（2）能够完成两个多项式的相加、
// 相减，并将结果输出。
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coef;              // 系数 coefficient
    int exp;               // 指数 exponent
    struct node *next;
}Node, *Polynomial;

// 创建结点
Node *newNode(int coef, int exp)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->coef = coef;
    p->exp = exp;
    p->next = NULL;
    //返回节点
    return p;
}

// 按指数降序插入
void insert(Polynomial *head, int coef, int exp)
{
    if (coef == 0)
        return;

    Node *p = newNode(coef, exp);

    // 空链表或插入到表头
    if (*head == NULL || (*head)->exp < exp)
    {
        p->next = *head;
        *head = p;
        return;
    }

    Node *pre = NULL;
    Node *cur = *head;

    while (cur && cur->exp > exp)
    {
        pre = cur;
        cur = cur->next;
    }

    // 存在相同指数，合并同类项
    if (cur && cur->exp == exp)
    {
        cur->coef += coef;

        // 系数变成0，删除该项
        if (cur->coef == 0)
        {
            if (pre == NULL)
                *head = cur->next;
            else
                pre->next = cur->next;

            free(cur);
        }

        free(p);
    }
    else
    {
        p->next = cur;

        if (pre == NULL)
            *head = p;
        else
            pre->next = p;
    }
}

// 创建多项式
void create(Polynomial *head)
{
    *head = NULL;

    int n;
    printf("请输入项数：");
    scanf("%d", &n);

    printf("请输入每一项的系数和指数：\n");

    for (int i = 0; i < n; i++)
    {
        int coef, exp;
        scanf("%d%d", &coef, &exp);
        insert(head, coef, exp);
    }
}

// 输出多项式
void printPoly(Polynomial head)
{
    //如果为空，则定义为
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    Node *p = head;
    int first = 1;

    while (p)
    {
        if (!first && p->coef > 0)
            printf("+");

        if (p->exp == 0)
            printf("%d", p->coef);
        else if (p->exp == 1)
        {
            if (p->coef == 1)
                printf("x");
            else if (p->coef == -1)
                printf("-x");
            else
                printf("%dx", p->coef);
        }
        else
        {
            if (p->coef == 1)
                printf("x^%d", p->exp);
            else if (p->coef == -1)
                printf("-x^%d", p->exp);
            else
                printf("%dx^%d", p->coef, p->exp);
        }

        first = 0;
        p = p->next;
    }

    printf("\n");
}

// 多项式加法
Polynomial add(Polynomial A, Polynomial B)
{
    Polynomial C = NULL;

    Node *p = A;
    while (p)
    {
        insert(&C, p->coef, p->exp);
        p = p->next;
    }

    p = B;
    while (p)
    {
        insert(&C, p->coef, p->exp);
        p = p->next;
    }

    return C;
}

// 多项式减法 A-B
Polynomial subtract(Polynomial A, Polynomial B)
{
    Polynomial C = NULL;

    Node *p = A;
    while (p)
    {
        insert(&C, p->coef, p->exp);
        p = p->next;
    }

    p = B;
    while (p)
    {
        insert(&C, -p->coef, p->exp);
        p = p->next;
    }

    return C;
}

// 释放链表
void destroy(Polynomial head)
{
    Node *p;

    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

int main()
{
    Polynomial A, B, C, D;

    printf("创建第一个多项式：\n");
    create(&A);

    printf("\n创建第二个多项式：\n");
    create(&B);

    printf("\nA(x) = ");
    printPoly(A);

    printf("B(x) = ");
    printPoly(B);

    C = add(A, B);
    printf("\nA(x)+B(x) = ");
    printPoly(C);

    D = subtract(A, B);
    printf("A(x)-B(x) = ");
    printPoly(D);

    destroy(A);
    destroy(B);
    destroy(C);
    destroy(D);

    return 0;
}