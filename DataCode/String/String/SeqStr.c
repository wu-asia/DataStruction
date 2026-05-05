//#include<stdio.h>
//#include<stdlib.h>
//
//#define ERROR 0
//#define FINE 1
//#define MaxSize 100
//typedef struct
//{
//	char ch[MaxSize];
//	int len;
//}String;
////初始化字符串
//void InitString(String* s);
////赋值运算
//void StrAssign(String* s, char chars[]);
////字符串的插入
//int StrInsert(String* s, int pos, String* t);
////字符串的删除
//int StrDelete(String* s, int pos, int len);
////字符串的访问
//void StrVisit(String* s);
////简单模式串匹配
//int SimpleMatch(String* str, String* substr);
//void GetNext(String* s, int next[]);
////kmp算法
//int kmp(String* str, String* substr, int next[]);
////获取nextval数组
//void GetNextVal(String* s, int next[], int nextval[]);
////kmp算法(nextval版)
//int kmp_val(String* str, String* substr, int nextval[]);
//
//int main()
//{
//	String s;
//	InitString(&s);
//	char ch[] = "abaababaa";
//	StrAssign(&s, ch);
//	StrVisit(&s);
//	String substr;
//	InitString(&substr);
//	char subch[] = "def";
//	StrAssign(&substr, subch);
//	StrVisit(&substr);
//	printf("%d\n", SimpleMatch(&s, &substr));
//	int next[100] = { 0 };
//	GetNext(&substr, next);
//	for (int i = 0; i < substr.len; i++)
//		printf("%d ", next[i]);
//	printf("\n");
//
//	int next1[100] = { 0 };
//	int nextval[100] = { 0 };
//
//	GetNext(&substr, next1);       // 先求 next
//	GetNextVal(&substr, next1, nextval);  // 再求 nextval
//
//	int ret = kmp_val(&s, &substr, nextval);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//
//void InitString(String* s)
//{
//	s->len = 0;
//}
//
//void StrAssign(String* s, char chars[])
//{
//	int i = 0;
//	while (chars[i] != '\0')
//	{
//		s->ch[i] = chars[i];
//		i++;
//	}
//	s->len = i;
//}
//
//int StrInsert(String* s, int pos, String* t)
//{
//	if (pos < 0 || pos > s->len)
//	{
//		printf("插入位置不合法\n");
//		return ERROR;
//	}
//	//主串的位置充足
//	if (s->len + t->len <= MaxSize)
//	{
//		for (int i = s->len + t->len + 1; i >= t->len + pos; i--)
//			s->ch[i] = s->ch[i - t->len];
//		for (int i = 0; i < t->len; i++)
//			s->ch[i + pos] = t->ch[i];
//		s->len = s->len + t->len;
//	}
//	//主串只能放下全部附串和部分主串
//	if (pos + t->len <= MaxSize)
//	{
//		for (int i = MaxSize - 1; i > t->len - 1; i--)
//			s->ch[i] = s->ch[i - t->len];
//		for (int i = 0; i < t->len; i++)
//			s->ch[i + pos] = t->ch[i];
//		s->len = MaxSize;
//	}
//	//主串只能放下附串的部分
//	else
//	{
//		for (int i = pos; i < MaxSize; i++)
//			s->ch[i] = t->ch[i - pos];
//		s->len = MaxSize;
//	}
//	return FINE;
//}
//
//int StrDelete(String* s, int pos, int len)
//{
//	if (pos < 0 || pos > s->len)
//	{
//		printf("删除位置错误!\n");
//		return ERROR;
//	}
//	for (int i = pos; i < len + pos; i++)
//	{
//		s->ch[i] = s->ch[i + len];
//	}
//	s->len = s->len - len;
//	return FINE;
//}
//
//void StrVisit(String* s)
//{
//	for (int i = 0; i < s->len; i++)
//		printf("%c", s->ch[i]);
//	printf("\n");
//}
//
//int SimpleMatch(String* str, String* substr)
//{
//	int j = 0, i = 0;
//	while (i < str->len && j < substr->len)
//	{
//		if (str->ch[i] == substr->ch[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			i = i - j + 1;
//			j = 0;
//		}
//	}
//	if (j == substr->len)
//		return i - j;
//	else
//		return -1;
//}
//
//void GetNext(String* s, int next[])
//{
//	next[0] = -1;
//	int j = 0;
//	for (int i = 1; i < s->len;)
//	{
//		if (j == -1 || s->ch[i] == s->ch[j])
//		{
//			j++;
//			i++;
//			next[i] = j;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//}
//
//int kmp(String* str, String* substr, int next[])
//{
//	int i = 0;
//	int j = 0;
//	while (i < str->len && j < substr->len)
//	{
//		if (j == -1 || str->ch[i] == substr->ch[j])
//		{
//			j++;
//			i++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j == substr->len)
//		return i - j;
//	return -1;
//}
//
//
////求 kmp 优化版 nextval 数组
//void GetNextVal(String* s, int next[], int nextval[])
//{
//	nextval[0] = -1;
//	for (int i = 1; i < s->len; i++)
//	{
//		if (s->ch[i] == s->ch[next[i]])
//			nextval[i] = nextval[next[i]];
//		else
//			nextval[i] = next[i];
//	}
//}
//
//// kmp 匹配算法 —— 使用 nextval
//int kmp_val(String* str, String* substr, int nextval[])
//{
//	int i = 0;
//	int j = 0;
//	while (i < str->len && j < substr->len)
//	{
//		if (j == -1 || str->ch[i] == substr->ch[j])
//		{
//			j++;
//			i++;
//		}
//		else
//		{
//			j = nextval[j];
//		}
//	}
//	if (j == substr->len)
//		return i - j;
//	return -1;
//}