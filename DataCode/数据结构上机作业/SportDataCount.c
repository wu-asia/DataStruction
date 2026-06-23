#include<stdio.h>
#include<string.h>

#define MaxN 21
#define MaxM 50

int n, m, w;
//n所学校，m个男子项目，w个女子项目
//男子编号1-m，女子编号m+1 - m+w
int eventCnt;

//score[i][j]表示学校和事件
int score[MaxN][MaxM];

int maleEvent[MaxM];
int femaleEvent[MaxM];
int eventType[MaxM];
//积分赛的积分规制，前三个和前五个
int point3[3] = {5, 3, 2};
int point5[5] = {7, 5, 3, 2, 1}; 

typedef struct
{
    int id;
    int total;
    int male;
    int female;
} School;

School sch[MaxN];

//对sch初始化
void init()
{
    memset(score, 0, sizeof(score));
    for(int i = 1; i <= n; i++)
    {
        sch[i].id = i;
        sch[i].total = 0;
        sch[i].male = 0;
        sch[i].female = 0;
    }
}

//录入单个项目的成绩

void inputEvent(int eid, int type, int IsMale)
{
    int k, school;
    eventType[eid] = type;
    for(int i = 1; i <= type; i++)
    {
        scanf("%d", &school);
        //判断积分规则
        int add = 0;
        if(type == 3)
            add = point3[i - 1];
        else
            add = point5[i - 1];
        score[school][eid] += add;
    }
    if(IsMale) maleEvent[eid] = 1;
    else femaleEvent[eid] = 1;
}

//录入所有项目
void input()
{
    eventCnt = m + w;
    for(int i = 1; i <= eventCnt; i++)
    {
        int type = 0;
        //3 或者 5
        scanf("%d", &type);
        //i <= m时，是男生，返回值是1，否则为0
        inputEvent(i, type, i <= m);
    }
}

//统计总分
void calc()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= eventCnt; j++)
        {
            sch[i].total += score[i][j];

            if(maleEvent[i])
                sch[i].male += score[i][j];
            else
                sch[i].female += score[i][j];
        }
    }
}

//按照序号输出
void printById()
{
    printf("按照学号输出：\n");
    for(int i = 1; i <= n; i++)
        printf("school %d : total=%d, male=%d, female=%d\n", sch[i].id, sch[i].total, sch[i].male, sch[i].female);
}

//冒泡排序
void sortByTotal()
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(sch[i].total < sch[j].total)
            {
                //交换
                School tmp = sch[i];
                sch[i] = sch[j];
                sch[j] = tmp;
            }
        }
    }
    printf("按照总分：\n");
    printById();
}
//按照男女排序
void sortByGender()
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if((sch[i].male + sch[i].female) < (sch[j].female + sch[j].male))
            {
                School tmp = sch[i];
                sch[i] = sch[j];
                sch[j] = tmp;
            }
        }
    }
    printf("按照男女团体积分:\n");
    printById();
}

void querySchool(int id)
{
    printf("查询学校:\n");
    for(int i = 1; i <= eventCnt; i++)
    {
        printf("Event%d : %d\n", i, score[id][i]);
    }
}
void queryEvent(int eid)
{
    printf("查询项目\n");
    printf("得分最高的学校:");
    for(int i = 1; i <= eventCnt; i++)
    {
        if(score[i][eid] > 0)
        {
            printf("school %d: %d\n", i, score[i][eid]);
        }
    }
}
int main()
{
    printf("分别依次输入n, m, w :");
    scanf("%d %d %d", &n, &m, &w);
    init();
    input();
    calc();
    printById();
    sortByTotal();
    sortByGender();

    //查询
    int sid, eid;
    printf("输入学校id和事件id:\n");
    scanf("%d %d", &sid, &eid);

    querySchool(sid);
    queryEvent(eid);

    return 0;
}