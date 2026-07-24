#include <stdio.h>
#include <string.h>

#define HASHSIZE 101

// 员工信息结构体
typedef struct
{
    int id;             // 工号
    char name[30];      // 姓名
    char dept[30];      // 部门
    int state;          // 0-空 1-已使用 2-已删除
} Employee;

// 哈希表
Employee HashTable[HASHSIZE];

// 初始化哈希表
void InitHashTable()
{
    int i;
    for(i = 0; i < HASHSIZE; i++)
    {
        HashTable[i].state = 0;
    }
}

// 哈希函数（除留余数法）
int Hash(int key)
{
    return key % HASHSIZE;
}

// 查找员工
int Search(int id)
{
    int addr = Hash(id);
    int start = addr;

    while(HashTable[addr].state != 0)
    {
        if(HashTable[addr].state == 1 &&
           HashTable[addr].id == id)
        {
            return addr;
        }

        addr = (addr + 1) % HASHSIZE;

        if(addr == start)
            break;
    }

    return -1;
}

// 添加员工
void Insert()
{
    Employee e;

    printf("请输入工号：");
    scanf("%d", &e.id);

    if(Search(e.id) != -1)
    {
        printf("工号已存在！\n");
        return;
    }

    printf("请输入姓名：");
    scanf("%s", e.name);

    printf("请输入部门：");
    scanf("%s", e.dept);

    int addr = Hash(e.id);
    int start = addr;

    while(HashTable[addr].state == 1)
    {
        addr = (addr + 1) % HASHSIZE;

        if(addr == start)
        {
            printf("哈希表已满！\n");
            return;
        }
    }

    HashTable[addr] = e;
    HashTable[addr].state = 1;

    printf("添加成功！\n");
}

// 查找员工信息
void Find()
{
    int id;

    printf("请输入要查找的工号：");
    scanf("%d", &id);

    int pos = Search(id);

    if(pos == -1)
    {
        printf("未找到该员工！\n");
    }
    else
    {
        printf("\n找到员工信息：\n");
        printf("工号：%d\n", HashTable[pos].id);
        printf("姓名：%s\n", HashTable[pos].name);
        printf("部门：%s\n", HashTable[pos].dept);
    }
}

// 删除员工
void Delete()
{
    int id;

    printf("请输入要删除的工号：");
    scanf("%d", &id);

    int pos = Search(id);

    if(pos == -1)
    {
        printf("员工不存在！\n");
        return;
    }

    HashTable[pos].state = 2;

    printf("删除成功！\n");
}

// 遍历哈希表
void Traverse()
{
    int i;
    printf("哈希地址\t工号\t姓名\t部门\n");
    for(i = 0; i < HASHSIZE; i++)
    {
        if(HashTable[i].state == 1)
        {
            printf("%3d\t\t%d\t%s\t%s\n",
                   i,
                   HashTable[i].id,
                   HashTable[i].name,
                   HashTable[i].dept);
        }
    }
}

// 菜单
void Menu()
{
    printf("\n");
    printf("员工信息管理系统\n");
    printf("1. 添加员工\n");
    printf("2. 查找员工\n");
    printf("3. 删除员工\n");
    printf("4. 遍历员工\n");
    printf("0. 退出系统\n");
    printf("请选择：");
}

int main()
{
    int choice;

    InitHashTable();

    while(1)
    {
        Menu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Insert();
                break;

            case 2:
                Find();
                break;

            case 3:
                Delete();
                break;

            case 4:
                Traverse();
                break;

            case 0:
                printf("程序结束！\n");
                return 0;

            default:
                printf("输入错误，请重新选择！\n");
        }
    }

    return 0;
}