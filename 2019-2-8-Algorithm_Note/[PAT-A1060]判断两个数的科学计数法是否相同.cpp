#include <iostream>
#include <string>

using namespace std;

int n;

string deal(string s, int* e)
{
    int k=0;
    while (s.length()>0 && s[0]=='0')
    {
        s.erase(s.begin());
    }

    if (s[0]=='.')
    {
        s.erase(s.begin());
        while(s.length()>0 && s[0]=='0')
        {
            s.erase(s.begin());
            (*e)--;
        }
    }
    else
    {
        while(k<s.length() && s[k]!='.')
        {
            k++;
            (*e)++;
        }
    }

    if(s.length()==0)
    {
        (*e)=0;
    }
    // ���϶�����ȥ��ǰ���㡢��Դ���1��С��1�����������ָ������ȥ��С����


    int num =0;
    string res;
    while(num<n)
    {
        if(num<s.length()) res +=s[num++];
        else
        {
            res+='0';
            num++;
        }
    }
    return res;
}

int main()
{
    string s1,s2,res1, res2;
    int e1=0,e2=0;
    cout<<"��������Чλ�����������֣��ÿո������";
    cin>>n>>s1>>s2;
    res1=deal(s1,&e1);
    res2=deal(s2,&e2);

    if(res1==res2 && e1==e2)
    {
        cout<<"YES 0."<<res1<<"*10^"<<e1<<endl;
    }
    else
    {
        cout<<"No 0."<<res1<<"*10^"<<e1<<"\tNo 0."<<res2<<"*10^"<<e2<<endl;
    }
    return 0;
}