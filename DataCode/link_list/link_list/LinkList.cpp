#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define FINE 1
#define ERROR 0
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node, *LinkList;
//初始化链表
void InitiList(LinkList* L);
//头插元素
int HeadInsElem(LinkList L, ElemType e);
//尾插元素
int TailInsElem(LinkList L, ElemType e);
//访问链表
void VisitList(LinkList L);
//头删元素
int HeadDelElem(LinkList L, ElemType* e);
//尾删元素
int TailDelElem(LinkList L, ElemType* e);
//在当前位置元素前插入元素
int InsElemWithPosBehind(LinkList L, ElemType e, int pos);
//在当前位置元素后插入元素
int InsElemWithPosFront(LinkList L, ElemType e, int pos);
//int DelElemWithPosBehind(LinkList L, ElemType* e, int pos);
//删除当前元素
int DelElemWithPos(LinkList L, ElemType* e, int pos);
//按照位置查找元素
ElemType FindElemWithPos(LinkList L, int pos);
//按照值查找元素
int FindElemWithValue(LinkList L, ElemType e);

int main()
{
	LinkList l1;
	InitiList(&l1);
	HeadInsElem(l1, 10);
	HeadInsElem(l1, 20);
	HeadInsElem(l1, 5);
	HeadInsElem(l1, 30);
	HeadInsElem(l1, 20);
	HeadInsElem(l1, 11);
	HeadInsElem(l1, 12);
	HeadInsElem(l1, 13);
	HeadInsElem(l1, 14);
	HeadInsElem(l1, 15);
	VisitList(l1);
	TailInsElem(l1, 100);
	VisitList(l1);
	ElemType elem;
	HeadDelElem(l1, &elem);
	std::cout << "头删删除元素是：" << elem << std::endl;
	VisitList(l1);
	TailDelElem(l1, &elem);
	std::cout << "尾删删除的元素是:" << elem << std::endl;
	VisitList(l1);
	InsElemWithPosBehind(l1, 99, 2);
	VisitList(l1);
	InsElemWithPosFront(l1, 88, 2);
	VisitList(l1);
	/*DelElemWithPosBehind(l1, &elem, 4);
	std::cout << "删除的元素是：" << elem << std::endl;
	VisitList(l1);*/
	DelElemWithPos(l1, &elem, 5);
	std::cout << "删除位置是：5, " << "删除的元素是：" << elem << std::endl;
	VisitList(l1);
	std::cout << "位置2处的元素是：" << FindElemWithPos(l1, 2) << std::endl;
	std::cout << "查找的元素是99，它的位置是:" << FindElemWithValue(l1, 99) << std::endl;
	return 0;
}

void InitiList(LinkList* L)
{
	*L = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
}

int HeadInsElem(LinkList L, ElemType e)
{
	Node* s;
	s = (Node*)malloc(sizeof(Node));
	if (!s) return ERROR;
	s->data = e;
	s->next = L->next;
	L->next = s;
	return FINE;
}

int TailInsElem(LinkList L, ElemType e)
{
	Node * p = L->next;
	while (p->next) p = p->next;
	Node* s = (Node*)malloc(sizeof(Node));
	if (!s) return ERROR;
	s->data = e;
	s->next = NULL;
	p->next = s;
	return FINE;
}
void VisitList(LinkList L)
{
	for (Node* s = L->next; s; s = s->next)
		std::cout << s->data << " ";
	std::cout << std::endl;
}

int HeadDelElem(LinkList L, ElemType* e)
{
	if (!L->next) return ERROR;
	Node* tmp = L->next;
	*e = tmp->data;
	L->next = tmp->next;
	free(tmp);
	return FINE;
}

int TailDelElem(LinkList L, ElemType* e)
{
	Node* p = L->next;
	if (!p) return ERROR;
	while (p->next->next) p = p->next;
	Node* tmp = p->next;
	*e = tmp->data;
	p->next = NULL;
	free(tmp);
	return FINE;
}

int InsElemWithPosBehind(LinkList L, ElemType e, int pos)
{
	int cnt = pos;
	Node* pre = L;
	//Node* p = L->next;
	while (cnt != 0 && pre->next)
	{
		cnt--;
		pre = pre->next;
	}
	if (!pre->next)
	{
		printf("插入位置错误\n");
		return ERROR;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = pre->next;
	pre->next = s;
	return FINE;
}

int InsElemWithPosFront(LinkList L, ElemType e, int pos)
{
	int cnt = pos - 1;
	Node* pre = L;
	Node* p = L->next;
	while (cnt != 0 && p)
	{
		cnt--;
		pre = pre->next;
		p = p->next;
	}
	if (!p)
	{
		printf("插入位置错误\n");
		return ERROR;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = pre->next;
	pre->next = s;
	return FINE;
}

//int DelElemWithPosBehind(LinkList L, ElemType* e, int pos)
//{
//	int cnt = pos;
//	Node* pre = L;
//	while (cnt != 0 && pre->next)
//	{
//		cnt--;
//		pre = pre->next;
//	}
//	if (!pre->next)
//	{
//		printf("删除位置错误\n");
//		return ERROR;
//	}
//	*e = pre->next->data;
//	Node* tmp = pre->next;
//	pre->next = tmp->next;
//	free(tmp);
//	return FINE;
//}

int DelElemWithPos(LinkList L, ElemType* e, int pos)
{
	int cnt = pos - 1;
	Node* p = L->next;
	Node* pre = L;
	while (cnt != 0 && p)
	{
		cnt--;
		pre = pre->next;
		p = p->next;
	}
	if (!p)
	{
		printf("插入位置错误\n");
		return ERROR;
	}
	*e = p->data;
	Node* tmp = pre->next;
	pre->next = tmp->next;
	free(tmp);
	return FINE;
}

ElemType FindElemWithPos(LinkList L, int pos)
{
	int cnt = pos - 1;
	Node* p = L->next;
	while (cnt != 0 && p!= NULL)
	{
		p = p->next;
		cnt--;
	}
	return (p->data);
}

int FindElemWithValue(LinkList L, ElemType e)
{
	int cnt = 1;
	for (Node* s = L->next; s; s = s->next)
	{
		if (s->data == e)
		{
			return cnt;
		}
		cnt++;
	}
	return -1;
}