#pragma once

#include<stdio.h>
#include<stdlib.h>

//#define StackSize 10010
//typedef int ElemType;
#define StackSize 10010
typedef char ElemType;
#define TRUE 1
#define FALSE 0
typedef struct
{
	ElemType elem[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack* s);
int IsStackEmpty(SeqStack* s);
int IsStackFull(SeqStack* s);
int Push(SeqStack* s, ElemType x);
int Pop(SeqStack* s, ElemType* e);
int GetTop(SeqStack* s, ElemType* e);