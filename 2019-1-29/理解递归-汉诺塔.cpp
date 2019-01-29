# include <stdio.h>

void move(int n, int start, int goal, int temp)
{
    if(n>=1)
    {
        move(n-1, start, temp, goal);
        printf("Move disk %d from %d to %d.\n", n, start, goal);
        move(n-1, temp, goal, start);
    }
}


int main()
{
    move(3,1,3,2);
}