 #include <stdio.h>

 int month[12][2]={{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

 bool isRunnian(int year)
 {
     return (year % 4==0 && year%100!=0) || (year%400==0);
 }

//算法笔记Page-92的解法
 int CalculateGap1(int year1, int year2, int month1, int month2, int day1, int day2)
 {
     int answer=0;
     while(year1<year2 || month1<month2 || day1<day2)
     {
         day1++;
         if(day1==month[month1-1][isRunnian(year1)]+1)
         {
             month1++;
             day1=1;
         }
         if(month1==13)
         {
             year1++;
             month1=1;
         }
        answer++;
     }
     return answer;
 }

// 若两个年份间隔很远，中间的每年循环365/366次其实很浪费，修改代码如下
 int CalculateGap2(int year1, int year2, int month1, int month2, int day1, int day2)
 {
     int answer=0;
     if(year1==year2)
     {
         return CalculateGap1(year1,year2,month1,month2,day1,day2);
     }
     answer+=CalculateGap1(year1,year1+1,month1,1,day1,1);//第一年的后续天数加上
     answer+=CalculateGap2(year2,year2,1,month2,1,day2);//第二年的天数加上
     //中间年的天数加上
     for(int year=year1+1;year<=year2-1;year++)
    {
        if(isRunnian(year))
        {
            answer+=366;
        }
        else
        {
            answer+=365;
        }
    }
    return answer;
 }



 int main()
 {
     int time1,year1,month1,day1;
     int time2,year2,month2,day2;

     printf("请输入日期1：");
     scanf("%d",&time1);
     printf("请输入日期2：");
     scanf("%d",&time2);

     if(time1>time2)
     {
         int temp=time1;
         time1=time2;
         time2=temp;
     }
     year1=time1/10000;
     month1=time1%10000/100;
     day1=time1%100;

     year2=time2/10000;
     month2=time2%10000/100;
     day2=time2%100;
    
    int answer1=CalculateGap1(year1,year2,month1,month2,day1,day2);
    printf("The gap1 between two dates is: %d\n", answer1);
    int answer2=CalculateGap2(year1,year2,month1,month2,day1,day2);
    printf("The gap2 between two dates is: %d\n", answer2);
    return 0; 
 }