#pragma once

#include<stdio.h>

#include<stdlib.h>
typedef int QElemType;
#define QueueSize 10010
#define TRUE 1
#define FALSE 0


typedef struct
{
	QElemType elem[QueueSize];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue* Q);
int EnterQueue(SeqQueue* Q, QElemType e);
int DeleteQueue(SeqQueue* Q, QElemType* e);
int IsEmptyQueue(SeqQueue* Q);
int IsFullQueue(SeqQueue* Q);
int GetHead(SeqQueue* Q, QElemType* e);
int GetTail(SeqQueue* Q, QElemType* e);