#include <stdio.h>

#define MAXSIZE 100

// 学生结构体
typedef struct
{
    int id;         // 学号
    char name[20];  // 姓名
    float score;    // 总成绩
} Student;

// 顺序查找
int SequentialSearch(Student stu[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (stu[i].id == key)
            return i;
    }
    return -1;
}

// 折半查找
int BinarySearch(Student stu[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (stu[mid].id == key)
            return mid;
        else if (stu[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// 输出学生信息
void PrintStudent(Student s)
{
    printf("学号：%d\n", s.id);
    printf("姓名：%s\n", s.name);
    printf("总成绩：%.2f\n", s.score);
}

int main()
{
    Student stu[MAXSIZE];
    int n;

    printf("请输入学生人数：");
    scanf("%d", &n);

    printf("请按学号从小到大输入学生信息：\n");

    for (int i = 0; i < n; i++)
    {
        printf("第%d个学生：\n", i + 1);

        printf("学号：");
        scanf("%d", &stu[i].id);

        printf("姓名：");
        scanf("%s", stu[i].name);

        printf("总成绩：");
        scanf("%f", &stu[i].score);
    }

    int key;

    printf("\n请输入要查找的学号：");
    scanf("%d", &key);

    // 顺序查找
    printf("\n顺序查找\n");

    int pos = SequentialSearch(stu, n, key);

    if (pos != -1)
    {
        printf("查找成功！\n");
        PrintStudent(stu[pos]);
    }
    else
    {
        printf("查找失败，未找到该学生！\n");
    }

    // 折半查找
    printf("\n折半查找\n");

    pos = BinarySearch(stu, n, key);

    if (pos != -1)
    {
        printf("查找成功！\n");
        PrintStudent(stu[pos]);
    }
    else
    {
        printf("查找失败，未找到该学生！\n");
    }

    return 0;
}