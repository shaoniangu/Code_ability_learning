#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

int pre[6]={1,2,4,5,3,6};
int in[6] = {4,2,5,1,6,3};

node* create(int preL, int preR, int inL, int inR)
{
    if(preL>preR)   // 先序序列长度为零的时候结束
    {
        return NULL;
    }

    node * root=new node;
    root->data=pre[preL];       //先序遍历的第一个数为根节点

    int k;
    for(k=inL; k<=inR; k++)
    {
        if(in[k]==pre[preL])
            break;
    }
    int numLeft=k-inL;

    root->left = create(preL+1, preL+numLeft, inL, k-1);
    root->right = create(preL+numLeft+1, preR, k+1,inR);

    return root;
}

void preorder(node * root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node * root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node * root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void layerorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node * now=q.front();
        q.pop();
        printf("%d ",now->data);
        if(now->left!=NULL)
        {
            q.push(now->left);
        }
        if(now->right!=NULL)
        {
            q.push(now->right);
        }
    }
}

int main()
{
    node * root=create(0,5,0,5);
    printf("先序遍历序列：");
    preorder(root);
    printf("\n");

    printf("中序遍历序列：");
    inorder(root);
    printf("\n");

    printf("后序遍历序列：");
    postorder(root);
    printf("\n");

    printf("层序遍历序列：");
    layerorder(root);
    printf("\n");

    return 0;
}