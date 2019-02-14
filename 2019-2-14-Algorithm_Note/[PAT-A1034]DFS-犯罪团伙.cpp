#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

const int maxn=2000;
const int INF = 1e9;

map<int, string> inttostring;
map<string, int> stringtoint;
map<string,int> Gang;       //建立犯罪头目和组人数间的映射关系，且map内自动按第一个键从小到大排序，方便输出

int G[maxn][maxn]={0}, weight[maxn]={0}; //邻接矩阵表示图，weight用来存放每个人的点权（个人总通话时长）
int n,k,numPerson=0; //边数n，下限k，总人数numPerson
bool vis[maxn]={false}; //标记是否被访问


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
        if(G[nowVisit][i]>0)    //如果是同组的
        {
            totalValue+=G[nowVisit][i]; //计算总权
            G[nowVisit][i]=G[i][nowVisit]=0;    //删除这条边防止回头，保证一条边只算一次
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
            DFS(i, head, numMember, totalValue);    //遍历i所在的连通块，寻找头目，计算组权重和组人数
            if(numMember>2 && totalValue>k)
            {
                Gang[inttostring[head]]=numMember;
            }
        }
    }
}


//返回姓名str对应的编号
int change(string str)
{
    if(stringtoint.find(str)!=stringtoint.end())    //如果string已经出现过
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
    printf("请输入边数和下限：");
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d组通话人员和时长：",i+1);
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