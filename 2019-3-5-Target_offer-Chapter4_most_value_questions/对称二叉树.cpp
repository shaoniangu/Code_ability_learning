#include <cstdio>
#include "../2019-2-12-Algorithm_Note/���������������������.cpp"

typedef struct node * tree;

bool isSymmetrical(tree root1,tree root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    
    return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}

int main()
{
    node * root=create(0,5,0,5);
    printf("����������У�");
    layerorder(root);
    printf("\n");

    bool res = isSymmetrical(root, root);
    printf("%d", res);
    return 0;
}