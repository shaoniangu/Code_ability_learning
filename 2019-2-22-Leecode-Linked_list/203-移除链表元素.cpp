/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL) return head;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    struct ListNode *p=nodehead->next, *pre=nodehead, *temp;
    while(p!=NULL)
    {
        if(p->val==val)
        {
            temp=p->next;
            pre->next=p->next;
            p->next=NULL;
            free(p);
            p=temp;
        }
        else
        {
            pre=pre->next;
            p=p->next;
        }
    }
    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}