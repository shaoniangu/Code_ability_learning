#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student
{
    char id[15];
    int score;
    int location_number;
    int local_rank;
}stu[100];

bool cmp(Student a, Student b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.id,b.id)<0;
}

int main()
{
    int n,k,num=0;
    printf("请输入考场数：");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("请输入考场%d内人数:",i);
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            printf("请输入考生%d的id和分数，用空格隔开：", j+1);
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number=i;
            num++;
        }
        sort(stu+num-k, stu+num, cmp);
        stu[num-k].local_rank=1;
        for(int j=num-k+1;j<num;j++)
        {
            if(stu[j].score==stu[j-1].score)
            {
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else
            {
                stu[j].local_rank=j+1-(num-k);
            }
        }
    }
    printf("Total student num: %d\n", num);
    sort(stu,stu+num,cmp);
    int r=1;
    for(int i=0;i<num;i++)
    {
        if(i>0 && stu[i].score!=stu[i-1].score)
            r=i+1;
        printf("%s ",stu[i].id);
        printf("%d %d %d\n", r, stu[i].location_number,stu[i].local_rank);
    }
    return 0;
}