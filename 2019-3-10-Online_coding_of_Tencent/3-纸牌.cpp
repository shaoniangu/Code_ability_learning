#include <stdio.h>
#include <malloc.h>


struct node
{
    int val;
    struct node* next;
};

int main()
{
    int n, ans;
    struct node* head, *rear, *temp;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->val=i;
        temp->next=NULL;
        if(i==1)
        {
            head=temp;
            rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }

    while(head->next!=NULL)
    {
        temp=head;
        head=head->next; //�������ӵ�
        printf("%d", temp->val);   //��ӡ���
        temp->next=NULL;
        free(temp); //�ͷŶ��˽ڵ�

        temp=head;      //��ǰ�ڵ�ŵ�����ĩβ
        if(head->next!=NULL)
        {
            head=head->next;
            rear->next=temp;
            temp->next=NULL;
            rear = temp;
        }
        printf(" ");
    }
    printf("%d", head->val);
    return 0;
}