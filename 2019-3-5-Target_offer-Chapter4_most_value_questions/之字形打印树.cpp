#include <cstdio>
#include <stack>
#include "../2019-2-12-Algorithm_Note/根据先序和中序序列求树.cpp"
using namespace std;

typedef struct node * tree;

void zhiprint(tree root)
{
    if(root==NULL)
    {
        printf("空树！\n");
        return;
    }

    stack<tree> s[2];
    int current =0,next=1;
    s[current].push(root);
    while(!s[0].empty() || !s[1].empty())
    {
        tree temp=s[current].top();
        s[current].pop();
        printf("%d", temp->data);

        if(current==0)
        {
            if(temp->left!=NULL)
            {
                s[next].push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s[next].push(temp->right);
            }
        }
        else
        {
            if(temp->right!=NULL)
            {
                s[next].push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s[next].push(temp->left);
            }
        }

        if(s[current].empty())
        {
            printf("\n");
            current=1-current;
            next=1-next;
        }
    }
}


int main()
{
    node * root=create(0,5,0,5);
    printf("层序遍历序列：");
    layerorder(root);
    printf("\n");

    zhiprint(root);
    return 0;
}