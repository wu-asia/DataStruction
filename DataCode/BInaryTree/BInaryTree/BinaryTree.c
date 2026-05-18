#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lc, * rc;
}BiTNode, * BiTree;

BiTree Create()
{
	BiTree t;
	char ch;
	scanf(" %c", &ch);
	if (ch == '#') t = NULL;
	else
	{
		t = (BiTree)malloc(sizeof(BiTNode));
		t->data = ch;
		t->lc = Create();
		t->rc = Create();
	}
	return t;
}


void PreOrder(BiTree t)
{
	if (t == NULL) 
		return;
	printf("%c ", t->data);
	PreOrder(t->lc);
	PreOrder(t->rc);
}

void InOrder(BiTree t)
{
	if (t == NULL) return;
	InOrder(t->lc);
	printf("%c ", t->data);
	InOrder(t->rc);
}

void PostOrder(BiTree t)
{
	if (t == NULL) return;
	PostOrder(t->lc);
	PostOrder(t->rc);
	printf("%c ", t->data);
}

int Count(BiTree t)
{
	if (t == NULL)
		return 0;
	else if (t)
		return 1 + Count(t->lc) + Count(t->rc);
}

#include"stack.h"
#define StackSize 25
typedef BiTree ElemType;

void PreOrder_I(BiTree t)
{
	SeqStack st;
	BiTNode* p;
	InitStack(&st);
	while (t || !IsStackEmpty(&st))
	{
		if (t)
		{
			printf("%c ", t->data);
			Push(&st, t);
			t = t->lc;
		}
		else
		{
			Pop(&st, &p);
			t = p->rc;
		}
	}
}

void InOrder_I(BiTree t)
{
	SeqStack st;
	BiTNode* p;
	InitStack(&st);
	while (t || !IsStackEmpty(&st))
	{
		if (t)
		{
			Push(&st, t);
			t = t->lc;
		}
		else
		{
			Pop(&st, &p);
			printf("%c ", p->data);
			t = p->rc;
		}
	}
}

int Max(int x, int y)
{
	return (x > y ? x : y);
}

int Height(BiTree t)
{
	if (t == NULL) return 0;
	if (t->lc == NULL && t->rc == NULL) return 1;
	
	return 1 + Max(Height(t->lc), Height(t->rc));
}

//叶子节点的个数
int cnt_zero = 0;
void NodeZero(BiTree t)
{
	if (t == NULL) return;
	if (t->lc == NULL && t->rc == NULL) cnt_zero++;
	NodeZero(t->lc);
	NodeZero(t->rc);
}

int cnt_one = 0;
void NodeOne(BiTree t)
{
	if (t == NULL) return;
	if((t->lc == NULL && t->rc != NULL) || (t->rc == NULL && t->lc != NULL)) 
	cnt_one++;
	NodeOne(t->lc);
	NodeOne(t->rc);
}

int cnt_two = 0;
int NodeTwo(BiTree t)
{
	if (t == NULL) return;
	if (t->lc != NULL && t->rc != NULL)
		cnt_two++;
	NodeTwo(t->lc);
	NodeTwo(t->rc);
}
#include"queue.h"

typedef BiTree QElemType;
#define QueueSize 25
void BFS(BiTree t)
{
	SeqQueue q;
	InitQueue(&q);
	EnterQueue(&q, t);
	while (!IsEmptyQueue(&q))
	{
		BiTNode* p;
		DeleteQueue(&q, &p);
		printf("%c ", p->data);
		if (p->lc != NULL) EnterQueue(&q, p->lc);
		if (p->rc != NULL) EnterQueue(&q, p->rc);
	}
}

int main()
{
	BiTree root;
	root = Create();
	printf("前序遍历:");
	PreOrder(root);
	printf("\n");
	printf("中序遍历:");
	InOrder(root);
	printf("\n");
	printf("后序遍历:");
	PostOrder(root);
	printf("\n节点个数:%d\n", Count(root));
	printf("非递归前序遍历:");
	PreOrder_I(root);
	printf("\n非递归中序遍历:");
	InOrder_I(root);
	printf("\n树的高度为:%d\n", Height(root));
	printf("层序遍历:");
	BFS(root);
	cnt_zero = 0;
	NodeZero(root);
	printf("\n度为零的结点个数:%d\n", cnt_zero);
	cnt_one = 0;
	NodeOne(root);
	printf("\n度为一的结点个数:%d\n", cnt_one);
	cnt_two = 0;
	NodeTwo(root);
	printf("\n度为二的结点个数:%d\n", cnt_two);
	return 0;
}