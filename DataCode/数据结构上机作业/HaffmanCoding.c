#include<stdio.h>

// （1）统计文本字符串中不同字符的个数以及各字符在文本中出现的次数；
// （2）按文本字符串中字符的个数以及各字符的次数来建立并输出哈夫曼树；
// （3）设计并输出各字符对应的哈夫曼编码；
// （4）将传输的文本字符串转换成对应的哈夫曼编码01序列；
// （5）将哈夫曼编码生成的01序列翻译成原来的文本字符串。

struct node
{
    char ch;
    int weight;
    int parent;
    int lchild, rchild;
};

int main()
{

    return 0;
}