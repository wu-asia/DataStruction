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
//
//int main()
//{
//	String s;
//	InitString(&s);
//	char ch[] = "abcdefghigklm";
//	StrAssign(&s, ch);
//	StrVisit(&s);
//
//	return 0;
//}
//
//
//void InitString(String* s)
//{
//	s->len = 1;
//}
//
//void StrAssign(String* s, char chars[])
//{
//	int i = 0;
//	while (chars[i] != '\0')
//	{
//		s->ch[i] = chars[i];
//	}
//	s->len = i - 1;
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
//		print("%c", s->ch[i]);
//}