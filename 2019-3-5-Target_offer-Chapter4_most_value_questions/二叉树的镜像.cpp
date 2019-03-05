#include <cstdio>
#include "../2019-2-12-Algorithm_Note/根据先序和中序序列求树.cpp"
typedef struct node* BST;

void mirror(BST root)
{
    //递归边界
    if(root == NULL)
        return;
    
    //交换root的左右子节点
    BST temp=root->right;
    root->right=root->left;
    root->left=temp;

    //递归求子树镜像
    if(root->left)
        mirror(root->left);
    if(root->right)
        mirror(root->right);
}

int main()
{
    node * root=create(0,5,0,5);
    printf("层序遍历序列：");
    layerorder(root);
    printf("\n");

    mirror(root);
    printf("镜像后的层序遍历序列：");
    layerorder(root);
    printf("\n");
    return 0;
}