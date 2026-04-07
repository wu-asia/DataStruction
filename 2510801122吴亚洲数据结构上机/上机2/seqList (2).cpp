#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<time.h>

typedef int ElemType;
const int MaxSize = 1000;
#define FINE 1
#define ERROR 0
typedef struct
{
	ElemType data[MaxSize];
	int last;
}SeqList;
//菜单
void menu();
//顺序表的初始化
void InitiList(SeqList* list);
//插入元素
int InsElement(SeqList* list, ElemType e, int pos);
//删除元素
int DelElement(SeqList* list, ElemType* e, int pos);
//遍历顺序表
void VisitList(SeqList* list);
//顺序表长度
int ListLength(SeqList* list);
//逆置顺序表
void ReverseList(SeqList* list);
//排序
void SortList(SeqList* list);
int get_random_pos(int left, int right);
void Swap(ElemType* e1, ElemType* e2);
void quick_sort(ElemType arr[], int left, int right);
//合并两个有序顺序表
void MergeList(SeqList* list1, SeqList* list2);
//批量插入元素
int InsNElements(SeqList* list, int num, int pos, ElemType arr[], int sz);
//批量删除元素
int main()
{
	srand((unsigned int)time(NULL));
	SeqList l1;
	InitiList(&l1);
	SeqList l2 = { { 2, 3, 2, 1 }, 3 };
	l1 = { {1, 2, 3}, 2 };
	int input = 0;
	while (1)
	{
		menu();
		printf("请输入选项:>");
		scanf("%d", &input);
		if (!input) break;
		switch (input)
		{
		case 0:
			printf("退出\n");
			break;
		case 1:
			printf("插入l1中的元素和位置:>");
			ElemType elem1;
			int p1;
			std::cin >> elem1 >> p1;
			InsElement(&l1, elem1, p1);
			break;
		case 2:
			printf("插入l2中的元素和位置:>");
			ElemType elem2;
			int p2;
			std::cin >> elem2 >> p2;
			InsElement(&l2, elem2, p2);
			break;
		case 3:
			printf("删除l1中元素的位置:>");
			int p_one;
			ElemType elem_one;
			std::cin >> p_one >> elem_one;
			DelElement(&l1, &elem_one, p_one);
			std::cout << "删除的元素是：" << elem_one << std::endl;
			break;
		case 4:
			printf("删除l2中的元素的位置:>");
			int p_two;
			ElemType elem_two;
			std::cin >> p_two >> elem_two;
			DelElement(&l2, &elem_two, p_two);
			std::cout << "删除的元素是：" << elem_two << std::endl;
			break;
		case 5:
			printf("顺序表l1的长度为：%d\n", ListLength(&l1));
			break;
		case 6:
			printf("顺序表l2的长度为：%d\n", ListLength(&l2));
			break;
		case 7:
			ReverseList(&l1);
			break;
		case 8:
			ReverseList(&l2);
			break;
		case 9:
			SortList(&l1);
			break;
		case 10:
			SortList(&l2);
			break;
		case 11:
			MergeList(&l1, &l2);
			break;
		case 12:
			MergeList(&l2, &l1);
			break;
		case 13:
			VisitList(&l1);
			break;
		case 14:
			VisitList(&l2);
			break;
		}
	}

	VisitList(&l1);
	InsElement(&l1, 1000, 1);
	VisitList(&l1);
	printf("%d\n", ListLength(&l1));
	InsElement(&l1, 99, l1.last + 1);
	VisitList(&l1);
	SortList(&l1);
	VisitList(&l1);

	SortList(&l2);
	MergeList(&l1, &l2);
	VisitList(&l2);
	VisitList(&l1);
	return 0;
}

void menu()
{
	printf("===============================================\n");
	printf("                顺序表管理系统                \n");
	printf("===============================================\n");
	printf("   0 退出系统               13 遍历顺序表l1      \n");
	printf("   1 l1插入单个元素         14 遍历顺序表l2      \n");
	printf("   2 l2插入单个元素         15 l1批量插入元素    \n");
	printf("   3 l1删除单个元素         16 l1批量删除元素    \n");
	printf("   4 l2删除单个元素         17 l1奇偶分离排序    \n");
	printf("   5 查看l1长度                                \n");
	printf("   6 查看l2长度                                \n");
	printf("   7 逆置l1                                    \n");
	printf("   8 逆置l2                                    \n");
	printf("   9 排序l1                                    \n");
	printf("  10 排序l2                                    \n");
	printf("  11 合并到l1                                  \n");
	printf("  12 合并到l2                                  \n");
	printf("==============================================\n");
}
//void menu()
//{
//	printf("0 退出\n");
//	printf("1 顺序表l1中插入元素\n");
//	printf("2 顺序表l2中插入元素\n");
//	printf("3 顺序表l1中删除元素\n");
//	printf("4 顺序表l2中删除元素\n");
//	printf("5 查看顺序表l1的长度\n");
//	printf("6 查看顺序表l2的长度\n");
//	printf("7 逆置顺序表l1\n");
//	printf("8 逆置顺序表l2\n");
//	printf("9 排序顺序表l1\n");
//	printf("10 排序顺序表l2\n");
//	printf("11 合并两个有序顺序表(合并在l1)\n");
//	printf("12 合并两个有序顺序表(合并在l2)\n");
//	printf("13 访问顺序表l1\n");
//	printf("14 访问顺序表l2\n");
//}

