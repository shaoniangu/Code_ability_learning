/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *gap, *beforegap, *p, *q;
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    p=nodehead;
    while(p !=NULL && p->next!=NULL)
    {
        if(p->next->val >= x)
            break;
        else
        {
            p=p->next;
        }
    }
    if(p->next==NULL)
    {
        return head;
    }
    gap=p->next;    //�ҵ��ָ��
    beforegap=p;    //�ҵ��ָ��ǰһ����
    p=gap;          //pָ��ָ��
    q=gap->next;    //qָ��ָ���һ����
    while(q!=NULL)
    {
        if(q->val<x) //ע��ָ��仯
        {
            p->next=q->next;
            q->next=beforegap->next;
            beforegap->next=q;
            beforegap=q;
            q=p->next;
        }
        else
        {
            p=p->next;
            q=p->next;
        }
    }
    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}