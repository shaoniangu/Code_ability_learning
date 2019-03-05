#include <cstdio>
#include "../2019-2-12-Algorithm_Note/���������������������.cpp"
typedef struct node* BST;

void mirror(BST root)
{
    //�ݹ�߽�
    if(root == NULL)
        return;
    
    //����root�������ӽڵ�
    BST temp=root->right;
    root->right=root->left;
    root->left=temp;

    //�ݹ�����������
    if(root->left)
        mirror(root->left);
    if(root->right)
        mirror(root->right);
}

int main()
{
    node * root=create(0,5,0,5);
    printf("����������У�");
    layerorder(root);
    printf("\n");

    mirror(root);
    printf("�����Ĳ���������У�");
    layerorder(root);
    printf("\n");
    return 0;
}