#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MaxSize 100
#define ERROR 0
#define FINE 1
typedef int ElemType;
typedef struct List_One
{
	ElemType ele[MaxSize];
	int last;
}List;

//初始化顺序表
void InitiList(List* L);
//创建顺序表
int CreateList(List* L, int n);
//顺序表的访问
void VisitList(List* L);
//顺序表中插入元素
int InsertList(List* L, int pos, ElemType e);
//查找顺序表中的元素(序号)
ElemType FindWithIndex(List* L, int pos/*表示链表中的实际位置*/);
//查找顺序表中的元素(值)
int FindWithElement(List* L, ElemType e);
//删除顺序表中的元素
int DeleteEle(List* L, int index, ElemType* e);
int main()
{
	
	List L1 = { {1, 2, 3, 4}, 3 };
	
	VisitList(&L1);
	/*CreateList(&L1, 4);
	VisitList(&L1);*/
	InsertList(&L1, 1, 1000);
	VisitList(&L1);
	cout << FindWithIndex(&L1, 2) << endl;
	int flag = FindWithElement(&L1, 1000);
	if (flag) cout << "下标是：" << flag << endl;
	else cout << "未能找到" << endl;
	ElemType remain = 0;
	int i = DeleteEle(&L1, 1, &remain);
	if (i) cout << "删除成功,删除的元素是：" << remain << endl;
	else cout << "删除失败" << endl;
	VisitList(&L1);
	return 0;
}

void InitiList(List* L)
{
	L->last = -1;
	//将List中的首元素下标定义为-1，完成初始化
}
int CreateList(List* L, int n)
{
	if (n < 0) return ERROR;
	for (int i = 0; i < n; i++)
		cin >> L->ele[i];
	L->last = n - 1;
	return FINE;
}
void VisitList(List* L)
{
	if (L->last == -1)
		cout << "empty List" << endl;
	for (int i = 0; i <= L->last; i++)
		cout << L->ele[i] << " ";
	cout << endl;
}

int InsertList(List* L, int pos, ElemType e)
{
	if (pos < 0 || pos > L->last + 1) return ERROR;

	for (int i = L->last; i >= pos; i--)
		L->ele[i + 1] = L->ele[i];
	L->ele[pos] = e;
	L->last++;
	return FINE;
}

ElemType FindWithIndex(List* L, int pos)
{
	if (pos <= 0 || pos > L->last + 1)
	{
		cout << "未能找到" << endl;
		return ERROR;
	}
	return (L->ele[pos - 1]);
}

int FindWithElement(List* L, ElemType e)
{
	int i = 0;
	while (i < L->last && L->ele[i] != e)
		i++;
	if (i > L->last) return ERROR;
	else return i;
}

int DeleteEle(List* L, int index, ElemType* e)
{
	if (index < 0 || index > L->last)
		return ERROR;
	*e = L->ele[index];
	for (int i = index + 1; i <= L->last; i++)
		L->ele[i - 1] = L->ele[i];
	L->last--;
	return FINE;

}