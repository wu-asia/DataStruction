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
}Node, * LinkList;

//显示菜单
void ShowMenu();
//操作函数
void operation(LinkList L);
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
//判断链表是否局部有环
int CheckListWithCircle(LinkList L);
//对链表进行排序
void SortLinkWithSelection(LinkList L);
//逆置链表
int ReverseLink(LinkList L);
//找出链表中的倒数第几个元素
Node* FindTheLastCountElem(LinkList L, int i);
int main()
{
	LinkList L1;
	InitiList(&L1);  // 初始化链表
	//int choice;     // 用户选择的操作编号
	//ElemType e;
	//int pos;
	//Node* resNode;
	operation(L1);
	LinkList L2;
	InitiList(&L2);
	operation(L2);
	LinkList L3;
	InitiList(&L3);
	ReverseMergeTwoLinkLists(L1, L2, L3);
	return 0;
}

void ShowMenu() 
{
	printf("========== 单链表操作界面 ==========\n");
	printf("==========1.  头插元素   ==========\n");
	printf("==========2.  尾插元素   ==========\n");
	printf("==========3.遍历打印链表 ==========\n");
	printf("==========4.  头删元素   ==========\n");
	printf("==========5.  尾删元素   ==========\n");
	printf("==========6.指定位置后插入元素==========\n");
	printf("==========7.指定位置前插入元素==========\n");
	printf("==========8.删除指定位置元素==========\n");
	printf("==========9.按位置查找元素==========\n");
	printf("==========10.按值查找元素位置==========\n");
	printf("==========11.检测链表是否有环==========\n");
	printf("==========12.链表选择排序==========\n");
	printf("==========13.链表逆置==========\n");
	printf("==========14.查找倒数第k个元素==========\n");
	printf("==========0.退出程序==========\n");
	printf("===================================\n");
	printf("请输入操作序号：");
}

void operation(LinkList L)//操作器，可以在主函数中仅仅定义并初始化链表即可
{
	int choice = 0;
	ElemType e;
	int pos = 0;
	Node* resNode;
	// 循环监听用户输入，实现持续交互
	while (1)
	{
		ShowMenu();    // 显示菜单
		scanf("%d", &choice);

		// switch匹配操作，调用对应函数
		switch (choice) 
		{
		case 1:
			printf("请输入头插元素值：");
			scanf("%d", &e);
			HeadInsElem(L, e) ? printf("头插成功！\n") : printf("头插失败！\n");
			break;

		case 2:
			printf("请输入尾插元素值：");
			scanf("%d", &e);
			TailInsElem(L, e) ? printf("尾插成功！\n") : printf("尾插失败！\n");
			break;

		case 3:
			printf("链表元素：");
			VisitList(L);
			break;

		case 4:
			if (HeadDelElem(L, &e))
				printf("头删成功，删除元素：%d\n", e);
			else
				printf("链表为空，头删失败！\n");
			break;

		case 5:
			if (TailDelElem(L, &e))
				printf("尾删成功，删除元素：%d\n", e);
			else
				printf("链表为空，尾删失败！\n");
			break;

		case 6:
			printf("请输入插入位置：");
			scanf("%d", &pos);
			printf("请输入元素值：");
			scanf("%d", &e);
			InsElemWithPosBehind(L, e, pos);
			break;

		case 7:
			printf("请输入插入位置：");
			scanf("%d", &pos);
			printf("请输入元素值：");
			scanf("%d", &e);
			InsElemWithPosFront(L, e, pos);
			break;

		case 8:
			printf("请输入删除位置：");
			scanf("%d", &pos);
			if (DelElemWithPos(L, &e, pos))
				printf("删除成功，元素值：%d\n", e);
			break;

		case 9:
			printf("请输入查找位置：");
			scanf("%d", &pos);
			try 
			{
				e = FindElemWithPos(L, pos);
				printf("位置%d的元素：%d\n", pos, e);
			}
			catch (...) 
			{
				printf("位置非法，查找失败！\n");
			}
			break;

		case 10:
			printf("请输入要查找的值：");
			scanf("%d", &e);
			pos = FindElemWithValue(L, e);
			pos == -1 ? printf("未找到该元素！\n") : printf("元素位置：%d\n", pos);
			break;

		case 11:
			CheckListWithCircle(L) ? printf("链表有环！\n") : printf("链表无环！\n");
			break;

		case 12:
			SortLinkWithSelection(L);
			printf("链表排序完成！\n");
			break;

		case 13:
			ReverseLink(L);
			printf("链表逆置完成！\n");
			break;

		case 14:
			printf("请输入倒数k值：");
			scanf("%d", &pos);
			resNode = FindTheLastCountElem(L, pos);
			printf("倒数第%d个元素：%d\n", pos, resNode->data);
			break;

		case 0:
			printf("程序已退出！\n");
			return;

		default:
			printf("输入错误，请重新输入！\n");
		}
	}
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
	Node* p = L->next;
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
	while (cnt != 0 && p != NULL)
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

int CheckListWithCircle(LinkList L)
{
	//利用快慢指针来解决是否有环
	if (!L->next || !L) return 0;
	Node* slow = L;
	Node* quick = L;
	while (quick && quick->next)
	{
		slow = slow->next;
		quick = quick->next->next;
		if (slow == quick)
		{
			return 1;
		}
	}
	return 0;
}

void SortLinkWithSelection(LinkList L)
{
	//使用直接插入排序，对链表进行排序
	if (!L->next || !L) return;
	for (Node* p = L->next; p; p = p->next)
	{
		Node* min = p;
		for (Node* q = p->next; q; q = q->next)
		{
			if (min->data > q->data)
			{
				min = q;
			}
		}
		ElemType tmp = p->data;
		p->data = min->data;
		min->data = tmp;
	}
}

int ReverseLink(LinkList L)
{
	if (L->next == NULL || L->next->next == NULL)
		return 0;
	Node* p = L->next->next;
	L->next->next = NULL;
	for (; p;)
	{
		Node* tmp = p->next;
		p->next = L->next;
		L->next = p;
		p = tmp;
	}
}

Node* FindTheLastCountElem(LinkList L, int i)
{
	Node* p = L->next;
	Node* pre = L->next;
	int cnt = 0;
	while (p)
	{
		if (cnt >= i)
		{
			pre = pre->next;
		}
		p = p->next;
		cnt++;
	}
	return pre;
}

void ReverseMergeTwoLinkLists(LinkList l1, LinkList l2, LinkList l3)
{
	Node* p1 = l1->next;
	Node* p2 = l2->next;
	while (p1 && p2)
	{
		if (p1->data < p2->data)
		{
			Node* tmp = p1->next;
			p1->next = l3->next;
			l3->next = p1;
			p1 = tmp;
		}
		else
		{
			Node* tmp = p2->next;
			p2->next = l3->next;
			l3->next = p2;
			p2 = tmp;
		}
	}
	while (p1)
	{
		Node* tmp = p1->next;
		p1->next = l3->next;
		l3->next = p1;
		p1 = tmp;
	}
	while (p2)
	{
		Node* tmp = p2->next;
		p2->next = l3->next;
		l3->next = p2;
		p2 = tmp;
	}
	l1->next = NULL;
	l2->next = NULL;
}

void MergeTwoLinkLists(LinkList l1, LinkList l2, LinkList l3)
{
	Node* p1 = l1->next;
	Node* p2 = l2->next;
	while (p1 && p2)
	{

	}
}