/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head==NULL) return NULL; //���������⴦��
    struct ListNode* rear=head, *p=head, *temp;
    int num=0;

    while(rear!=NULL && num<n)  //�ڶ���ָ��ָ���n�����
    {
        num++;
        rear=rear->next;
    }
    
    if(num<n)     //ѹ��û��n�����,����ɾ����ֱ�ӷ���ԭ����
    {
        return head;
    }
    
    if(rear != NULL) //
    {
        rear=rear->next;
        while(rear!=NULL)
        {
            rear=rear->next; //���rear��NULL,p�ļ�ָ������n+1����,֮����ָ������n+1��������Ϊ�˷���ɾ��������n����
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else                //ע�⣺���n���������ȣ�ɾ�����ǵ�һ���ڵ�Ҫ���⴦��
    {
        temp=p;
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    
    return head;
}