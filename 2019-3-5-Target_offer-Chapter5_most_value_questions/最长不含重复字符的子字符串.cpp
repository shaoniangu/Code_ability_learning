#include <cstdio>
#include <string>
using namespace std;

int longestSubstringWithoutDumplication(string str)
{
    int curlen=0;
    int maxlen=0;

    int position[26]={-1};

    for(int i=0;i<str.length();i++)
    {
        int pre=position[str[i]-'a'];
        if(pre<0 || i-pre>curlen)
        {
            curlen++;
        }
        else
        {
            if(curlen>maxlen)
            {
                maxlen=curlen;
            }   
            curlen=i-pre;
        }
        position[str[i]-'a']=i;
    }
    if(curlen>maxlen)
    {
        maxlen=curlen;
    }
    return maxlen;
}

int main()
{
    string str="arabcacfr";
    int maxlen=longestSubstringWithoutDumplication(str);
    printf("%d", maxlen);
    return 0;
}