#define MAXN 1000
typedef int ElementType;
typedef int SetName;
ElementType SetType[MAXN];


SetName Find(SetType S,ElementType X)
{
    for(;S[X]>=0;X=S[X]);
    return X;
}

//问题：集合树会越来越高，也意味着某个元素的查询路径会越来越长
void Union(SetType S, SetName Root1, SetName Root2)
{
    S[Root2]=Root1;
}

//根节点不再存-1，而是存集合个数的相反数，然后每次都把高的树加到矮的树上
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

// 路径压缩，第一次找的时候把树变矮，下一次只需要2次比较
SetName Find(SetType S, ElementType X)
{
    if(S[X]<0)
        return X;
    else
    {
        return S[X]=Find(S, S[x]); //路径压缩
    }
}

