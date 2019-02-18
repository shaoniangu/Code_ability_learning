/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findNthFromEnd(struct ListNode* head, int n) {
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
        return p;
    }
    
    rear=rear->next;    //����n+1�����
    while(rear!=NULL)
    {
        rear=rear->next; //���rear��NULL,p�ļ�ָ������n+1����,֮����ָ������n+1��������Ϊ�˷���ɾ��������n����
        p=p->next;
    }
    
    return p;

}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k==0) return head;
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    struct ListNode *p=head, *q=p->next, *newhead;
    int num=1;
    while(q->next!=NULL)    //qָ�����һ�����
    {
        num++;
        q=q->next;
    }
    num++;
    k=k%num;
    if(k==0)    return head;
    p=findNthFromEnd(head,k);    //pָ������n+1�����
    newhead=p->next;
    p->next=NULL;
    q->next=head;
    head=q;
    k--;
    return newhead;
}