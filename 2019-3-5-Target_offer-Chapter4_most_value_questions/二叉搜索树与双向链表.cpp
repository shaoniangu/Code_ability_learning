#include <cstdio>
#include "../2019-2-12-Algorithm_Note/���������������������.cpp"

typedef struct node * tree;

//�������ת������������Ϊ˫������
void ConvertNode(tree root, tree* lastnode)
{
    if(root==NULL)
        return;

    tree cur=root;
    if(cur->left!=NULL)
    {
        ConvertNode(cur->left, lastnode);
    }
    cur->left=*lastnode;
    if(*lastnode!=NULL)
    {
        (*lastnode)->right=cur;
    }
    *lastnode=cur;

    if(cur->right!=NULL)
    {
        ConvertNode(cur->right, lastnode);
    }
}

tree convert(tree root)
{
    tree lastnode=NULL;
    ConvertNode(root, &lastnode);
    lastnode->right=NULL;
    tree head=lastnode;
    while(head!=NULL && head->left!=NULL)
    {
        head=head->left;
    }
    return head;
}

int main()
{
    node * root=create(0,5,0,5);
    printf("����������У�");
    layerorder(root);
    printf("\n");

    tree biList=convert(root);
    printf("%d\n", biList->data);
    tree p=biList;
    while(p!=NULL)
    {
        printf("%d\t", p->data);
        p=p->right;
    }
    printf("\n");
    return 0;
}