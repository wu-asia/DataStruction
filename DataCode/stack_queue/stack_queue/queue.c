#include "queue.h"

//front 指向的数组中的头元素
//rear 指向的数组中的为元素的后一位
void InitQueue(SeqQueue* Q)
{
	Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % QueueSize == Q->front)
		return FALSE;
	Q->elem[Q->rear] = e;
	Q->rear = (Q->rear + 1) % QueueSize;
	return TRUE;
}
int DeleteQueue(SeqQueue* Q, QElemType* e)
{
	if (Q->rear == Q->front)
		return FALSE;
	*e = Q->elem[Q->front];
	Q->front = (Q->front + 1) % QueueSize;
	return TRUE;
}
int IsEmptyQueue(SeqQueue* Q)
{
	if (Q->rear == Q->front) return 1;
	else return 0;
}
int IsFullQueue(SeqQueue* Q)
{
	if ((Q->rear + 1) % QueueSize == Q->front) return 1;
	else return 0;
}
int GetHead(SeqQueue* Q, QElemType* e)
{
	if (IsEmptyQueue(Q)) return FALSE;
	*e = Q->elem[Q->front];
	return TRUE;
}
int GetTail(SeqQueue* Q, QElemType* e)
{
	if (IsEmptyQueue(Q)) return FALSE;
	*e = Q->elem[(Q->rear - 1 + QueueSize) % QueueSize];
	return TRUE;
}