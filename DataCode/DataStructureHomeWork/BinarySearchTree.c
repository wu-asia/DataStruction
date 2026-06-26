#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

//二叉搜索树结点
typedef struct BSTNode
{
    char word[MAXWORD];
    int count;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef BSTNode* BSTree;

// 创建新结点
BSTNode* CreateNode(char *word)
{
    BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));

    strcpy(node->word, word);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}
 
// 查找
BSTNode* Search(BSTree root, char *word)
{
    if(root == NULL)
        return NULL;

    int cmp = strcmp(word, root->word);

    if(cmp == 0)
        return root;
    else if(cmp < 0)
        return Search(root->left, word);
    else
        return Search(root->right, word);
}

// 插入
BSTree Insert(BSTree root, char *word)
{
    if(root == NULL)
        return CreateNode(word);

    int cmp = strcmp(word, root->word);

    if(cmp == 0)
    {
        root->count++;
    }
    else if(cmp < 0)
    {
        root->left = Insert(root->left, word);
    }
    else
    {
        root->right = Insert(root->right, word);
    }

    return root;
}

// 中序遍历
void InOrder(BSTree root)
{
    if(root == NULL)
        return;

    InOrder(root->left);

    printf("%-15s %d\n", root->word, root->count);

    InOrder(root->right);
}

// 将单词转换为小写
void ToLower(char *word)
{
    for(int i=0;word[i];i++)
        word[i]=tolower(word[i]);
}

// 从文件读取
void ReadFile(BSTree *root, char *filename)
{
    FILE *fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        return;
    }

    char word[MAXWORD];
    int index=0;
    int ch;

    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            word[index++]=tolower(ch);
        }
        else
        {
            if(index>0)
            {
                word[index]='\0';

                *root=Insert(*root,word);

                index=0;
            }
        }
    }

    // 文件最后一个单词
    if(index>0)
    {
        word[index]='\0';
        *root=Insert(*root,word);
    }

    fclose(fp);
}

// 释放树
void Destroy(BSTree root)
{
    if(root==NULL)
        return;

    Destroy(root->left);
    Destroy(root->right);

    free(root);
}

int main()
{
    BSTree root=NULL;

    ReadFile(&root,"text.txt");

    printf("单词统计结果：\n\n");
    printf("%-15s%s\n","Word","Count");
    InOrder(root);

    Destroy(root);

    return 0;
}