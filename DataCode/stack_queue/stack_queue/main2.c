////#define StackSize 10010
////typedef char ElemType;
//#include"stack.h"
//int Match(char a, char b)
//{
//	int flag = 0;
//	switch (a)
//	{
//	case '(':
//		if (b == ')')
//			flag = 1;
//		break;
//	case '[':
//		if (b == ']')
//			flag = 1;
//		break;
//	case '{':
//		if (b == '}')
//			flag = 1;
//		break;
//	}
//	return flag;
//}
//int BracketMatch(char* str)
//{
//	ElemType e;
//	SeqStack S;
//	InitStack(&S);
//	int flag = 1, cnt = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		switch (str[i])
//		{
//		case '(':
//		case '[':
//		case '{':
//			cnt++;
//			Push(&S, str[i]);
//			break;
//		case ')':
//		case ']':
//		case '}':
//			cnt++;
//			if (IsStackEmpty(&S))
//			{
//				printf("第%d处的%c无匹配的左括号", cnt, str[i]);
//				flag = 0;
//			}
//			else
//			{
//				Pop(&S, &e);
//				if (!Match(e, str[i]))
//				{
//					printf("第%d个%c与%c不匹配\n", cnt, e, str[i]);
//					flag = 0;
//				}
//			}
//			break;
//		}
//	}
//	return flag;
//}
//int main()
//{
//	ElemType e, str[20];
//	int x, i = 0;
//	scanf("%s", str);
//	x = BracketMatch(str);
//	if (x == 1) printf("表达式中的所有括号都匹配\n");
//	return 0;
//}