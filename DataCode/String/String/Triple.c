an#include<stdio.h>

#define MaxSize 100
typedef int ElemType;
typedef struct
{
	int row;
	int col;
	ElemType val;
}Triple;

typedef struct
{
	Triple arr[MaxSize + 1];
	int n;
	int m;
	int len;
}Matrix;

void CreateMatrix(Matrix* M) 
{
	int i, j, value;
	printf("请输入矩阵的行数和列数：");
	scanf("%d%d", &M->m, &M->n);
	M->len = 0;
	for (i = 1; i <= M->m; i++) 
	{
		for (j = 1; j <= M->n; j++) 
		{
			scanf("%d", &value);
			// 仅存储非零元素
			if (value != 0) 
			{
				M->len++;
				M->arr[M->len].row = i;
				M->arr[M->len].col = j;
				M->arr[M->len].val = value;
			}
		}
	}
}
//输出矩阵
void PrintMatrix(Matrix* M) 
{
	int i, j, k = 1;
	for (i = 1; i <= M->m; i++) 
	{
		for (j = 1; j <= M->n; j++) 
		{
			// 判断当前位置是否为非零元素
			if (k <= M->len && M->arr[k].row == i && M->arr[k].col == j) 
			{
				printf("%d\t", M->arr[k].val);
				k++;
			}
			else 
			{
				printf("0\t");
			}
		}
		printf("\n");
	}
}

void GetRow(Matrix* M, int row)
{
	int j, k = 1;
	printf("第%d行元素：", row);
	for (j = 1; j <= M->n; j++)
	{
		if (k <= M->len && M->arr[k].row == row && M->arr[k].col == j)
		{
			printf("%d ", M->arr[k].val);
			k++;
		}
		else
		{
			printf("0 ");
		}
	}
	printf("\n");
}

ElemType GetElement(Matrix* M, int row, int col)
{
	int k;
	for (k = 1; k <= M->len; k++)
	{
		if (M->arr[k].row == row && M->arr[k].col == col)
		{
			return M->arr[k].val;
		}
	}
	return 0;
}

void TransposeTSMatrix(Matrix* A, Matrix* B)
{
	int i, j, k;
	B->m = A->n;
	B->n = A->m;
	B->len = A->len;
	if (B->len > 0)
	{
		j = 1;
		for (k = 1; k <= A->n; k++)
			for (i = 1; i <= A->len; i++)
			{
				if (A->arr[i].col == k)
				{
					B->arr[j].row = A->arr[i].col;
					B->arr[j].col = A->arr[i].row;
					B->arr[j].val = A->arr[i].val;
					j++;
				}
			}
	}
}

void Fast(Matrix* a, Matrix* b)
{
	int col, t, p, q;
	int num[MaxSize], pos[MaxSize];
	b->len = a->len;
	b->n = a->m;
	b->m = a->n;
	if (b->len)
	{
		for (col = 1; col <= a->n; col++)
		{
			num[col] = 0;
		}
		for (t = 1; t <= a->len; t++)
			num[a->arr[t].col]++;
		pos[1] = 1;
		for (col = 2; col <= a->n; col++)
			pos[col] = pos[col - 1] + num[col - 1];
		for (p = 1; p <= a->len; p++)
		{
			col = a->arr[p].col;
			q = pos[col];
			b->arr[q].row = a->arr[p].col;
			b->arr[q].col = a->arr[p].row;
			b->arr[q].val = a->arr[p].val;
			pos[col]++;
		}
	}

}


void AddMatrix(Matrix* A, Matrix* B, Matrix* C) 
{
	int i = 1, j = 1, k = 1;

	// 行列必须相同才能相加
	if (A->m != B->m || A->n != B->n) 
	{
		printf("矩阵行列数不同，无法相加！\n");
		C->len = 0;
		return;
	}

	C->m = A->m;
	C->n = A->n;

	// 归并法相加
	while (i <= A->len && j <= B->len) 
	{
		// A元素行更小
		if (A->arr[i].row < B->arr[j].row) 
		{
			C->arr[k++] = A->arr[i++];
		}
		// B元素行更小
		else if (A->arr[i].row > B->arr[j].row)
		{
			C->arr[k++] = B->arr[j++];
		}
		// 行相同，比较列
		else 
		{
			if (A->arr[i].col < B->arr[j].col) 
			{
				C->arr[k++] = A->arr[i++];
			}
			else if (A->arr[i].col > B->arr[j].col) 
			{
				C->arr[k++] = B->arr[j++];
			}
			// 行列都相同，值相加
			else 
			{
				int sum = A->arr[i].val + B->arr[j].val;
				if (sum != 0) 
				{
					C->arr[k].row = A->arr[i].row;
					C->arr[k].col = A->arr[i].col;
					C->arr[k].val = sum;
					k++;
				}
				i++;
				j++;
			}
		}
	}

	// 处理剩余元素
	while (i <= A->len)
		C->arr[k++] = A->arr[i++];
	while (j <= B->len)
		C->arr[k++] = B->arr[j++];

	C->len = k;
}

int main()
{
	Matrix M, N, FastN, AddM;
	int row, col, val;

	printf("创建第一个矩阵");
	CreateMatrix(&M);
	printf("输出原始矩阵");
	PrintMatrix(&M);

	// 读取行元素
	printf("\n请输入要读取的行号：");
	scanf("%d", &row);
	GetRow(&M, row);

	// 读取指定位置元素
	printf("请输入要读取的行和列：");
	scanf("%d%d", &row, &col);
	val = GetElement(&M, row, col);
	printf("M[%d][%d] = %d\n", row, col, val);

	// 简单转置
	printf("简单转置矩阵");
	TransposeTSMatrix(&M, &N);
	PrintMatrix(&N);

	// 快速转置
	printf("快速转置矩阵");
	Fast(&M, &FastN);
	PrintMatrix(&FastN);

	// 矩阵相加测试
	printf("创建第二个矩阵（用于相加）");
	CreateMatrix(&N);
	AddMatrix(&M, &N, &AddM);
	printf("矩阵相加结果：");
	PrintMatrix(&AddM);
	return 0;
}