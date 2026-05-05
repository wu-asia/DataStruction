#include "stack.h"

void InitStack(SeqStack* s)
{
	s->top = -1;
}

int IsStackEmpty(SeqStack* s)
{
	if (s->top == -1) return 1;
	else return 0;
}

int IsStackFull(SeqStack* s)
{
	if (s->top == StackSize - 1) return 1;
	else return 0;
}

int Push(SeqStack* s, ElemType x)
{
	if (s->top + 1 >= StackSize) 
		return FALSE;
	s->elem[++s->top] = x;
	return TRUE;
}

int Pop(SeqStack* s, ElemType* e)
{
	if (s->top == -1) return FALSE;
	*e = s->elem[s->top--];
	return TRUE;
}

int GetTop(SeqStack* s, ElemType* e)
{
	if (s->top == -1) return FALSE;
	*e = s->elem[s->top];
	return TRUE;
}