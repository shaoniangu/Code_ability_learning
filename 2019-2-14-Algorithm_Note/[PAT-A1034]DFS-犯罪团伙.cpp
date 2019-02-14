#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

const int maxn=2000;
const int INF = 1e9;

map<int, string> inttostring;
map<string, int> stringtoint;
map<string,int> Gang;       //��������ͷĿ�����������ӳ���ϵ����map���Զ�����һ������С�������򣬷������

int G[maxn][maxn]={0}, weight[maxn]={0}; //�ڽӾ����ʾͼ��weight�������ÿ���˵ĵ�Ȩ��������ͨ��ʱ����
int n,k,numPerson=0; //����n������k��������numPerson
bool vis[maxn]={false}; //����Ƿ񱻷���


void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
    numMember++;
    vis[nowVisit]=true;
    if(weight[nowVisit]>weight[head])
    {
        head=nowVisit;
    }

    for(int i=0;i<numPerson;i++)
    {
        if(G[nowVisit][i]>0)    //�����ͬ���
        {
            totalValue+=G[nowVisit][i]; //������Ȩ
            G[nowVisit][i]=G[i][nowVisit]=0;    //ɾ�������߷�ֹ��ͷ����֤һ����ֻ��һ��
            if(vis[i]==false)
            {
                DFS(i,head,numMember,totalValue);
            }
        }
    }
}


void DFSTravel()
{
    for(int i=0;i<numPerson;i++)
    {
        if(vis[i]==false)
        {
            int head=i,numMember=0,totalValue=0;
            DFS(i, head, numMember, totalValue);    //����i���ڵ���ͨ�飬Ѱ��ͷĿ��������Ȩ�غ�������
            if(numMember>2 && totalValue>k)
            {
                Gang[inttostring[head]]=numMember;
            }
        }
    }
}


//��������str��Ӧ�ı��
int change(string str)
{
    if(stringtoint.find(str)!=stringtoint.end())    //���string�Ѿ����ֹ�
    {
        return stringtoint[str];
    }
    else
    {
        stringtoint[str]=numPerson;
        inttostring[numPerson]=str;
        return numPerson++;
    }
}

int main()
{
    int w;
    string str1,str2;
    printf("��������������ޣ�");
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        printf("�������%d��ͨ����Ա��ʱ����",i+1);
        cin>>str1>>str2>>w;
        int id1=change(str1);
        int id2=change(str2);
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2]+=w;
        G[id2][id1]+=w;
    }

    DFSTravel();
    cout<<Gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=Gang.begin();it!=Gang.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}