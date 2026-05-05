////注意：调用这个主函数时，需要将ElemTpye的值换成int类型
//
//#define StackSize 10010
//typedef int ElemType;
//#include"stack.h"
//#include"queue.h"
//void converse(int n, int base)
//{
//	SeqStack S;
//	InitStack(&S);
//	while (n)
//	{
//		Push(&S, n % base);
//		n /= base;
//	}
//	while (!IsStackEmpty(&S))
//	{
//		ElemType e;
//		Pop(&S, &e);
//		printf("%d", e);
//	}
//}
//int main()
//{
//	int n, base;
//	printf("请输入一个数字和要转换的进制：");
//	scanf("%d %d", &n, &base);
//	converse(n, base);
//	return 0;
//}
////另一种解决方法，使用的递归调用，底层原理还是栈的调用
//#include<stdio.h>
//
//void converse(int num, int base)
//{
//	if (num == 0)
//		return;
//	else
//	{
//		converse(num / base, base);
//		printf("%d", num % base);
//	}
//}
//int main()
//{
//	int num = 0, base = 0;
//	scanf("%d %d", &num, &base);
//	converse(num, base);
//	return 0;
//}