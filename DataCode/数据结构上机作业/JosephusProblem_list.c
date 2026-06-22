#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node, * list;

//创建一个循环链表，里面有n个节点，节点的data是1到n
list create(int n)
{
    //如果只有一个人，则直接返回一个节点
	if (n == 1)
	{
		node* head = (node*)malloc(sizeof(node));
		head->data = 1;
		head->next = head;
		return head;
	}
    //如果有多个人，则创建一个循环链表
	node* head = NULL;
	node* tail = NULL;
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = tail;
	tail->data = n;
	tail->next = head;
    //从n-1开始，使用头插法创建一个循环链表
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
        //当数到第m个时，该节点删除
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