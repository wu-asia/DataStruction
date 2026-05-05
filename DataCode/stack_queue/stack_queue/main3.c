//#include"stack.h"
//#include<ctype.h>
//
//
//int priority[6][6] =
//{
//	//       +  -   *   /   (  )  
//	/* + */ {1, 1, -1, -1, -1, 1},
//	/* - */ {1, 1, -1, -1, -1, 1},
//	/* * */ {1, 1,  1,  1, -1, 1},
//	/* / */ {1, 1,  1,  1, -1, 1},
//	/* ( */ {-1,-1,-1, -1, -1, 0},
//	/* ) */ {1, 1,  1,  1,  1, 1}
//};
//
//int IsOperator(char ch)
//{
//    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
//        return 1;
//    else
//        return 0;
//}
//
//int index(char ch, char* operation)
//{
//	int i = 0;
//	while (ch != operation[i])
//		i++;
//	return i;
//}
//void InfixToPostfix(char* infix, char* postfix, char* operation, int priority[6][6], int* a, int* b)
//{
//    SeqStack s;
//    InitStack(&s);
//    int i = 0, j = 0;
//    ElemType e;
//
//    while (infix[i] != '\0')
//    {
//        // 1. 如果是字母，直接输出到后缀
//        if (isalpha(infix[i])) 
//        {
//            postfix[j++] = infix[i++];
//        }
//        // 2. 如果是运算符
//        else if (IsOperator(infix[i]))
//        {
//            while (1)
//            {
//                // 栈空，直接入栈
//                if (IsStackEmpty(&s))
//                {
//                    Push(&s, infix[i]);
//                    i++;
//                    break;
//                }
//
//                // 取栈顶运算符
//                GetTop(&s, &e);
//                int row = index(e, operation);
//                int col = index(infix[i], operation);
//                int pri = priority[row][col];
//
//                if (pri == 1)
//                {
//                    // 栈顶优先级高 → 出栈输出
//                    Pop(&s, &e);
//                    postfix[j++] = e;
//                }
//                else if (pri == -1)
//                {
//                    // 当前优先级高 → 入栈
//                    Push(&s, infix[i]);
//                    i++;
//                    break;
//                }
//                else
//                {
//                    // pri == 0：遇到 ( 和 ) 匹配，弹出 ( 不输出
//                    Pop(&s, &e);
//                    i++;
//                    break;
//                }
//            }
//        }
//        else
//        {
//            // 跳过空格等非法字符
//            i++;
//        }
//        *a = i;
//        *b = j;
//    }
//    while (!IsStackEmpty(&s))
//    {
//        Pop(&s, &e);
//        postfix[j] = e;
//        j++;
//    }
//    postfix[j] = '\0';
//    *b = j;
//}
////void function(char* infix, char* postfix, char* operation, int priority[10][10])
////{
////	SeqStack s;
////	InitStack(&s);
////	int i = 0, j = 0;
////	while (infix[i] != '\0')
////	{
////		if (isalpha(infix[i]))
////		{
////			postfix[j] = infix[i];
////			i++;
////			j++;
////		}
////		else
////		{
////			if (IsOperator(infix[i]))
////			{
////				ElemType e;
////				GetTop(&s, &e);
////				int row = index(e, operation);
////				int col = index(infix[i], operation);
////				int getPriority = priority[row][col];
////				if (getPriority == 1)
////				{
////					Pop(&s, &e);
////					postfix[j] = e;
////					j++;
////				}
////				else if (getPriority == -1)
////				{
////					Push(&s, infix[i]);
////					i++;
////				}
////				else
////				{
////					Pop(&s, &e);
////					i++;
////				}
////			}
////		}
////	}
////	//prefix[i] = '\0';
////}
//int main()
//{
//    char infix[100], postfix[100];
//    char operation[] = "+-*/()";
//    int a, b;
//    scanf("%s", infix);
//    InfixToPostfix(infix, postfix, operation, priority, &a, &b);
//    
//    for (int i = 0; i < a; i++)
//        printf("%c", infix[i]);
//    printf("\n");
//    for (int i = 0; i < b; i++)
//        printf("%c", postfix[i]);
//
//	return 0;
//}