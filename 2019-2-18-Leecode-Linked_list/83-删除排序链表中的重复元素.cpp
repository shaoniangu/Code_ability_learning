/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head; 
    struct ListNode *lastrear, *p, *q, *temp;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    lastrear=nodehead;
    p=lastrear->next;
    q=p->next;
    while(q!=NULL)
    {
        if(q->val == p->val)
        {
            p->next=q->next;    //�����ظ�ɾ���ڶ�����������һ����p������q����flag��Ϊtrue
            q->next=NULL;
            free(q);
            q=p->next;
        }
        else
        {
            
            lastrear=p;
            p=p->next;
            q=p->next;
        }
    }
    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}