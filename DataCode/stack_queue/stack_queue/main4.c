//#include"queue.h"
//
//void YangHuiTriangle(int column)
//{
//	SeqQueue q;
//	InitQueue(&q);
//	EnterQueue(&q, 1);
//	for (int i = 2; i <= column; i++)
//	{
//		EnterQueue(&q, 1);
//		for (int j = 1; j <= i - 2; j++)
//		{
//			QElemType e;
//			DeleteQueue(&q, &e);
//			printf(" %d", e);
//			QElemType x;
//			GetHead(&q, &x);
//			e += x;
//			EnterQueue(&q, e);
//		}
//		QElemType x;
//		DeleteQueue(&q, &x);
//		printf(" %d\n", x);
//		EnterQueue(&q, 1);
//	}
//	while (!IsEmptyQueue(&q))
//	{
//		QElemType x;
//		DeleteQueue(&q, &x);
//		printf(" %d", x);
//	}
//	printf("\n");
//}
//int main()
//{
//	YangHuiTriangle(10);
//	return 0;
//}