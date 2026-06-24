#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct
{
    char ch;        // 字符
    int weight;     // 权值(频率)

    int parent;
    int lchild;
    int rchild;

} HTNode;

// 统计字符频率
void CountChar(char str[], char chars[], int freq[], int *count)
{
    *count = 0;

    for (int i = 0; str[i]; i++)
    {
        int found = -1;

        for (int j = 0; j < *count; j++)
        {
            if (chars[j] == str[i])
            {
                found = j;
                break;
            }
        }

        if (found == -1)
        {
            chars[*count] = str[i];
            freq[*count] = 1;
            (*count)++;
        }
        else
        {
            freq[found]++;
        }
    }
}

// 选两个最小权值结点
void Select(HTNode ht[], int end, int *s1, int *s2)
{
    *s1 = *s2 = 0;

    for (int i = 1; i <= end; i++)
    {
        if (ht[i].parent != 0)
            continue;

        if (*s1 == 0 || ht[i].weight < ht[*s1].weight)
            *s1 = i;
    }

    for (int i = 1; i <= end; i++)
    {
        if (ht[i].parent != 0 || i == *s1)
            continue;

        if (*s2 == 0 || ht[i].weight < ht[*s2].weight)
            *s2 = i;
    }

    if (ht[*s1].weight > ht[*s2].weight)
    {
        int t = *s1;
        *s1 = *s2;
        *s2 = t;
    }
}

// 建立哈夫曼树
void CreateHuffmanTree(HTNode ht[], char chars[], int freq[], int n)
{
    int m = 2 * n - 1;

    for (int i = 1; i <= m; i++)
    {
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
        ht[i].weight = 0;
        ht[i].ch = '\0';
    }

    for (int i = 1; i <= n; i++)
    {
        ht[i].ch = chars[i - 1];
        ht[i].weight = freq[i - 1];
    }

    for (int i = n + 1; i <= m; i++)
    {
        int s1, s2;

        Select(ht, i - 1, &s1, &s2);

        ht[s1].parent = i;
        ht[s2].parent = i;

        ht[i].lchild = s1;
        ht[i].rchild = s2;

        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}

// 输出哈夫曼树
void PrintTree(HTNode ht[], int m)
{
    printf("\n哈夫曼树：\n\n");

    printf("编号\t字符\t权值\t双亲\t左孩子\t右孩子\n");

    for (int i = 1; i <= m; i++)
    {
        printf("%d\t", i);

        if (ht[i].ch)
            printf("%c\t", ht[i].ch);
        else
            printf("-\t");

        printf("%d\t%d\t%d\t%d\n", ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }
}

// 生成哈夫曼编码
void CreateCode(HTNode ht[], char HC[][MAXSIZE], int n)
{
    char code[MAXSIZE];

    for (int i = 1; i <= n; i++)
    {
        int start = MAXSIZE - 1;

        code[start] = '\0';

        int c = i;
        int p = ht[c].parent;

        while (p)
        {
            if (ht[p].lchild == c)
                code[--start] = '0';
            else
                code[--start] = '1';

            c = p;
            p = ht[c].parent;
        }

        strcpy(HC[i], &code[start]);
    }
}

// 输出编码
void PrintCode(char chars[], char HC[][MAXSIZE], int n)
{
    printf("\n哈夫曼编码：\n\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%c : %s\n", chars[i - 1], HC[i]);
    }
}

// 编码
void Encode(char str[], char chars[], char HC[][MAXSIZE], int n, char result[])
{
    result[0] = '\0';

    for (int i = 0; str[i]; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i] == chars[j - 1])
            {
                strcat(result, HC[j]);
                break;
            }
        }
    }
}

// 译码
void Decode(HTNode ht[], int root, char code[])
{
    printf("\n译码结果：\n");

    int p = root;

    for (int i = 0; code[i]; i++)
    {
        if (code[i] == '0')
            p = ht[p].lchild;
        else
            p = ht[p].rchild;

        if (ht[p].lchild == 0 &&
            ht[p].rchild == 0)
        {
            printf("%c", ht[p].ch);
            p = root;
        }
    }

    printf("\n");
}

void Menu()
{
    // 打印菜单
    printf("1. 统计字符的个数以及字符出现的次数\n");
    printf("2. 建立并输出哈夫曼树\n");
    printf("3. 设计并输出哈夫曼编码\n");
    printf("4. 将文本转换成01编码\n");
    printf("5. 将01编码翻译成文本\n");
    printf("0. 退出\n");
    printf("请选择0-5：");
}
int main()
{
    int choice = 0;
    char str[MAXSIZE];
    char chars[MAXSIZE];
    int freq[MAXSIZE];
    int count;
    HTNode ht[2 * MAXSIZE];
    char HC[MAXSIZE][MAXSIZE];
    char codeResult[1000];
    // 标记是否已经初始化数据
    int hasData = 0;
    while (1)
    {
        Menu();
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("程序退出！\n");
            break;
        }

        if (choice == 1)
        {
            // 1、输入字符串 + 统计频率
            printf("请输入字符串：");
            scanf("%s", str);
            CountChar(str, chars, freq, &count);
            hasData = 1;

            printf("\n字符频率统计：\n\n");
            for (int i = 0; i < count; i++)
            {
                printf("%c : %d\n", chars[i], freq[i]);
            }
        }
        else
        {
            // 2~5必须先执行1录入数据
            if (!hasData)
            {
                printf("错误：请先选择1录入字符串并统计字符！\n");
                continue;
            }
            if (choice == 2)
            {
                // 2、建树并输出树表
                CreateHuffmanTree(ht, chars, freq, count);
                PrintTree(ht, 2 * count - 1);
            }
            else if (choice == 3)
            {
                // 3、生成并输出编码
                CreateHuffmanTree(ht, chars, freq, count);
                CreateCode(ht, HC, count);
                PrintCode(chars, HC, count);
            }
            else if (choice == 4)
            {
                // 4、原文转为01串
                CreateHuffmanTree(ht, chars, freq, count);
                CreateCode(ht, HC, count);
                Encode(str, chars, HC, count, codeResult);
                printf("\n编码结果：\n%s\n", codeResult);
            }
            else if (choice == 5)
            {
                // 5、01串译码
                CreateHuffmanTree(ht, chars, freq, count);
                CreateCode(ht, HC, count);
                Encode(str, chars, HC, count, codeResult);
                Decode(ht, 2 * count - 1, codeResult);
            }
            else
            {
                printf("输入选项无效，请输入0~5！\n");
            }
        }
    }
    return 0;
}
