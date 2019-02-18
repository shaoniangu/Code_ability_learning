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
            p->next=q->next;    //发现重复删除第二个，保留第一个，p不动，q动，flag置为true
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