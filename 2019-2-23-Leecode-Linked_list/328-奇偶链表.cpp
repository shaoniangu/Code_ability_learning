/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next==NULL || head->next->next==NULL) return head;

    struct ListNode *oddhead=head, *oddrear=head,*evenhead=head->next,*evenrear=head->next, *p=head->next->next,*temp;
    int count=2;
    oddrear->next=NULL;
    evenrear->next=NULL;
    while(p)
    {
        count++;
        if(count%2==1)
        {
            temp=p->next;
            oddrear->next=p;
            p->next=NULL;
            oddrear=p;
            p=temp;
        }
        else
        {
            temp=p->next;
            evenrear->next=p;
            p->next=NULL;
            evenrear=p;
            p=temp;
        }
    }
    oddrear->next=evenhead;
    return oddhead;
}