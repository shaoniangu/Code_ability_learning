#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

struct node
{
    double num;
    char op;
    bool flag;
};

string str; //读入存储中缀表达式
stack<node> s;  //操作符栈
queue<node> q;  //后缀表达式序列
map<char, int> op;  //操作符优先级map

void Change()
{
    double num;
    node temp;
    for(int i=0;i<str.length();)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            temp.flag=true;
            temp.num=str[i++]-'0';
            while(i<str.length() && str[i]>='0' && str[i]<='9')
            {
                temp.num = temp.num*10 + (str[i]-'0');
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag=false;
            while(!s.empty() && op[str[i]]<=op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double Cal()
{
    double temp1, temp2;
    node cur, temp;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.flag==true)
        {
            s.push(cur);
        }
        else
        {
            temp2=s.top().num;
            s.pop();
            temp1=s.top().num;
            s.pop();
            temp.flag=true;
            switch (cur.op)
            {
                case '+':temp.num=temp1+temp2;break;
                case '-':temp.num=temp1-temp2;break;
                case '*':temp.num=temp1*temp2;break;
                case '/':temp.num=temp1/temp2;break;
                default:printf("Unsupported operator %c!", cur.op);
            }
            s.push(temp);
        }
    }
    return s.top().num;
}
int main()
{
    op['+']=op['-']=0;
    op['*']=op['/']=1;
    printf("请输入中缀表达式：");
    getline(cin, str);
    for(string::iterator it=str.end(); it!=str.begin();it--)
    {
        if(*it == ' '){
            str.erase(it);
        }
    }
    while(!s.empty())
        s.pop();
    Change();
    cout<<str<<"=";
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<Cal();
    return 0;
}