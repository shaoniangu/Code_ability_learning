#include <stdio.h>

bool dumplicate(int *array, int num, int * dumplication)
{
    if(array==NULL || num==0)
        return false;
    for(int i=0;i<num;i++)
    {
        if(array[i]<0 || array[i]>num-1)
            return false;
    }

    for(int i=0;i<num;i++)
    {
        while(array[i]!=i)
        {
            if(array[i] == array[array[i]])
            {
                *dumplication = array[i];
                return true;
            }
            int temp=array[i];
            array[i]=array[array[i]];
            array[temp]=temp;
        }
    }
    return false;
}


int main()
{
    int num=7, array[num]={2,3,1,0,2,5,3}, dumplication=-1;
    bool ifdumplicate = dumplicate(array, num, &dumplication);
    if(ifdumplicate)
    {
        printf("Yes, the first dumplication is %d", dumplication);
    }
    else
    {
        printf("No dumplication!");
    }
}