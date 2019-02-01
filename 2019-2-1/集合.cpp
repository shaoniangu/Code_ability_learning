#define MAXN 1000
typedef int ElementType;
typedef int SetName;
ElementType SetType[MAXN];


SetName Find(SetType S,ElementType X)
{
    for(;S[X]>=0;X=S[X]);
    return X;
}

//���⣺��������Խ��Խ�ߣ�Ҳ��ζ��ĳ��Ԫ�صĲ�ѯ·����Խ��Խ��
void Union(SetType S, SetName Root1, SetName Root2)
{
    S[Root2]=Root1;
}

//���ڵ㲻�ٴ�-1�����Ǵ漯�ϸ������෴����Ȼ��ÿ�ζ��Ѹߵ����ӵ���������
void Union(SetType S, SetName Root1, SetName Root2)
{
    if(S[Root2]<S[Root1])
    {
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }
    else
    {
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}

// ·��ѹ������һ���ҵ�ʱ������䰫����һ��ֻ��Ҫ2�αȽ�
SetName Find(SetType S, ElementType X)
{
    if(S[X]<0)
        return X;
    else
    {
        return S[X]=Find(S, S[x]); //·��ѹ��
    }
}

