#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct Student)
#define len sizeof(struct Course)
struct Course
{
    int num;
    char name[10];
    int credit;
    char teacher[20];
    int max;
    int selected;
    struct Course* next;
}cou[10], * head = &cou[0];
struct student
{
    int stunum;
    int num[10];
    int counum;
}stu[5] = {
    {1001, { 1,2,5,7,8 }, 5 },
    {1002, { 1,3,6,7 }, 4 },
    {},
    {},
    {}
};
int i, j, k = 8, flag;

void init()
{
    cou[0].num = 1; strcpy(cou[0].name, "yuwen"); cou[0].credit = 3; strcpy(cou[0].teacher, "Lihua"); cou[0].max = 100; cou[0].selected = 23;
    cou[1].num = 2; strcpy(cou[1].name, "shuxue"); cou[1].credit = 3; strcpy(cou[1].teacher, "Zhangliang"); cou[1].max = 150; cou[1].selected = 19;
    cou[2].num = 3; strcpy(cou[2].name, "yingyu"); cou[2].credit = 3; strcpy(cou[2].teacher, "Tony"); cou[2].max = 200; cou[2].selected = 37;
    cou[3].num = 4; strcpy(cou[3].name, "wuli"); cou[3].credit = 2; strcpy(cou[3].teacher, "wangfeng"); cou[3].max = 50; cou[3].selected = 41;
    cou[4].num = 5; strcpy(cou[4].name, "huaxue"); cou[4].credit = 2; strcpy(cou[4].teacher, "wulei"); cou[4].max = 60; cou[4].selected = 39;
    cou[5].num = 6; strcpy(cou[5].name, "lishi"); cou[5].credit = 1; strcpy(cou[5].teacher, "liuyang"); cou[5].max = 70; cou[5].selected = 55;
    cou[6].num = 7; strcpy(cou[6].name, "dili"); cou[6].credit = 1; strcpy(cou[6].teacher, "pengfei"); cou[6].max = 60; cou[6].selected = 58;
    cou[7].num = 8; strcpy(cou[7].name, "zhengzhi"); cou[7].credit = 2; strcpy(cou[7].teacher, "liuzheng"); cou[7].max = 100; cou[7].selected = 86;
    cou[8].num = 9; strcpy(cou[8].name, "tiyu"); cou[8].credit = 1; strcpy(cou[8].teacher, "wangfeng"); cou[8].max = 50; cou[8].selected = 43;
    for (i = 0; i < k; i++)
    {
        j = i + i;
        cou[i].next = &cou[j];
    }
    cou[8].next = NULL;
    stu[0].stunum = 1001, stu[0].num = { 1,2,5,7,8 }, stu[0].counum = 5;
    stu[1].stunum = 1002, stu[1].num = { 1,3,6,7 }, stu[1].counum = 4;
    stu[2].stunum = 1003, stu[2].num = { 1,2,3,6,8,9 }, stu[2].counum = 5;
    stu[3].stunum = 1004, stu[3].num = { 1,2,5,7,8 }, stu[0].counum = 5;
    stu[4].stunum = 1005, stu[4].num = { 2,6,7 }, stu[0].counum = 3;
    stu[5].stunum = 1006, stu[5].num = { 1,4,6,9 }, stu[0].counum = 4;
}

void selectedcourses(void)
{
    scanf("%d", &k);
    for (i = 0; i < 6; i++)
        if (stu[i].stunum == k)break;
    printf("已选课程列表：\n");
    for (j = 0, k = 0; j < stu[i].counum; j++)
    {
        printf("%d %s  ", cou[stu[i].num[j]].num, cou[stu[i].num[j]].name);
        k = k + cou[stu[i].num[j]].credit;
    }
    printf("\n");
    printf("总学分为：%d\n", k);
}
void optionalcourses(void)
{
    scanf("%d", &k);
    for (i = 0; i < 6; i++)
        if (stu[i].stunum == k)break;
    printf("可选课程列表：\n");
    for (j = 0; j < 9; j++)
    {
        flag = 0;
        for (k = 0; k < stu[i].counum; k++)
            if (stu[i].num[k] == j)
                flag = 1;
        if (flag == 0)
            printf("%d %s  ", cou[j].num, cou[j].name);
    }
    printf("\n");
}
void selectcourses()
{
    scanf("%d%d",j,k);
}
int main()
{
    init();
    selectedcourses();
    return 0;
}