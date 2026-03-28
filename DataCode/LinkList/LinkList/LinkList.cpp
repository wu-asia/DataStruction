#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define ERROR 0
#define FINE 1
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          next;
}Node, *LinkList;

void InitiList(LinkList* L);
int HeadInsElem(LinkList L, ElemType e);
int TailInsElem(LinkList L, ElemType* e);
void VisitList(LinkList L);
int main()
{
	LinkList l1;
	InitiList(&l1);
	HeadInsElem(l1, 10);
	HeadInsElem(l1, 20);
	HeadInsElem(l1, 5);

	return 0;
}

void InitiList(LinkList* L)
{
	*L = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
}

int  HeadInsElem(LinkList L, ElemType e)
{
	Node* s;
	s = (Node*)malloc(sizeof(Node));
	if (!s) return ERROR;
	s->data = e;
	s->next = L->next;
	L->next = s;
	return FINE;
}

int TailInsElem(LinkList L, ElemType* e)
{

}

void VisitList(LinkList L)
{
	for(Node* s = L; s->next; s = s->next)
		std::cout << 
}