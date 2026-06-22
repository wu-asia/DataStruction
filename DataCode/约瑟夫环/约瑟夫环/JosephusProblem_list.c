#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node, * list;

list create(int n)
{
	node* head = NULL;
	node* tail = NULL;
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = tail;
	tail->data = n;
	tail->next = head;
	for (int i = n - 1; i >= 2; i--)
	{
		node* t = (node*)malloc(sizeof(node));
		t->data = i;
		t->next = head->next;
		head->next = t;
	}
	return head;
}

int josephus_circle(list head, int m)
{
	node* p = head;
	node* pre = p;
	//直接找到链表的尾结点
	while (pre->next != p)
		pre = pre->next;
	while(p != p->next)
	{
		for (int i = 1; i < m; i++)
		{
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		node* tmp = p;
		p = p->next;
		free(tmp);
	}
	int ret = p->data;
	free(p);
	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	node* head = create(n);
	int ret = josephus_circle(head, m);
	printf("%d", ret);
	return 0;
}