void InitiList(SeqList* list)
{
	list->last = -1;
}

int InsElement(SeqList* list, ElemType e, int pos)
{
	if (pos < 0 || pos > list->last + 1 || list->last + 2 > MaxSize) return ERROR;
	for (int i = list->last; i >= pos; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[pos] = e;
	list->last++;
	return FINE;
}

int DelElement(SeqList* list, ElemType* e, int pos)
{
	if (pos < 0 || pos > list->last) return ERROR;
	*e = list->data[pos];
	for (int i = pos + 1; i < list->last; i++)
	{
		list->data[i - 1] = list->data[i];
	}
	list->last--;
	return FINE;
}
void VisitList(SeqList* list)
{
	if (list->last == -1) printf("顺序表为空\n");
	for (int i = 0; i <= list->last; i++)
	{
		std::cout << list->data[i] << " ";
	}
	std::cout << std::endl;
}

int ListLength(SeqList* list)
{
	return list->last + 1;
}

void ReverseList(SeqList* list)
{
	for (int i = 0, j = list->last; i < j; i++, j--)
	{
		ElemType tmp = list->data[i];
		list->data[i] = list->data[j];
		list->data[j] = tmp;
	}
}

void SortList(SeqList* list)
{
	quick_sort(list->data, 0, list->last);
}

int get_random_pos(int left, int right)
{
	return (rand() % (right - left + 1) + left);
}

void Swap(ElemType* e1, ElemType* e2)
{
	ElemType tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}
void quick_sort(ElemType arr[], int left, int right)
{
	//设定结束条件
	if (left >= right) return;
	int pos = get_random_pos(left, right);
	ElemType elem = arr[pos];
	//合并两个有序数组
	int cur = left, cur1 = left - 1, cur2 = right + 1;
	while (cur < cur2)
	{
		if (arr[cur] < elem) Swap(&arr[++cur1], &arr[cur++]);
		else if (arr[cur] == elem) cur++;
		else Swap(&arr[cur], &arr[--cur2]);
	}
	//[left, cur1], [cur1 + 1, cur2 - 1], [cur2, right]
	quick_sort(arr, left, cur1);
	quick_sort(arr, cur2, right);
}

void MergeList(SeqList* list1, SeqList* list2)
{
	int cur1 = list1->last;
	int cur2 = list2->last;
	int cur = cur1 + cur2 + 1;
	while (cur1 > 0 && cur2 > 0)
	{
		if (list1->data[cur1] >= list2->data[cur2])
			list1->data[cur--] = list1->data[cur1--];
		else
			list1->data[cur--] = list2->data[cur2--];
	}
	while (cur2 > 0)
		list1->data[cur--] = list2->data[cur2--];
	list1->last = list1->last + list2->last + 1;
}

int InsNElements(SeqList* list, int num, int pos, ElemType arr[], int sz)
{
	if (pos < 0 || pos > list->last + 1 || num + list->last + 1 > MaxSize) return ERROR;
	for (int i = list->last; i >= pos; i--)
	{
		list->data[i + pos] = list->data[i];
	}
	for (int i = pos; i < sz + pos; i++)
	{
		list->data[i] = arr[i];
	}
	list->last += num;
	return FINE;
}

int DelNElements(SeqList* list, int num, int pos)
{
	if (pos < 0 || pos > list->last || list->last + 1 - num < 0) return ERROR;
	for (int i = pos + 1; i <= list->last; i++)
	{
		list->data[i] = list->data[i + num];
	}
	list->last -= num;
	return ERROR;
}

void SortListWithEvenAndOdd(SeqList* list)
{
	int left = 0;
	int right = list->last;
	while (left < right)
	{
		ElemType* left_e = &list->data[left];
		ElemType* right_e = &list->data[right];
		if (*left_e % 2 == 0 && *right_e % 2 == 1)
		{
			Swap(left_e, right_e);
			left++;
			right--;
		}
		else if (*left_e % 2 == 0 && *right_e % 2 != 1)
			right--;
		else if (*left_e % 2 != 0 && *right_e % 2 == 1)
			left++;
		else
		{
			right--;
			left++;
		}
	}
}
